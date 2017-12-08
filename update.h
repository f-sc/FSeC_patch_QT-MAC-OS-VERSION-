#ifndef UPDATE_H
#define UPDATE_H
#include <QObject>
#include <QByteArray>
#include <QVector>

#define current_version 0.7
/*namespace pup
{


class update:public QObject
{
    Q_OBJECT
  QVector<table_upd_item> data;
  QString server_url;
   QNetworkAccessManager latest_version_req;
  QNetworkAccessManager mWebCtl;
public:
  update(QString server_url);
    bool check_for_update(double version);
    void download_update();
    void setup_update();
public slots:
    void latest_version_received(QNetworkReply* pReply);
    void update_downloaded(QNetworkReply* pReply){};
    void parse_update_data(QByteArray patch_data){};
    void update_installed(){};
signals:
    void downloaded();
    void updated();
};
}*/
/*
struct table_upd_item
{
    QPoint offset;
    QByteArray data;
};

class updator
{
    QVector<table_upd_item> data;
public:
    void connect_upd_server();
    void get_last_version();
    void setup_upd();
};*/

#endif // UPDATE_H
