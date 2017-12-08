#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "update.h"

QString toHexS(int value)
{
    QString temp;
    temp.setNum(value, 16);
    return temp;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    manager = new patch();
   // manager->setUI(ui);
    //new QShortcut(QKeySequence(Qt::CTRL), this, SLOT(ccz()));
    undo_redo_shortcut = new QShortcut(QKeySequence("Ctrl+Z"), this, SLOT(makeBackup()), SLOT(makeBackup()), Qt::WindowShortcut);
    ui->search->setHidden(true);
    ui->convert->setHidden(true);
    ui->data_table->verticalHeader()->setVisible(true);
    //ui->centralWidget->is
    isSearched = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
}

void MainWindow::on_data_table_cellChanged(int row, int column)
{
    if(manager->data_loaded && !backup_mode)
    {
    // qDebug() << "on_data_table_cellChanged" << column << " : " << row << "::" <<  ui->data_table->item(row, column)->data(0).toByteArray();
      //  qDebug() << ui->data_table->cellWidget(column, row)
     //ui->data_table->ite
    manager->change_item(ui->data_table->item(row, column)->data(0).toByteArray(), QPoint(column, row));
    ui->last_actions->addItem(ui->data_table->item(row, column)->data(0).toString() + " - 0x" + toHexS(row) + ":" + toHexS(column));

    //qDebug() << ui->data_table->item(row, column)->data(0).toByteArray();
    }
}

void MainWindow::on_data_table_activated(const QModelIndex &index)
{

}

void MainWindow::on_data_table_doubleClicked(const QModelIndex &index)
{
    manager->data_loaded = true;
}

void MainWindow::on_toolButton_3_clicked()
{
    makeBackup();
}

void MainWindow::makeBackup()
{
    item temp = manager->cz(true);
    //manager->backup.clear();
    backup_mode = true;
    if(temp.item_t.length()>0 && !temp.error)
    {
       ui->data_table->setItem(temp.offset.y(), temp.offset.x(), new QTableWidgetItem(temp.item_t, 1));
     //  qDebug() << "on_data_table_cellChanged" << temp.offset.x() << " : " << temp.offset.y();
    }
    backup_mode = false;
}

void MainWindow::ccz()
{
    manager->cz(true);
   // qDebug() << "CCZ";
}

void MainWindow::load_file(QString filename)
{
    manager->data_loaded = false;
    ui->data_table->clear();
    manager->load_file(filename);
   // qDebug() << filename;
    QList<item> temp = manager->all_items();
    ui->data_table->setColumnCount(16);
    ui->data_table->setRowCount(temp.length()/16);
    for(int i=0; i< ui->data_table->rowCount(); i++)
    {
      QString temp;
      temp = "0x"+toHexS(i);
      ui->data_table->setVerticalHeaderItem(i, new QTableWidgetItem(temp));
      //ui->data_table->horizontalHeaderItem(0)->setText("temp");
    }
    for(int i=0; i< ui->data_table->columnCount(); i++)
    {
      QString temp;
      temp = "0x"+toHexS(i);
      ui->data_table->setHorizontalHeaderItem(i, new QTableWidgetItem(temp));
      //ui->data_table->horizontalHeaderItem(0)->setText("temp");
    }
    for(int i=0; i<16; i++)
    {
     ui->data_table->setColumnWidth(i, 45);
    }
   // qDebug() << temp.length();
    int temp_counter = 0;
    ui->progress_saveload->setValue(0);
    for(auto t: temp)
    {
        temp_counter++;
        //qDebug() << t.offset.y();
        ui->progress_saveload->setValue(temp_counter/100);
        ui->data_table->setItem(t.offset.y(), t.offset.x(), new QTableWidgetItem(QString::fromUtf8(t.item_t)));
       // qDebug() << "load_file " << t.offset.x() << " : " << t.offset.y();
    }
}

void MainWindow::on_toolButton_clicked()
{
    //"/Users/2ima/build-leran-Desktop_Qt_5_5_0_clang_64bit-Debug/1.exe")
    ui->fil_name_label->setText(QFileDialog::getOpenFileName(this, "Open File"));
    load_file(ui->fil_name_label->text());
}

void MainWindow::on_toolButton_2_clicked()
{
    manager->save_file();
}

void MainWindow::on_toolButton_5_clicked()
{
    ui->convert->setVisible(false);
    switch(ui->search->isHidden())
    {
    case true:
      ui->search->setHidden(false);
      break;
    case false:
      ui->search->setHidden(true);
      break;
    }
}

void MainWindow::on_toolButton_5_triggered(QAction *arg1)
{
}



void MainWindow::on_toolButton_5_toggled(bool checked)
{
}

void MainWindow::on_text_to_search_linkActivated(const QString &link)
{

}

void MainWindow::on_toolButton_6_clicked()
{
    ui->search->setVisible(false);
    switch(ui->convert->isHidden())
    {
    case true:
      ui->convert->setHidden(false);
      break;
    case false:
      ui->convert->setHidden(true);
      break;
    }
}

void MainWindow::on_go_search_clicked()
{
    if(isSearched == false)
    {
     manager->search_upd();
     values.clear();
     manager->search(ui->data_v->text().toUtf8());
     values = manager->search_result();
     isSearched = true;
    }
   if(values.length()>0)
   {
   QPoint temp = values.first();

   ui->data_table->setCurrentCell(temp.y(), temp.x());
   qDebug() << "Cell: " << temp.x() << " : " << temp.y();
   values.removeFirst();
   }
   else
   {
       manager->search_upd();
       values.clear();
       isSearched = false;
   }
}

void MainWindow::on_data_v_cursorPositionChanged(int arg1, int arg2)
{

}

void MainWindow::load_string_view(QString data)
{

}

void MainWindow::on_data_t_activated(const QString &arg1)
{
    ui->to_convert->setText(ui->data_table->currentItem()->data(0).toString());
   if(arg1 == "Hex")
   {
     ui->converted->setText(manager->convert(ui->data_table->currentItem()->data(0).toString().toUtf8(), data_type::hex16));
   }
   else if(arg1 == "Char")
   {
     ui->converted->setText(manager->convert(ui->data_table->currentItem()->data(0).toByteArray(), data_type::strS));
   }
}

void MainWindow::on_data_v_textChanged(const QString &arg1)
{
    isSearched = false;
    values.clear();
}

void MainWindow::on_widget_destroyed()
{

}

void MainWindow::mousePressEvent(QMouseEvent* pe)
{
    if(pe->button() == Qt::LeftButton)
    {
        this->m_ptDragPos = pe->pos();
       // qDebug() << "LB pressed";
    }
    QWidget::mousePressEvent(pe);
}

void MainWindow::mouseMoveEvent(QMouseEvent* pe)
{
    if(pe->button() & Qt::LeftButton)
    {
       // qDebug() << "LB move";
        int distance = (pe->pos() - m_ptDragPos).manhattanLength();
        if(distance > QApplication::startDragDistance())
        {
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(pe);
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasText())
    {
        event->acceptProposedAction();
       // qDebug() << "Dropped";
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QString name = event->mimeData()->text();
    name.remove(0, 7);
  //  name.chop(1);
    ui->fil_name_label->setText(name);
    load_file(name);
}

void MainWindow::on_toolButton_7_clicked()
{
    QPoint offset = manager->goToOffset(ui->offset_text->text());
    ui->data_table->setCurrentCell(offset.x(), offset.y());
   /* QString temp;
    for(int i=0; i<200; i+=16)
    {

     qDebug() << temp;
    }*/
}

void MainWindow::on_MainWindow_sonClick()
{

}

void MainWindow::on_data_table_cellDoubleClicked(int row, int column)
{

}

void MainWindow::on_check_upd_clicked()
{
    //pup::update* get_new_upds = new pup::update("http://www.cyberforum.ru/order-program/");
   // get_new_upds->check_for_update(0.2);
}
