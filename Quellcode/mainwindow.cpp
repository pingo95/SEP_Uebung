#include "../Header-Dateien/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    Beispiel für 2 Knöpfe mit Bildern + Text (rechts bzw links vom Bild
//    test = new QPushButton(centralesWidget);
//    test->setIcon(QIcon(":/Icons/leftArrow"));
//    test->setText("Aktivieren");
//    test->setIconSize(QSize(32,32));
//    test2 = new QPushButton(centralesWidget);
//    test2->setLayoutDirection(Qt::RightToLeft);
//    test2->setIcon(QIcon(":/Icons/rightArrow"));
//    test2->setText("Deaktivieren");
//    test2->setIconSize(QSize(32,32));

    widgetCentral = new QWidget(this);

    plot = new Interpolationsplot(widgetCentral);

    buttonPunktHinzufuegen = new QPushButton("Punkt hinzufügen",widgetCentral);
    buttonAchsenAktualisieren = new QPushButton("Achsen aktualisieren",widgetCentral);
    buttonAllePunkteLoeschen = new QPushButton("Alle Punkte löschen",widgetCentral);
    buttonIArtenAktivieren = new QPushButton("hinzufügen",widgetCentral);
    buttonIArtenDeaktivieren = new QPushButton("entfernen",widgetCentral);
    buttonReset = new QPushButton("Reset",widgetCentral);
    //buttonOptionen = new QPushButton("Optionen",widgetCentral);

    spinBoxXMin = new QDoubleSpinBox(widgetCentral);
    spinBoxXMax = new QDoubleSpinBox(widgetCentral);
    spinBoxYMin = new QDoubleSpinBox(widgetCentral);
    spinBoxYMax = new QDoubleSpinBox(widgetCentral);
    spinBoxXKoord = new QDoubleSpinBox(widgetCentral);
    spinBoxYKoord = new QDoubleSpinBox(widgetCentral);

    listWidgetAktiveIArten = new QListWidget(widgetCentral);
    listWidgetInaktiveIArten = new QListWidget(widgetCentral);

    labelDefinitionsbereich = new QLabel("Definitionsbereich:",widgetCentral);
    labelXMin = new QLabel("xMin",widgetCentral);
    labelXMax = new QLabel("xMax",widgetCentral);
    labelWertebereich = new QLabel("Wertebereich:",widgetCentral);
    labelYMin = new QLabel("yMin",widgetCentral);
    labelYMax = new QLabel("xMax",widgetCentral);
    labelPunktperTastatur = new QLabel("Punkt per Tastatur:",widgetCentral);
    labelXKoord = new QLabel("x-Koordinate",widgetCentral);
    labelYKoord = new QLabel("y-Koordinate",widgetCentral);


}

MainWindow::~MainWindow()
{
    delete widgetCentral;
}

