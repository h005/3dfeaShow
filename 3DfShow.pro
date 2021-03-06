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

DP_TOOLS_DIR = $$(DP_TOOLS_DIR)
INCLUDEPATH += $$DP_TOOLS_DIR\opencv\build\include\opencv\
                $$DP_TOOLS_DIR\opencv\build\include\opencv2\
                $$DP_TOOLS_DIR\opencv\build\include

LIBS += -L$$DP_TOOLS_DIR\opencv\build\x86\vc12\lib \
        -lopencv_calib3d249d \
        -lopencv_contrib249d \
        -lopencv_core249d \
        -lopencv_features2d249d \
        -lopencv_flann249d \
        -lopencv_gpu249d \
        -lopencv_highgui249d \
        -lopencv_imgproc249d \
        -lopencv_legacy249d \
        -lopencv_ml249d \
        -lopencv_nonfree249d \
        -lopencv_objdetect249d \
        -lopencv_ocl249d \
        -lopencv_photo249d \
        -lopencv_stitching249d \
        -lopencv_superres249d \
        -lopencv_ts249d \
        -lopencv_video249d \
        -lopencv_videostab249d
