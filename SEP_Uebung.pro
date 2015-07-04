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
    Quellcode/Interpolationplot.cpp \
    Quellcode/Linear.cpp \
    Quellcode/Main.cpp \
    Quellcode/Mainwindow.cpp \
    Quellcode/Point.cpp \
    Quellcode/Pointsvector.cpp \
    Quellcode/Polynom.cpp \
    Quellcode/Qcustomplot.cpp \
    Quellcode/Qstceplot.cpp \
    Quellcode/Spline.cpp

HEADERS  += \
    Header-Dateien/Interpolationplot.h \
    Header-Dateien/Interpolationtype.h \
    Header-Dateien/Linear.h \
    Header-Dateien/Mainwindow.h \
    Header-Dateien/Point.h \
    Header-Dateien/Pointsvector.h \
    Header-Dateien/Polynom.h \
    Header-Dateien/Qcustomplot.h \
    Header-Dateien/Qstceplot.h \
    Header-Dateien/Spline.h \
    Header-Dateien/SplineLib.h

win32:RC_FILE = Resources/icon.qrc

RESOURCES += \
    Resources/Projectresources.qrc
