/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *data_table;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QProgressBar *progress_saveload;
    QLabel *fil_name_label;
    QWidget *search;
    QPushButton *go_search;
    QLineEdit *data_v;
    QLabel *text_to_search;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QWidget *convert;
    QComboBox *data_t;
    QLabel *to_convert;
    QLabel *converted;
    QListWidget *last_actions;
    QToolButton *toolButton_7;
    QLineEdit *offset_text;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(906, 548);
        MainWindow->setMinimumSize(QSize(906, 548));
        MainWindow->setMaximumSize(QSize(906, 548));
        MainWindow->setStyleSheet(QLatin1String("background-color:black\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        data_table = new QTableWidget(centralWidget);
        data_table->setObjectName(QStringLiteral("data_table"));
        data_table->setGeometry(QRect(10, 30, 771, 501));
        data_table->setStyleSheet(QStringLiteral("background-color:white"));
        data_table->verticalHeader()->setVisible(false);
        data_table->verticalHeader()->setCascadingSectionResizes(false);
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 0, 31, 31));
        toolButton->setStyleSheet(QStringLiteral("background-color:black"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(29, 27));
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(40, 0, 31, 31));
        toolButton_2->setStyleSheet(QStringLiteral("background-color:black"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/img/save.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(29, 27));
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(80, 0, 31, 31));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/img/back.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(29, 27));
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setEnabled(false);
        toolButton_4->setGeometry(QRect(110, 0, 31, 31));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/img/forw.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(29, 27));
        progress_saveload = new QProgressBar(centralWidget);
        progress_saveload->setObjectName(QStringLiteral("progress_saveload"));
        progress_saveload->setGeometry(QRect(480, 6, 118, 16));
        progress_saveload->setStyleSheet(QStringLiteral("background-color:black"));
        progress_saveload->setValue(0);
        fil_name_label = new QLabel(centralWidget);
        fil_name_label->setObjectName(QStringLiteral("fil_name_label"));
        fil_name_label->setGeometry(QRect(120, 530, 751, 16));
        search = new QWidget(centralWidget);
        search->setObjectName(QStringLiteral("search"));
        search->setEnabled(true);
        search->setGeometry(QRect(150, 30, 120, 81));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(128, 128, 128, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        search->setPalette(palette);
        search->setStyleSheet(QLatin1String("background-color: grey\n"
""));
        go_search = new QPushButton(search);
        go_search->setObjectName(QStringLiteral("go_search"));
        go_search->setGeometry(QRect(0, 50, 121, 32));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        go_search->setPalette(palette1);
        go_search->setStyleSheet(QStringLiteral("color:white"));
        data_v = new QLineEdit(search);
        data_v->setObjectName(QStringLiteral("data_v"));
        data_v->setGeometry(QRect(10, 30, 101, 21));
        data_v->setStyleSheet(QStringLiteral("color:white"));
        text_to_search = new QLabel(search);
        text_to_search->setObjectName(QStringLiteral("text_to_search"));
        text_to_search->setGeometry(QRect(10, 0, 91, 20));
        text_to_search->setStyleSheet(QStringLiteral("color:white"));
        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(200, 0, 31, 31));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/img/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setIconSize(QSize(29, 27));
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(250, 0, 41, 31));
        toolButton_6->setStyleSheet(QStringLiteral("background-color:black"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/img/htb.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);
        toolButton_6->setIconSize(QSize(29, 27));
        convert = new QWidget(centralWidget);
        convert->setObjectName(QStringLiteral("convert"));
        convert->setEnabled(true);
        convert->setGeometry(QRect(210, 30, 120, 81));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        convert->setPalette(palette2);
        convert->setStyleSheet(QLatin1String("background-color: grey\n"
""));
        data_t = new QComboBox(convert);
        data_t->setObjectName(QStringLiteral("data_t"));
        data_t->setGeometry(QRect(0, 0, 121, 26));
        data_t->setStyleSheet(QStringLiteral("color:white"));
        to_convert = new QLabel(convert);
        to_convert->setObjectName(QStringLiteral("to_convert"));
        to_convert->setGeometry(QRect(20, 30, 91, 20));
        to_convert->setStyleSheet(QStringLiteral("color:white"));
        converted = new QLabel(convert);
        converted->setObjectName(QStringLiteral("converted"));
        converted->setGeometry(QRect(20, 50, 91, 20));
        converted->setStyleSheet(QStringLiteral("color:white"));
        last_actions = new QListWidget(centralWidget);
        last_actions->setObjectName(QStringLiteral("last_actions"));
        last_actions->setGeometry(QRect(790, 30, 111, 501));
        last_actions->setStyleSheet(QStringLiteral("background-color:white"));
        toolButton_7 = new QToolButton(centralWidget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(420, 0, 31, 31));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/img/goto.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon6);
        toolButton_7->setIconSize(QSize(29, 27));
        offset_text = new QLineEdit(centralWidget);
        offset_text->setObjectName(QStringLiteral("offset_text"));
        offset_text->setGeometry(QRect(300, 5, 113, 21));
        offset_text->setStyleSheet(QStringLiteral("background-color:white"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(810, 10, 81, 20));
        label->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralWidget);
        progress_saveload->raise();
        fil_name_label->raise();
        toolButton_7->raise();
        toolButton_6->raise();
        toolButton_5->raise();
        toolButton->raise();
        toolButton_2->raise();
        data_table->raise();
        toolButton_3->raise();
        toolButton_4->raise();
        search->raise();
        convert->raise();
        last_actions->raise();
        offset_text->raise();
        label->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FSeC Patch", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainWindow", "<-", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MainWindow", "->", Q_NULLPTR));
        fil_name_label->setText(QApplication::translate("MainWindow", "No file opened", Q_NULLPTR));
        go_search->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        text_to_search->setText(QApplication::translate("MainWindow", "HEX to search", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("MainWindow", "Convert", Q_NULLPTR));
        data_t->clear();
        data_t->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "HEX", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Char", Q_NULLPTR)
        );
        to_convert->setText(QApplication::translate("MainWindow", "FF", Q_NULLPTR));
        converted->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        toolButton_7->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<font color='white'>Last changes:</font>\"", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
