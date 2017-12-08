#include "update.h"

/*pup::update::update(QString server_url):QObject(0){
    this->server_url = server_url;
    connect(&latest_version_req, SIGNAL(finished(QNetworkReply*)), this, SLOT(latest_version_received(QNetworkReply*)));
    connect(&mWebCtl, SIGNAL(finished(QNetworkReply*)), this, SLOT(update_downloaded(QNetworkReply*)));
    QNetworkRequest request(QUrl(server_url));
}

 bool pup::update::check_for_update(double version)
 {
     QNetworkRequest request(server_url);
     mWebCtl.get(request);
     return 0;
 }

 void pup::update::latest_version_received(QNetworkReply* pReply)
 {
     qDebug() << "AAAA" << pReply->readAll();
 }*/
