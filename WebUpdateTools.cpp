#include "WebUpdateTools.h"

QString WebUpdate::GetCurrentProductVersion(QString versioningFile) const
{
    QFile latestVersionFile(versioningFile);
    if(latestVersionFile.open(QIODevice::ReadOnly)) {
        return latestVersionFile.readAll();
    }
    return "8";
}

WebUpdate::WebUpdate()
{
    m_localDataFolderPath = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/FsecPatch";
    if (! QDir().exists(m_localDataFolderPath)) {
        QDir().mkpath(m_localDataFolderPath);
    } else {
        if(QFile(m_localDataFolderPath + "/FsecPatch.exe").exists()) {
            ProceedRequestAfterRestart(QDir::currentPath() + "/FsecPatch.exe", m_localDataFolderPath + "/FsecPatch.exe");
        }
    }
}

QString WebUpdate::GetLatestProductVersion(const QString& serverUrl)
{
    QString currentProductVersion = GetCurrentProductVersion(m_localDataFolderPath + "/LATEST");
    QDir().mkpath(m_localDataFolderPath + "/UPD_TMP");
    PerformRequest(serverUrl, m_localDataFolderPath + "/UPD_TMP/LATEST");
    QString newProductVersion = GetCurrentProductVersion(m_localDataFolderPath + "/UPD_TMP/LATEST");
    if(currentProductVersion.toInt() < newProductVersion.toInt()) {
        QMessageBox messageUpdateNeeded;
        messageUpdateNeeded.setText("New update available, do you want to download it?");
        messageUpdateNeeded.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        messageUpdateNeeded.setDefaultButton(QMessageBox::Yes);

        if(messageUpdateNeeded.exec() == QMessageBox::Yes) {
            QFile(m_localDataFolderPath + "/UPD_TMP/LATEST").copy(m_localDataFolderPath + "/LATEST");
            PerformFilesUpdate(m_localDataFolderPath + "/FsecPatch.exe");
            messageUpdateNeeded.setText("Update done, it will be applied at next program start");
            messageUpdateNeeded.setStandardButtons(QMessageBox::Ok);
            messageUpdateNeeded.exec();
        } else {
            QFile(m_localDataFolderPath + "/UPD_TMP/LATEST").remove();
            return QString("NEW UPDATE IS AVAILABLE! Current version is %1, new update is available to version %2").arg(currentProductVersion).arg(newProductVersion);
        }
    }
    return QString("Current version: " + currentProductVersion);
}

void ServerHttpConnection::WriterCurlCallback(const char *inData, const size_t length, const size_t nn, void* currentFileNameProcessing)
{
    QFile outFile(*(static_cast<QString*>(currentFileNameProcessing)));
    if (outFile.open(QIODevice::ReadWrite)) {
        outFile.write(inData, length * nn);
        outFile.close();
    }
}

bool ServerHttpConnection::InitializeConnection()
{
    m_curlEntity = curl_easy_init();
    if (m_curlEntity != nullptr) {
        return true;
    }
    return false;
}

void ServerHttpConnection::PerformRequest(const QString &url, QString currentFileNameProcessing)
{
    if (m_curlEntity != nullptr) {
        curl_easy_setopt(m_curlEntity, CURLOPT_URL, url.toStdString().c_str());
        curl_easy_setopt(m_curlEntity, CURLOPT_WRITEFUNCTION, ServerHttpConnection::WriterCurlCallback);
        curl_easy_setopt(m_curlEntity, CURLOPT_WRITEDATA, (void*)&currentFileNameProcessing);
        curl_easy_perform(m_curlEntity);
    }
}

ServerHttpConnection::~ServerHttpConnection()
{
    if (m_curlEntity != nullptr) {
        curl_easy_cleanup(m_curlEntity);
    }
}

void WebUpdate::PerformFilesUpdate(const QString &filePath)
{
    QString fileUrl = "http://fsec.ltd.ua/UPD" + QFileInfo(filePath).fileName();
    PerformRequest(fileUrl, filePath);
}

void WebUpdate::ProceedRequestAfterRestart(const QString& filePathToUpdate, const QString& filePathUpdateFrom)
{
    if (QFileInfo(filePathUpdateFrom).size() > 0) {
        QFile::remove(filePathToUpdate);
        if (QFile::copy(filePathUpdateFrom, filePathToUpdate)) {
            QFile(filePathUpdateFrom).remove();
        }
    }
}

void WebUpdate::SetInitialProductVersion()
{

}
