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
    update.cpp \
    WebUpdateTools.cpp

HEADERS  += mainwindow.h \
    HexTableModel.h \
    HexTableView.h \
    update.h \
    WebUpdateTools.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resc.qrc

RC_ICONS = res/exeIcon.ico

INCLUDEPATH += C:/Users/Dmitry/Documents/CODE/LIBS/curl-7.70.0/include
CURL_DLL_PATH = C:/Users/Dmitry/Documents/CODE/LIBS/build-curl-7.70.0-Desktop_Qt_5_12_5_MSVC2017_32bit-Release/lib
LIBS += $${CURL_DLL_PATH}/libcurl_imp.lib
