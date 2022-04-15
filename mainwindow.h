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
#include <QMessageBox>

#include <cmath>

#include "HexTableModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPoint m_ptDragPos;
    QShortcut *undo_redo_shortcut;
    bool backup_mode;
    void startDrag();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void resizeEvent(QResizeEvent* event);

private slots:
    void LoadFile(QString filename);

    void on_tbOpenFile_clicked();

    void on_tbSaveFile_clicked();
    void on_pbRevertSelected_clicked();

    void on_tbGoToOffset_clicked();
    void dataTableSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::MainWindow *ui;
    bool isSearched;
    QList<QPoint> values;
    HexTableModel* m_hexDataViewModel;
public slots:
    void UpdateEditHistory(const QModelIndex& index);
};

#endif // MAINWINDOW_H
