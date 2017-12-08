#ifndef PATCH_H
#define PATCH_H
#include <QTableWidgetItem>
#include <QList>
#include <QPoint>
#include <QFile>
#include <QString>
#include <QCharRef>
#include <QDebug>
#include <QMessageBox>
#include <QByteArray>
#include <QMainWindow>

enum data_type{hex16, dec10, strS};

struct item
{
    QByteArray item_t;
    QPoint offset;
    bool error;
};

class patch: public QObject
{
    Q_OBJECT
    QList<item> data;
    QList<item> search_exclude;
    QList<QPoint> tempS_list;
    QPoint current_add;
    QString filename;
    QMainWindow *ui;
public:
    QList<item> backup;
    patch(){current_add.setX(0); current_add.setY(0); data_loaded = false;}
    void setUI(QMainWindow *window);
    void load_file(QString filename);
    void save_file();
    void add_item(QByteArray value);
    void change_item(QByteArray value, QPoint offset);
    void draw();
    void clear();
    item cz(bool ctrlz);
    //QPoint search(QByteArray data);
    void search(QByteArray data);
    QPoint goToOffset(QString offset);
    QList<QPoint> search_result();
    void search_upd();
    QByteArray convert(QByteArray data, data_type type);
    QList<item> all_items();
    bool data_loaded;
signals:

public slots:
};




#endif // PATCH_H
