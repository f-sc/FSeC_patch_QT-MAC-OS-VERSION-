#include "menu.h"

menu::menu()
{

}

void menu::loadMenuUI(QString value, QPoint point)
{
    text.insert(value, point);
}

QString menu::isTextPoint(QPoint point)
{
    for(auto temp: text)
    {
    if(temp == point)
    {
      return text.key(point);
    }
    }
}

