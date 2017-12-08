#ifndef TABLES_H
#define TABLES_H
#include <QByteArray>
#include <QString>
#include <QPoint>
#include <QMap>

class tables
{
    QMap<QPoint, QByteArray> values;
public:
    tables();
    void ac_value(QPoint offset, QByteArray data);
};



#endif // TABLES_H
