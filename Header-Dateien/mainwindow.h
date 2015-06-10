#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QToolButton>

#include "interpolationsplot.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
