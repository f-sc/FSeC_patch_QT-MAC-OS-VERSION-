#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QString>
#include <QShortcut>
#include <QFileDialog>
#include <QMimeData>
#include <QMouseEvent>
#include <QDrag>
#include <QPoint>
#include <QDialog>
#include <QInputDialog>
#include "patch.h"

#include <cmath>

#include "HexTableModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPoint m_ptDragPos;
    void startDrag()
    {
        QMimeData* pmimeData = new QMimeData;
        pmimeData->setText("test");

        QDrag* drag = new QDrag(this);
        drag->setMimeData(pmimeData);
      //  drag->setPixmap(QPixmap(":/im"));
        drag->exec();
    }
    QShortcut *undo_redo_shortcut;
    bool backup_mode;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);

private slots:

    void on_go_search_clicked();

    void on_data_t_activated(const QString &arg1);

    void load_file(QString filename);

    void on_tbOpenFile_clicked();

    void on_tbSaveFile_clicked();
    void on_pbRevertSelected_clicked();

    void on_tbGoToOffset_clicked();

private:
    Ui::MainWindow *ui;
    patch *manager;
    bool isSearched;
    QList<QPoint> values;

    HexTableModel* m_hexDataViewModel;
public slots:
    void UpdateEditHistory(const QModelIndex& index);
};

#endif // MAINWINDOW_H
