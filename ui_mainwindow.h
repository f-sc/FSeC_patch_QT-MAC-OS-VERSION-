/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *layoutHeader;
    QToolButton *tbOpenFile;
    QToolButton *tbSaveFile;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *editOffsetText;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *tbGoToOffset;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *layoutContents;
    QTableView *viewDataTable;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *lblChanges;
    QLabel *lblByteInfoDesc;
    QListWidget *listByteInfo;
    QLabel *lblHistoryDesc;
    QListWidget *listLastEdit;
    QPushButton *pbRevertSelected;
    QHBoxLayout *horizontalLayout;
    QLabel *fil_name_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(906, 548);
        MainWindow->setMinimumSize(QSize(906, 548));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainLayout = new QVBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetMaximumSize);
        layoutHeader = new QHBoxLayout();
        layoutHeader->setSpacing(6);
        layoutHeader->setObjectName(QString::fromUtf8("layoutHeader"));
        tbOpenFile = new QToolButton(centralWidget);
        tbOpenFile->setObjectName(QString::fromUtf8("tbOpenFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbOpenFile->sizePolicy().hasHeightForWidth());
        tbOpenFile->setSizePolicy(sizePolicy1);
        tbOpenFile->setMinimumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8("res/iconOpen.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbOpenFile->setIcon(icon);
        tbOpenFile->setIconSize(QSize(50, 50));

        layoutHeader->addWidget(tbOpenFile);

        tbSaveFile = new QToolButton(centralWidget);
        tbSaveFile->setObjectName(QString::fromUtf8("tbSaveFile"));
        sizePolicy1.setHeightForWidth(tbSaveFile->sizePolicy().hasHeightForWidth());
        tbSaveFile->setSizePolicy(sizePolicy1);
        tbSaveFile->setMinimumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/res/iconSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbSaveFile->setIcon(icon1);
        tbSaveFile->setIconSize(QSize(50, 50));

        layoutHeader->addWidget(tbSaveFile);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layoutHeader->addItem(horizontalSpacer_7);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        layoutHeader->addWidget(label);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layoutHeader->addItem(horizontalSpacer_8);

        editOffsetText = new QLineEdit(centralWidget);
        editOffsetText->setObjectName(QString::fromUtf8("editOffsetText"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editOffsetText->sizePolicy().hasHeightForWidth());
        editOffsetText->setSizePolicy(sizePolicy2);
        editOffsetText->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 150, 150)"));

        layoutHeader->addWidget(editOffsetText);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layoutHeader->addItem(horizontalSpacer_5);

        tbGoToOffset = new QToolButton(centralWidget);
        tbGoToOffset->setObjectName(QString::fromUtf8("tbGoToOffset"));
        sizePolicy1.setHeightForWidth(tbGoToOffset->sizePolicy().hasHeightForWidth());
        tbGoToOffset->setSizePolicy(sizePolicy1);
        tbGoToOffset->setMinimumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/res/iconGoto.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbGoToOffset->setIcon(icon2);
        tbGoToOffset->setIconSize(QSize(50, 50));

        layoutHeader->addWidget(tbGoToOffset);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layoutHeader->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        layoutHeader->addItem(horizontalSpacer_3);


        mainLayout->addLayout(layoutHeader);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        mainLayout->addItem(verticalSpacer);

        layoutContents = new QHBoxLayout();
        layoutContents->setSpacing(6);
        layoutContents->setObjectName(QString::fromUtf8("layoutContents"));
        viewDataTable = new QTableView(centralWidget);
        viewDataTable->setObjectName(QString::fromUtf8("viewDataTable"));
        viewDataTable->setMinimumSize(QSize(0, 0));
        viewDataTable->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170)"));
        viewDataTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        viewDataTable->horizontalHeader()->setCascadingSectionResizes(false);
        viewDataTable->horizontalHeader()->setDefaultSectionSize(40);
        viewDataTable->horizontalHeader()->setStretchLastSection(false);
        viewDataTable->verticalHeader()->setMinimumSectionSize(30);

        layoutContents->addWidget(viewDataTable);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layoutContents->addItem(horizontalSpacer);

        lblChanges = new QVBoxLayout();
        lblChanges->setSpacing(6);
        lblChanges->setObjectName(QString::fromUtf8("lblChanges"));
        lblByteInfoDesc = new QLabel(centralWidget);
        lblByteInfoDesc->setObjectName(QString::fromUtf8("lblByteInfoDesc"));
        lblByteInfoDesc->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        lblByteInfoDesc->setAlignment(Qt::AlignCenter);

        lblChanges->addWidget(lblByteInfoDesc);

        listByteInfo = new QListWidget(centralWidget);
        listByteInfo->setObjectName(QString::fromUtf8("listByteInfo"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listByteInfo->sizePolicy().hasHeightForWidth());
        listByteInfo->setSizePolicy(sizePolicy3);
        listByteInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170)"));

        lblChanges->addWidget(listByteInfo);

        lblHistoryDesc = new QLabel(centralWidget);
        lblHistoryDesc->setObjectName(QString::fromUtf8("lblHistoryDesc"));
        lblHistoryDesc->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        lblHistoryDesc->setAlignment(Qt::AlignCenter);

        lblChanges->addWidget(lblHistoryDesc);

        listLastEdit = new QListWidget(centralWidget);
        listLastEdit->setObjectName(QString::fromUtf8("listLastEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listLastEdit->sizePolicy().hasHeightForWidth());
        listLastEdit->setSizePolicy(sizePolicy4);
        listLastEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 170)"));

        lblChanges->addWidget(listLastEdit);

        pbRevertSelected = new QPushButton(centralWidget);
        pbRevertSelected->setObjectName(QString::fromUtf8("pbRevertSelected"));
        pbRevertSelected->setAutoFillBackground(false);
        pbRevertSelected->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pbRevertSelected->setFlat(false);

        lblChanges->addWidget(pbRevertSelected);


        layoutContents->addLayout(lblChanges);


        mainLayout->addLayout(layoutContents);


        verticalLayout->addLayout(mainLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fil_name_label = new QLabel(centralWidget);
        fil_name_label->setObjectName(QString::fromUtf8("fil_name_label"));
        fil_name_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));

        horizontalLayout->addWidget(fil_name_label);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FSeC Patch", nullptr));
        tbOpenFile->setText(QApplication::translate("MainWindow", "Open", nullptr));
        tbSaveFile->setText(QApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QApplication::translate("MainWindow", "Go to offset(e.g 0x17):", nullptr));
        tbGoToOffset->setText(QApplication::translate("MainWindow", "Search", nullptr));
        lblByteInfoDesc->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Byte info:</p></body></html>", nullptr));
        lblHistoryDesc->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Change history:</p></body></html>", nullptr));
        pbRevertSelected->setText(QApplication::translate("MainWindow", "Revert Selected", nullptr));
        fil_name_label->setText(QApplication::translate("MainWindow", "No file opened", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
