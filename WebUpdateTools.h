#ifndef WEBUPDATE_H
#define WEBUPDATE_H

#include <QDebug>

#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDir>
#include <QMessageBox>

#include <curl/curl.h>

class ServerHttpConnection {
    CURL* m_curlEntity;
    static void WriterCurlCallback(const char *inData, const size_t length, const size_t nn, void* currentFileNameProcessing);
public:
    bool InitializeConnection();
    void PerformRequest(const QString &url, QString currentFileNameProcessing);
    ~ServerHttpConnection();
};

class WebUpdate : public ServerHttpConnection
{
    QString m_localDataFolderPath;
    QString GetCurrentProductVersion(QString versioningFile) const;
public:
    WebUpdate();
    QString GetLatestProductVersion(const QString& serverUrl = "http://fsec.ltd.ua/UPD/LATEST");
    void PerformFilesUpdate(const QString& filePath);
    void ProceedRequestAfterRestart(const QString& filePathToUpdate, const QString& filePathUpdateFrom);
    void SetInitialProductVersion();
};

#endif // WEBUPDATE_H
