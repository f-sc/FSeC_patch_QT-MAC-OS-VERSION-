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

void MainWindow::startDrag()
{
    QMimeData* pmimeData = new QMimeData;
    pmimeData->setText("inputData");

    QDrag* drag = new QDrag(this);
    drag->setMimeData(pmimeData);
    drag->exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    isSearched = false;

    m_hexDataViewModel = new HexTableModel;
    connect(m_hexDataViewModel, SIGNAL(reactHistoryUpdate(QModelIndex)), SLOT(UpdateEditHistory(QModelIndex)));
    ui->viewDataTable->setModel(m_hexDataViewModel);

    connect(ui->viewDataTable->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            SLOT(dataTableSelectionChanged(const QItemSelection &, const QItemSelection &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadFile(QString filename)
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
    }
    else
    {
        msg.setText("<font color='white'>Error while opening file "+ file.fileName() +"</font>");
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
    LoadFile(name);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    ui->viewDataTable->horizontalHeader()->setMinimumSectionSize(ui->viewDataTable->width() / 16);
}

void MainWindow::on_tbOpenFile_clicked()
{
    ui->fil_name_label->setText(QFileDialog::getOpenFileName(this, "Open File"));
    LoadFile(ui->fil_name_label->text());
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
    if(convStatus) {
        ui->viewDataTable->selectionModel()->clearSelection();
        ui->viewDataTable->selectionModel()->select(m_hexDataViewModel->index((offset / 16), (std::modf(double((double)offset / 16.0), &tempX) * 16)), QItemSelectionModel::Select);
    }
}

void MainWindow::dataTableSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    ui->listByteInfo->clear();
    if( selected.indexes().length() > 0) {
        QString selectedByte = selected.indexes().first().data(Qt::DisplayRole).toString();
        ui->listByteInfo->addItem("Hex: " + selectedByte);
        ui->listByteInfo->addItem("Real: " + QByteArray::fromHex(selectedByte.toLocal8Bit()));
    }
}

