#ifndef MENU_H
#define MENU_H
#include <QPoint>
#include <QString>
#include <QVector>
#include <QList>
#include <QMap>
#include <QImage>
#include <QDebug>

class menu
{
   QMap<QString, QPoint> text;
   QImage img;
public:
    menu();
    void loadMenuUI(QString value, QPoint point);
    void drawMenu();
    void closeMenu();
    QString isTextPoint(QPoint point);
signals:

public slots:
};

#endif // MENU_H
