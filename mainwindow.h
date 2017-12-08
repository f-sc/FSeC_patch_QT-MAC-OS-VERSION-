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


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_data_table_cellChanged(int row, int column);

    void on_data_table_activated(const QModelIndex &index);

    void on_data_table_doubleClicked(const QModelIndex &index);
    void ccz();
    void on_toolButton_3_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_5_triggered(QAction *arg1);

    void on_toolButton_5_toggled(bool checked);

    void on_text_to_search_linkActivated(const QString &link);

    void on_toolButton_6_clicked();

    void on_go_search_clicked();

    void on_data_v_cursorPositionChanged(int arg1, int arg2);

    void load_string_view(QString data);

    void on_data_t_activated(const QString &arg1);

    void on_data_v_textChanged(const QString &arg1);

    void on_widget_destroyed();

    void load_file(QString filename);
    void on_toolButton_7_clicked();
    void makeBackup();
    void on_MainWindow_sonClick();

    void on_data_table_cellDoubleClicked(int row, int column);

    void on_check_upd_clicked();

private:
    Ui::MainWindow *ui;
    patch *manager;
    bool isSearched;
    QList<QPoint> values;
};

#endif // MAINWINDOW_H
