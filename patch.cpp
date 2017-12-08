#include "patch.h"



void patch::load_file(QString filename)
{
    QFile file(filename);
    QMessageBox msg;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->data.clear();
        this->search_exclude.clear();
        this->current_add = QPoint(0,0);
        this->filename = file.fileName();
        while(!file.atEnd())
        {
            QByteArray val = file.read(1);
            add_item(val.toHex());

            //qDebug() << val.toHex();
        }
        file.close();
        qDebug() << "File opened";
        msg.setText("File opened");
    }
    else
    {
        msg.setText("<font color='white'>Error while opening file "+ file.fileName() +"</font>");
    }
   // msg.exec();
}

void patch::add_item(QByteArray value)
{
    item temp;
    temp.item_t = value;
    if(current_add.x() < 15)
    {
        if(data.length()<1)
        {
          current_add.setX(0);
        }
        else
        {
        current_add.setX(current_add.x()+1);
        }
    }
    else
    {
        current_add.setX(0);
        current_add.setY(current_add.y()+1);
    }
    temp.offset.setX(current_add.x());
    temp.offset.setY(current_add.y());
    //
   // qDebug() << "add_item" << temp.offset.x() << " : " << temp.offset.y() << temp.item_t;
    data.push_back(temp);
}

QList<item> patch::all_items()
{
    return data;
}

void patch::draw()
{
   // window->data_table
}

void patch::save_file()
{
    int ts =0;
    QFile file(this->filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        file.seek(0);
        QDataStream out(&file);
     for(int i=0; i<data.length(); i++)
     {
        // qDebug() << temp.item_t;
         if(ts!=16)
         {
        // file.write(data[i].item_t);
            QByteArray temps = (convert((data[i].item_t).toStdString().c_str(), data_type::strS).simplified());
           // qDebug() << temps << "::" << data[i].offset.x() << "::y::" << data[i].offset.y();
            file.write(temps);
            ts++;
           // out << temps;
           // qDebug(temps.length());
         }
         else
         {
             file.write("\n");
             ts = 0;
         }
     }
     qDebug() << "Saved";
    }
    else
    {
        qDebug() << "\nError while opening output file\n";
    }
}

void patch::change_item(QByteArray value, QPoint offset)
{
   // qDebug() << "Offset:" << offset.x() << " " << offset.y();
   // qDebug() << "Request :" << value << " at offset: " << offset.x() << " : " << offset.y();
    for(int i=0; i<this->data.length(); i++)
    {
       // qDebug() << "Request :" << this->data.at(i).item_t << " at offset: " << this->data.at(i).offset.x() << " : " << this->data.at(i).offset.y() << ":" << value;
        if(this->data.at(i).offset == offset)
        {
            if(backup.length()>5)
            {
                this->backup.clear();
            }
               this->backup.push_back(this->data[i]);
               //qDebug() << "Data val:" << this->data.at(i).item_t<< "\n";


            this->data[i].item_t = value;

           // qDebug() << "Changed A:" << value << " at offset: " << offset.x() << " : " << offset.y();
        }
    }
}

item patch::cz(bool ctrlz)
{
    if(!data.empty() && !backup.empty())
    {
        for(auto temp: data)
        {
            if(temp.offset == backup.last().offset)
            {
                temp = backup.last();
               // qDebug() << "Backup size: " << backup.size();
                temp.error = false;
                backup.removeLast();
                return temp;
               // break;
            }
           // return NULL;
        }
    }
    else
    {
        qDebug() << "Error";
        item error_item;
        error_item.error = true;
        return error_item;
    }
    /*if(ctrlz && !data.empty() && !backup.empty())
    {
        item tmp;
        qDebug() << "YES";
        for(int i=0; i<this->data.size(); i++)
        {
            if(!backup.empty())
            {
            if(this->data.at(i).offset == backup.last().offset)
            {
                this->data[i].item_t = backup.last().item_t;
                qDebug() << "Backup: " << backup.length();
                backup.removeLast();
                qDebug() << "ctrlz: " << this->data[i].item_t;
                tmp = this->data[i];
                return tmp;
            }
            {
                qDebug() << "Backup's empty";
            }
            }
        }
       return tmp;
    }
    else
    {
    }*/
}

/*QPoint patch::search(QByteArray data)
{
    qDebug() << data << " ";
    for(auto temp: this->data)
    {
        qDebug() << data << " " << temp.item_t;
        if(temp.item_t.toHex() == data)
        {
            return temp.offset;
        }
    }
    return QPoint(-1, -1);
}*/

void patch::search(QByteArray data)
{
    for(auto temp: this->data)
    {
        //qDebug() << data << " " << temp.item_t;
        if(temp.item_t == data)
        {
            tempS_list.push_back(temp.offset);
        }
    }
    //return Q;
}

QList<QPoint> patch::search_result()
{
    return tempS_list;
}

void patch::search_upd()
{
    tempS_list.clear();
}

QByteArray patch::convert(QByteArray data, data_type type)
{
    switch(type)
    {
      /*case data_type::dec10:
        return
        break;*/
      case data_type::hex16:
        return data.toHex();
        break;
      case data_type::strS:
        return QByteArray::fromHex(data);
        break;
    }
}

void patch::setUI(QMainWindow *window)
{
    ui = window;
}

QPoint patch::goToOffset(QString offset)
{
    /*QByteArray::fromHex(QByteArray::fromStdString(new char((char)(QString::number((static_cast<int>(offset.at(offset.length()-1).toLatin1())), 16).toInt())
                                                                           )));*/
    //QByteArray temp_x=offset.number().toLocal8Bit();
    QString temp = QString::number((static_cast<int>(offset.at(offset.length()-1).toLatin1())), 16);
    qDebug() << "gotoof:" << temp;
    if(temp.at(0).toLatin1() == '3')
    {
         //qDebug() << "temp: " << temp;
        //temp[0] = temp[1];
        temp = temp.remove(0, 1);
        qDebug() << "temp: " << temp;
    }
    else
    {
        temp[0] = '1';
        temp = QString::number(temp.toInt()-1);
    }
    QString temp_y = offset;
    temp_y.chop(1);
    temp_y = temp_y.remove(0, 2);
    temp_y.setNum(temp_y.toInt(0, 16), 10);
    //qDebug() << temp_y.toInt();
    //qDebug() <<  (QString::number((static_cast<int>(offset.at(offset.length()-1).toLatin1())), 16).at(1).toLatin1());
    //temp_x = QByteArray::fromHex(temp_x);
  //  qDebug() << temp_x;
    //int tempi = -48;
    //temp_x.setNum(tempi, 10);
   // qDebug() << QString::fromStdString(temp_x.toStdString()).toInt();
    qDebug() << temp.toInt(0, 10) << ": " <<  temp_y.toInt(0, 10);
    return QPoint(temp_y.toInt(0, 10), temp.toInt());

}
