#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T13:19:37
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../InterpolationGruppe11
TEMPLATE = app


SOURCES +=\
    Quellcode/point.cpp \
    Quellcode/pointsvector.cpp \
    Quellcode/qcustomplot.cpp \
    Quellcode/qstceplot.cpp \
    Quellcode/linear.cpp \
    Quellcode/polynom.cpp \
    Quellcode/spline.cpp \
    Quellcode/interpolationplot.cpp \
    Quellcode/mainwindow.cpp \
    Quellcode/main.cpp

HEADERS  += \
    Header-Dateien/point.h \
    Header-Dateien/pointsvector.h \
    Header-Dateien/qcustomplot.h \
    Header-Dateien/qstceplot.h \
    Header-Dateien/interpolationtype.h \
    Header-Dateien/linear.h \
    Header-Dateien/polynom.h \
    Header-Dateien/splineLib.h \
    Header-Dateien/spline.h \
    Header-Dateien/interpolationplot.h \
    Header-Dateien/mainwindow.h

win32:RC_FILE = Resources/icon.qrc

RESOURCES += \
    Resources/projectresources.qrc
