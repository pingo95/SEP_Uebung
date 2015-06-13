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
    Quellcode/main.cpp \
    Quellcode/mainwindow.cpp \
    Quellcode/qcustomplot.cpp \
    Quellcode/qstceplot.cpp \
    Quellcode/interpolationsplot.cpp \
    Quellcode/linear.cpp \
    Quellcode/polynom.cpp \
    Quellcode/spline.cpp \
    Quellcode/customqpunktevektor.cpp \
    Quellcode/punkt.cpp \
    Quellcode/customqlistwidgetitem.cpp

HEADERS  += \
    Header-Dateien/mainwindow.h \
    Header-Dateien/qcustomplot.h \
    Header-Dateien/qstceplot.h \
    Header-Dateien/interpolationsart.h \
    Header-Dateien/interpolationsplot.h \
    Header-Dateien/linear.h \
    Header-Dateien/polynom.h \
    Header-Dateien/spline.h \
    Header-Dateien/linear.h \
    Header-Dateien/customqpunktevektor.h \
    Header-Dateien/punkt.h \
    Header-Dateien/splineLib.h \
    Header-Dateien/customqlistwidgetitem.h

win32{RC_FILE = Resources/icon.qrc}

RESOURCES += \
    Resources/projectresources.qrc
