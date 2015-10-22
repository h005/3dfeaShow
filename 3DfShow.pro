#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T00:52:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DfShow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    labelview.cpp

HEADERS  += mainwindow.h \
    labelview.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:\opencv\include\
            D:\opencv\include\opencv\
            D:\opencv\include\opencv2

LIBS += D:/opencv/lib/*.dll.a
