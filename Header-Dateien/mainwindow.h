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


#include "Interpolationplot.h"

namespace graphics{

/*!
    \brief MainWindow implements the graphical user interface.

    The UI includes the InterpolationPlot and this class also sets up all the needed connects for the user interaction.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT    

public:

    /*!
        \brief Constructor for MainWindow.

    Sets up the graphical user interface including the Qt elements, the InterpolationPlot, and adding all the interpolation-types to the UI and the InterpolationPlot.
    */
    MainWindow(QWidget *parent = 0);

    /*!
        \brief Destructor for MainWindow
    */
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

    /*!
        \brief Slot for updating the domain of definition and range.

        Called by pressing the button "Achsen updaten". Gets new values from the UI and adjusts the InterpolationPlot. Shows an errormessage, if new values do not yield a correct dod or range.
    */
    void updateAxesSlot();

    /*!
        \brief Slot for adding a Point to the InterpolationPlot per the keyboard.

        Called by pressing the button "Punkt hinzuzufügen". Gets the coordinates from the UI and adds it to the InterpolationPlot. Shows a warning if new point would be outside of the dod or range.
    */
    void newPointPerKeyboardSlot();

    /*!
        \brief Slot for resetting the software.

        Called by pressing the button "Reset". Resets the UI and forces a reset of the InterpolationPlot.
    */
    void resetSlot();

    /*!
        \brief Slot for showing the help message.

        Called by pressing the button "Hilfe". Shows the help message until the user presser "Schließen".
    */
    void helpSlot();

    /*!
        \brief Slot for shutting down the application.

        Called by pressing the button "Beenden". Asks the user for confirmation, if he confirms, shuts down the software.
    */
    void shutDownSlot();

    /*!
        \brief Slot to activate interpolation-types currently deactive.

        Called by pressing the button ">". Takes the interpolation-types currently marked in the list "Deaktive Arten" and activates them in the InterpolationPlot (which causes are replot).
    */
    void activateITypesSlot();

    /*!
        \brief Slot to deactivate interpolation-types currently active.

        Called by pressing the button "<". Takes the interpolation-types currently marked in the list "Aktive Arten" and deactivates them in the InterpolationPlot (which causes are replot).
    */
    void deactivateITypesSlot();

    /*!
        \brief Slot to activate all interpolation-types currently deactive.

        Called by pressing the button ">>". Takes all the interpolation-types from the list "Deaktive Arten" and activates them in the InterpolationPlot (which causes a replot).
    */
    void activateAllITypesSlot();

    /*!
        \brief Slot to deactivate all interpolation-types currently active.

        Called by pressing the button "<<". Takes all the interpolation-types from the list "Aktive Arten" and deactivates them in the InterpolationPlot (which causes a replot).
    */
    void deactivateAllITypesSlot();

};

}

#endif // MAINWINDOW_H
