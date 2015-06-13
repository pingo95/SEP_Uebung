#include "../Header-Dateien/mainwindow.h"
#include "../Header-Dateien/linear.h"
#include "../Header-Dateien/polynom.h"
#include "../Header-Dateien/spline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    widgetCentral = new QWidget(this);    

    setWindowTitle("SEP Interpolation Gruppe 11");
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background,Qt::white);
    widgetCentral->setPalette(Pal);
    widgetCentral->setAutoFillBackground(true);


//    plot = new Interpolationsplot(widgetCentral);

    buttonPunktHinzufuegen = new QPushButton("Punkt hinzufügen",widgetCentral);
    buttonAchsenAktualisieren = new QPushButton("Achsen aktualisieren",widgetCentral);
    buttonAllePunkteLoeschen = new QPushButton("Alle Punkte löschen",widgetCentral);
    buttonIArtenAktivieren = new QPushButton(widgetCentral);
    buttonIArtenDeaktivieren = new QPushButton(widgetCentral);
    buttonAlleIArtenAktivieren = new QPushButton(widgetCentral);
    buttonAlleIArtenDeaktivieren = new QPushButton(widgetCentral);
    buttonReset = new QPushButton("Reset",widgetCentral);
    buttonOptionen = new QPushButton("Optionen",widgetCentral);

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
    Dummy = new QLabel("",widgetCentral);

    //Ausrichtung der Labels
    labelXMin->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelXMax->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYMin->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYMax->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelXKoord->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYKoord->setAlignment(Qt::AlignVCenter | Qt::AlignRight);


    //Icons auf Buttons setzen
    buttonIArtenAktivieren->setLayoutDirection(Qt::RightToLeft);
    buttonIArtenAktivieren->setIcon(QIcon(":/Icons/right"));
    buttonIArtenAktivieren->setText("Aktivieren");
    buttonIArtenAktivieren->setIconSize(QSize(15,15));



    buttonIArtenDeaktivieren->setIcon(QIcon(":/Icons/left"));
    buttonIArtenDeaktivieren->setText("Deaktivieren");
    buttonIArtenDeaktivieren->setIconSize(QSize(15,15));

    buttonAlleIArtenAktivieren->setLayoutDirection(Qt::RightToLeft);
    buttonAlleIArtenAktivieren->setIcon(QIcon(":/Icons/2right"));
    buttonAlleIArtenAktivieren->setText("Alle aktivieren");
    buttonAlleIArtenAktivieren->setIconSize(QSize(15,15));

    buttonAlleIArtenDeaktivieren->setIcon(QIcon(":/Icons/2left"));
    buttonAlleIArtenDeaktivieren->setText("Alle deaktivieren");
    buttonAlleIArtenDeaktivieren->setIconSize(QSize(15,15));



    //Layout
    mainLayout = new QVBoxLayout(widgetCentral);
    subGridLayout = new QGridLayout(widgetCentral);
    subHBoxLayout = new QHBoxLayout(widgetCentral);

    plot->setMinimumSize(680,480);
    mainLayout->addWidget(plot,6);
    mainLayout->addLayout(subGridLayout,0);
    subGridLayout->setColumnStretch(0,0);
    subGridLayout->setColumnStretch(1,0);
    subGridLayout->setColumnStretch(2,0);
    subGridLayout->setColumnStretch(3,0);
    subGridLayout->setColumnStretch(4,0);
    subGridLayout->setColumnStretch(5,0);
    subGridLayout->setColumnStretch(6,0);
    subGridLayout->setColumnStretch(7,2);


    //erste Zeile
    subGridLayout->addWidget(labelDefinitionsbereich,0,0);
    subGridLayout->addWidget(labelXMin,0,1);
    subGridLayout->addWidget(spinBoxXMin,0,2);
    subGridLayout->addWidget(labelXMax,0,3);
    subGridLayout->addWidget(spinBoxXMax,0,4);
    subGridLayout->addWidget(Dummy,0,7);

    subGridLayout->addWidget(buttonAchsenAktualisieren,0,5,2,1);


    //zweite Zeile
    subGridLayout->addWidget(labelWertebereich,1,0);
    subGridLayout->addWidget(labelYMin,1,1);
    subGridLayout->addWidget(spinBoxYMin,1,2);
    subGridLayout->addWidget(labelYMax,1,3);
    subGridLayout->addWidget(spinBoxYMax,1,4);

    //dritte Zeile
    subGridLayout->addWidget(labelPunktperTastatur,2,0);
    subGridLayout->addWidget(labelXKoord,2,1);
    subGridLayout->addWidget(spinBoxXKoord,2,2);
    subGridLayout->addWidget(labelYKoord,2,3);
    subGridLayout->addWidget(spinBoxYKoord,2,4);
    subGridLayout->addWidget(buttonPunktHinzufuegen,2,5);

    //vierte Zeile

    listWidgetInaktiveIArten->setMaximumWidth(220);
    listWidgetAktiveIArten->setMaximumWidth(220);

    subGridLayout->addWidget(listWidgetInaktiveIArten,3,0,4,2);
    subGridLayout->addWidget(buttonIArtenAktivieren,3,2);
    subGridLayout->addWidget(buttonIArtenDeaktivieren,4,2);
    subGridLayout->addWidget(buttonAlleIArtenAktivieren,5,2);
    subGridLayout->addWidget(buttonAlleIArtenDeaktivieren,6,2);
    subGridLayout->addWidget(listWidgetAktiveIArten,3,3,4,2);

    subGridLayout->addWidget(buttonAllePunkteLoeschen,4,5);
    subGridLayout->addWidget(buttonOptionen,5,5);
    subGridLayout->addWidget(buttonReset,6,5);


    new QListWidgetItem(tr("test"),listWidgetAktiveIArten);
    new QListWidgetItem(tr("test2"),listWidgetAktiveIArten);
    new QListWidgetItem(tr("test"),listWidgetAktiveIArten);

    widgetCentral->setLayout(mainLayout);
    setCentralWidget(widgetCentral);



}

MainWindow::~MainWindow()
{
    delete widgetCentral;
}

