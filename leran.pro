#-------------------------------------------------
#
# Project created by QtCreator 2016-11-18T23:05:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FsecPatch
TEMPLATE = app


SOURCES += main.cpp\
    HexTableModel.cpp \
        mainwindow.cpp \
    update.cpp

HEADERS  += mainwindow.h \
    HexTableModel.h \
    HexTableView.h \
    update.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resc.qrc
