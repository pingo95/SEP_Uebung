#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QListWidget>


#include "interpolationsplot.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT    

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QMap<QString,Interpolationsart*> alleIArten;

    QWidget * widgetCentral;

    //Platz für layouts:
   QVBoxLayout * mainLayout;
   QGridLayout * subGridLayout;
   QHBoxLayout * subHBoxLayout;

    //Plot:
    Interpolationsplot * plot;

    //Button:
    QPushButton * buttonPunktHinzufuegen;
    QPushButton * buttonAchsenAktualisieren;
    QPushButton * buttonAllePunkteLoeschen;
    QPushButton * buttonIArtenAktivieren;
    QPushButton * buttonIArtenDeaktivieren;
    QPushButton * buttonAlleIArtenAktivieren;
    QPushButton * buttonAlleIArtenDeaktivieren;
    QPushButton * buttonReset;
    QPushButton * buttonOptionen;


    //SpinBoxes:
    QDoubleSpinBox * spinBoxXMin;
    QDoubleSpinBox * spinBoxXMax;
    QDoubleSpinBox * spinBoxYMin;
    QDoubleSpinBox * spinBoxYMax;
    QDoubleSpinBox * spinBoxXKoord;
    QDoubleSpinBox * spinBoxYKoord;

    //Listen:
    QListWidget * listWidgetAktiveIArten;
    QListWidget * listWidgetInaktiveIArten;

    //Platz für Labels:
    QLabel * labelDefinitionsbereich;
    QLabel * labelXMin;
    QLabel * labelXMax;
    QLabel * labelWertebereich;
    QLabel * labelYMin;
    QLabel * labelYMax;
    QLabel * labelPunktperTastatur;
    QLabel * labelXKoord;
    QLabel * labelYKoord;
    QLabel * Dummy;

};

#endif // MAINWINDOW_H
