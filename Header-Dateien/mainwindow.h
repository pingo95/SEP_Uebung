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


#include "interpolationplot.h"

namespace graphics{
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
    graphics::InterpolationPlot * plot;

    //Buttons:
    QPushButton * buttonAddPoint;
    QPushButton * buttonUpdateAxes;
    QPushButton * buttonDeleteAllPoints;
    QPushButton * buttonActivateITypes;
    QPushButton * buttonDeactivateIType;
    QPushButton * buttonActivateAllITypes;
    QPushButton * buttonDeactivateAllITypes;
    QPushButton * buttonReset;
    QPushButton * buttonHelp;
    QPushButton * buttonShutDown;


    //SpinBoxes:
    QDoubleSpinBox * spinBoxXMin;
    QDoubleSpinBox * spinBoxXMax;
    QDoubleSpinBox * spinBoxYMin;
    QDoubleSpinBox * spinBoxYMax;
    QDoubleSpinBox * spinBoxXKoord;
    QDoubleSpinBox * spinBoxYKoord;

    //Listen:
    QListWidget * listWidgetActiveITypes;
    QListWidget * listWidgetInactiveITypes;

    //Labels:
    QLabel * labelDomainOfDefinition;
    QLabel * labelXMin;
    QLabel * labelXMax;
    QLabel * labelRange;
    QLabel * labelYMin;
    QLabel * labelYMax;
    QLabel * labelPointPerKeyboard;
    QLabel * labelXKoord;
    QLabel * labelYKoord;
    QLabel * labelListeActive;
    QLabel * labelListeInactive;

    //Platzhalter
    QSpacerItem * spacerItem;

    //Fehlermeldungen & Warnungen & Hilfe
    QMessageBox * messageBox;

protected slots:
    void updateAxesSlot();
    void newPointPerKeyboardSlot();
    void resetSlot();
    void helpSlot();
    void shutDownSlot();
    void activateITypesSlot();
    void deactivateITypesSlot();
    void activateAllITypesSlot();
    void deactivateAllITypesSlot();

};

}

#endif // MAINWINDOW_H
