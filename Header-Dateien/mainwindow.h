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
#include <QErrorMessage>
#include <QMessageBox>


#include "interpolationsplot.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT    

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    const double MINIMUM;
    const double MAXIMUM;

    QWidget * widgetCentral;

    //Layouts:
    QVBoxLayout * mainLayout;
    QGridLayout * subGridLayout;
    QHBoxLayout * subHBoxLayout;

    //Plot:
    Interpolationsplot * plot;

    //Buttons:
    QPushButton * buttonPunktHinzufuegen;
    QPushButton * buttonAchsenAktualisieren;
    QPushButton * buttonAllePunkteLoeschen;
    QPushButton * buttonIArtenAktivieren;
    QPushButton * buttonIArtenDeaktivieren;
    QPushButton * buttonAlleIArtenAktivieren;
    QPushButton * buttonAlleIArtenDeaktivieren;
    QPushButton * buttonReset;
    QPushButton * buttonHilfe;
    QPushButton * buttonBeenden;


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

    //Labels:
    QLabel * labelDefinitionsbereich;
    QLabel * labelXMin;
    QLabel * labelXMax;
    QLabel * labelWertebereich;
    QLabel * labelYMin;
    QLabel * labelYMax;
    QLabel * labelPunktperTastatur;
    QLabel * labelXKoord;
    QLabel * labelYKoord;
    QLabel * labelListeAktiv;
    QLabel * labelListeInaktiv;

    //Platzhalter
    QSpacerItem * spacerItem;

    //Fehlermeldungen & Warnungen & Hilfe
    QMessageBox * msgBox;

protected slots:
    void achsenUpdatenSlot();
    void neuerPunktPerTastaturSlot();
    void resetSlot();
    void hilfeSlot();
    void beendenSlot();
    void aktiviereIArtenSlot();
    void deaktiviereIArtenSlot();
    void aktiviereAlleIArtenSlot();
    void deaktiviereAlleIArtenSlot();

};

#endif // MAINWINDOW_H
