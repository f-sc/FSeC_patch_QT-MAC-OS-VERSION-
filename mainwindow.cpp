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
    //undo_redo_shortcut = new QShortcut(QKeySequence("Ctrl+Z"), this, SLOT(makeBackup()), SLOT(makeBackup()), Qt::WindowShortcut);
    //ui->tbSearch->setHidden(true);
    ui->tbConvert->setHidden(true);
    // ui->data_table->verticalHeader()->setVisible(true);
    isSearched = false;

    m_hexDataViewModel = new HexTableModel;
    connect(m_hexDataViewModel, SIGNAL(reactHistoryUpdate(QModelIndex)), SLOT(UpdateEditHistory(QModelIndex)));
    ui->viewDataTable->setModel(m_hexDataViewModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_file(QString filename)
{
    QFile file(filename);
    QMessageBox msg;
    if(file.open(QIODevice::ReadOnly))
    {
        m_hexDataViewModel->Clear();
        m_hexDataViewModel->setApproxLinesCount((file.size() / 16) + 1);
        int col = 0;
        int row = 0;
        while(!file.atEnd())
        {
            m_hexDataViewModel->setData(m_hexDataViewModel->index(row, col), file.read(1).toHex(), Qt::DisplayRole);
            if(col < 15) {
                col++;
            } else {
                col = 0;
                row++;
            }
        }
        file.close();
        m_hexDataViewModel->Reflesh();
        qDebug() << "File opened";
        msg.setText("File opened");
    }
    else
    {
        msg.setText("<font color='white'>Error while opening file "+ file.fileName() +"</font>");
    }
    /* manager->data_loaded = false;
    ui->data_table->clear();
    manager->load_file(filename);
    QList<item> tempDataItems = manager->all_items();
    ui->data_table->setColumnCount(16);
    ui->data_table->setRowCount(tempDataItems.length()/16);
    for(int i = 0; i < ui->data_table->rowCount(); i++)
    {
        ui->data_table->setVerticalHeaderItem(i, new QTableWidgetItem("0x"+toHexS(i)));
    }
    for(int i = 0; i < ui->data_table->columnCount(); i++)
    {
        ui->data_table->setHorizontalHeaderItem(i, new QTableWidgetItem("0x"+toHexS(i)));
    }
    for(int i = 0; i < 16; i++)
    {
        ui->data_table->setColumnWidth(i, 45);
    }
    // qDebug() << temp.length();
    int temp_counter = 0;
    ui->progress_saveload->setValue(0);
    for(auto t: tempDataItems)
    {
        temp_counter++;
        ui->progress_saveload->setValue(temp_counter/100);
        ui->data_table->setItem(t.offset.y(), t.offset.x(), new QTableWidgetItem(QString::fromUtf8(t.item_t)));
    }*/
}

/*void MainWindow::on_toolButton_5_clicked()
{
    ui->tbConvert->setVisible(false);
    switch(ui->tbSearch->isHidden())
    {
    case true:
        ui->tbSearch->setHidden(false);
        break;
    case false:
        ui->tbSearch->setHidden(true);
        break;
    }
}*/

/*void MainWindow::on_toolButton_6_clicked()
{
    ui->tbSearch->setVisible(false);
    if(ui->tbConvert->isHidden()) {
        ui->tbConvert->setHidden(false);
    } else {
        ui->tbConvert->setHidden(true);
    }
}*/

void MainWindow::on_go_search_clicked()
{
    if(isSearched == false)
    {
        /*  manager->search();
     values.clear();
     manager->search(ui->data_v->text().toUtf8());
     values = manager->sea();*/
        isSearched = true;
    }
    if(values.length()>0)
    {
        QPoint temp = values.first();

        // ui->data_table->setCurrentCell(temp.y(), temp.x());
        qDebug() << "Cell: " << temp.x() << " : " << temp.y();
        values.removeFirst();
    }
    else
    {
        //manager->tbSearch_upd();
        values.clear();
        isSearched = false;
    }
}

void MainWindow::on_data_t_activated(const QString &arg1)
{
    //ui->tbConvert->setText(ui->data_table->currentItem()->data(0).toString());
    if(arg1 == "Hex")
    {
        // ui->tbConvert->setText(manager->tbConvert(ui->data_table->currentItem()->data(0).toString().toUtf8(), data_type::hex16));
    }
    else if(arg1 == "Char")
    {
        // ui->tbConvert->setText(manager->tbConvert(ui->data_table->currentItem()->data(0).toByteArray(), data_type::strS));
    }
}

void MainWindow::mousePressEvent(QMouseEvent* pe)
{
    if(pe->button() == Qt::LeftButton)
    {
        this->m_ptDragPos = pe->pos();
    }
    QWidget::mousePressEvent(pe);
}

void MainWindow::mouseMoveEvent(QMouseEvent* pe)
{
    if(pe->button() & Qt::LeftButton)
    {
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
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QString name = event->mimeData()->text();
    name.remove(0, 7);
    ui->fil_name_label->setText(name);
    load_file(name);
}

void MainWindow::on_tbOpenFile_clicked()
{
    ui->fil_name_label->setText(QFileDialog::getOpenFileName(this, "Open File"));
    load_file(ui->fil_name_label->text());
}

void MainWindow::on_tbSaveFile_clicked()
{
    QFile outFile(ui->fil_name_label->text());
    if(outFile.open(QIODevice::ReadWrite)) {
        for(int row = 0; row < m_hexDataViewModel->rowCount(); row++) {
            for(int col = 0; col < m_hexDataViewModel->columnCount(); col++) {
                if(m_hexDataViewModel->data(m_hexDataViewModel->index(row, col), Qt::AccessibleTextRole).toBool()) {
                    outFile.seek((row * 16) - col);
                    outFile.write(QByteArray::fromHex(m_hexDataViewModel->data(m_hexDataViewModel->index(row, col), Qt::DisplayRole).toByteArray()));
                    qDebug() << "We'll save: " << m_hexDataViewModel->data(m_hexDataViewModel->index(row, col), Qt::DisplayRole);
                }
            }
        }
    }

}

void MainWindow::UpdateEditHistory(const QModelIndex &index)
{
    QString value = m_hexDataViewModel->data(index, Qt::ToolTipRole).toString() + " -> " + m_hexDataViewModel->data(index).toString();
    QString offset = QString::number(index.row() + 1) + " : " + QString::number(index.column() + 1);
    ui->listLastEdit->addItem(offset + " | " + value);
}

void MainWindow::on_pbRevertSelected_clicked()
{
    for(QListWidgetItem* tempItem : ui->listLastEdit->selectedItems()) {
        if(tempItem->text().isEmpty()) {
            return;
        }
        QStringList currentSelectedItemValue = tempItem->text().split(" | ");
        QStringList coordinatesContents = currentSelectedItemValue.at(0).split(" : ");
        QModelIndex itemUsedIndex = m_hexDataViewModel->index(coordinatesContents.at(0).toInt() - 1, coordinatesContents.at(1).toInt() - 1);

        m_hexDataViewModel->setData(itemUsedIndex, currentSelectedItemValue.at(1).split(" ->").at(0), Qt::DisplayRole);
        ui->viewDataTable->viewport()->update();
        ui->listLastEdit->takeItem(ui->listLastEdit->row(tempItem));
    }
}


void MainWindow::on_tbGoToOffset_clicked()
{
    QString offsetValue = ui->editOffsetText->text();
    offsetValue = offsetValue.mid(2, offsetValue.length() - 2);
    bool convStatus = false;
    uint offset = offsetValue.toUInt(&convStatus, 16);
    double tempX = 0.0;
    //qDebug() << "Coll: " << offset << " : " << (std::modf(double((double)offset / 16.0), &tempX) * 16) << " : " << offset / 16;
    if(convStatus) {
        ui->viewDataTable->selectionModel()->clearSelection();
        ui->viewDataTable->selectionModel()->select(m_hexDataViewModel->index((offset / 16), (std::modf(double((double)offset / 16.0), &tempX) * 16)), QItemSelectionModel::Select);
    }
}

