#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T13:19:37
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEP_Uebung
TEMPLATE = app


SOURCES +=\
    Quellcode/qcustomplot.cpp \
    Quellcode/qstceplot.cpp \
    Quellcode/linear.cpp \
    Quellcode/polynom.cpp \
    Quellcode/spline.cpp \
    Quellcode/mainwindow.cpp \
    Quellcode/main.cpp \
    Quellcode/pointsvector.cpp \
    Quellcode/point.cpp \
    Quellcode/interpolationplot.cpp \
    Quellcode/interpolationregistry.cpp

HEADERS  += \
    Header-Dateien/qcustomplot.h \
    Header-Dateien/qstceplot.h \
    Header-Dateien/linear.h \
    Header-Dateien/polynom.h \
    Header-Dateien/splineLib.h \
    Header-Dateien/spline.h \
    Header-Dateien/mainwindow.h \
    Header-Dateien/pointsvector.h \
    Header-Dateien/point.h \
    Header-Dateien/interpolationplot.h \
    Header-Dateien/interpolationtype.h \
    Header-Dateien/interpolationregistry.h

win32:RC_FILE = Resources/icon.qrc

RESOURCES += \
    Resources/projectresources.qrc
