#include "../Header-Dateien/mainwindow.h"
#include "../Header-Dateien/linear.h"
#include "../Header-Dateien/polynom.h"
#include "../Header-Dateien/spline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), MINIMUM(-1000), MAXIMUM(1000)
{
    //Interpolationsarten hinzufügen
    mapAlleIArten["Lineare Interpolation"] = new Linear();
    mapAlleIArten["Polynom-Interpolation"] = new Polynom();
    mapAlleIArten["kubische Spline-Interpolation"] = new Spline();

    //centrales Widget initialisieren
    widgetCentral = new QWidget(this);    

    setWindowTitle("SEP Interpolation Gruppe 11");
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background,Qt::white);
    widgetCentral->setPalette(Pal);
    widgetCentral->setAutoFillBackground(true);

    //Plot initialisieren
    plot = new Interpolationsplot(widgetCentral);
    plot->setMinimumSize(560,480);

    //Buttons initialisieren
    buttonPunktHinzufuegen = new QPushButton("Punkt hinzufügen",widgetCentral);
    buttonAchsenAktualisieren = new QPushButton("Achsen aktualisieren",widgetCentral);
    buttonAllePunkteLoeschen = new QPushButton("Alle Punkte löschen",widgetCentral);
    buttonIArtenAktivieren = new QPushButton(widgetCentral);
    buttonIArtenDeaktivieren = new QPushButton(widgetCentral);
    buttonAlleIArtenAktivieren = new QPushButton(widgetCentral);
    buttonAlleIArtenDeaktivieren = new QPushButton(widgetCentral);
    buttonReset = new QPushButton("Reset",widgetCentral);
//    buttonOptionen = new QPushButton("Optionen",widgetCentral);
    buttonBeenden = new QPushButton("Beenden", widgetCentral);

    //Icons+Groesse
    buttonIArtenAktivieren->setLayoutDirection(Qt::RightToLeft);
    buttonIArtenAktivieren->setIcon(QIcon(":/Icons/right"));
//    buttonIArtenAktivieren->setText("        Aktivieren");
    buttonIArtenAktivieren->setIconSize(QSize(15,15));

    buttonIArtenDeaktivieren->setIcon(QIcon(":/Icons/left"));
//    buttonIArtenDeaktivieren->setText("Deaktivieren");
    buttonIArtenDeaktivieren->setIconSize(QSize(15,15));

    buttonAlleIArtenAktivieren->setLayoutDirection(Qt::RightToLeft);
    buttonAlleIArtenAktivieren->setIcon(QIcon(":/Icons/2right"));
//    buttonAlleIArtenAktivieren->setText("   Alle aktivieren");
    buttonAlleIArtenAktivieren->setIconSize(QSize(15,15));

    buttonAlleIArtenDeaktivieren->setIcon(QIcon(":/Icons/2left"));
//    buttonAlleIArtenDeaktivieren->setText("Alle deaktivieren");
    buttonAlleIArtenDeaktivieren->setIconSize(QSize(15,15));

    //SpinBoxen initialisieren
    spinBoxXMin = new QDoubleSpinBox(widgetCentral);
    spinBoxXMax = new QDoubleSpinBox(widgetCentral);
    spinBoxYMin = new QDoubleSpinBox(widgetCentral);
    spinBoxYMax = new QDoubleSpinBox(widgetCentral);
    spinBoxXKoord = new QDoubleSpinBox(widgetCentral);
    spinBoxYKoord = new QDoubleSpinBox(widgetCentral);

    spinBoxXMax->setMaximumWidth(70);
    spinBoxYMax->setMaximumWidth(70);
    spinBoxYKoord->setMaximumWidth(70);

    //Listen initialisieren
    listWidgetAktiveIArten = new QListWidget(widgetCentral);
    listWidgetInaktiveIArten = new QListWidget(widgetCentral);

    listWidgetInaktiveIArten->setMaximumWidth(180);
    listWidgetAktiveIArten->setMaximumWidth(180);

    //Label initialisieren
    labelDefinitionsbereich = new QLabel("Definitionsbereich:",widgetCentral);
    labelXMin = new QLabel("xMin",widgetCentral);
    labelXMax = new QLabel("xMax",widgetCentral);
    labelWertebereich = new QLabel("Wertebereich:",widgetCentral);
    labelYMin = new QLabel("yMin",widgetCentral);
    labelYMax = new QLabel("yMax",widgetCentral);
    labelPunktperTastatur = new QLabel("Punkt per Tastatur:",widgetCentral);
    labelXKoord = new QLabel("x-Koordinate",widgetCentral);
    labelYKoord = new QLabel("y-Koordinate",widgetCentral);
    labelDummy = new QLabel("",widgetCentral);

    //Ausrichtung der Labels
    labelXMin->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelXMax->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYMin->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYMax->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelXKoord->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYKoord->setAlignment(Qt::AlignVCenter | Qt::AlignRight);

    //Layouts initialisieren
    mainLayout = new QVBoxLayout(widgetCentral);
    subGridLayout = new QGridLayout(widgetCentral);
    subHBoxLayout = new QHBoxLayout(widgetCentral);

    mainLayout->addWidget(plot,6);
    mainLayout->addLayout(subGridLayout,0);

    //erste Zeile
    subGridLayout->addWidget(labelDefinitionsbereich,0,0);
    subGridLayout->addWidget(labelXMin,0,1);
    subGridLayout->addWidget(spinBoxXMin,0,2);
    subGridLayout->addWidget(labelXMax,0,3);
    subGridLayout->addWidget(spinBoxXMax,0,4);
    subGridLayout->addWidget(buttonAchsenAktualisieren,0,5,2,1);
    subGridLayout->addWidget(labelDummy,0,6);


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
    subGridLayout->addWidget(listWidgetInaktiveIArten,3,0,4,2);
    subGridLayout->addWidget(buttonIArtenAktivieren,3,2);
    subGridLayout->addWidget(buttonIArtenDeaktivieren,4,2);
    subGridLayout->addWidget(buttonAlleIArtenAktivieren,5,2);
    subGridLayout->addWidget(buttonAlleIArtenDeaktivieren,6,2);
    subGridLayout->addWidget(listWidgetAktiveIArten,3,3,4,2);
    subGridLayout->addWidget(buttonAllePunkteLoeschen,3,5);

    //fünfte Zeile
    //subGridLayout->addWidget(buttonOptionen,4,5);

    //sechste Zeile
    subGridLayout->addWidget(buttonReset,5,5);

    //siebte Zeile
    subGridLayout->addWidget(buttonBeenden,6,5);

    //Spalten-Stretch anpassen
    subGridLayout->setColumnStretch(0,0);
    subGridLayout->setColumnStretch(1,0);
    subGridLayout->setColumnStretch(2,0);
    subGridLayout->setColumnStretch(3,0);
    subGridLayout->setColumnStretch(4,0);
    subGridLayout->setColumnStretch(5,0);
    subGridLayout->setColumnStretch(6,1);

    //Layout anwenden
    widgetCentral->setLayout(mainLayout);
    setCentralWidget(widgetCentral);

    //Buttons & Slots verbinden
    connect(buttonAchsenAktualisieren,SIGNAL(clicked(bool)),this,SLOT(achsenUpdatenSlot()));
    connect(buttonPunktHinzufuegen,SIGNAL(clicked(bool)),this,SLOT(neuerPunktPerTastaturSlot()));
    connect(buttonAllePunkteLoeschen,SIGNAL(clicked(bool)),plot,SLOT(allePunkteLoeschenSlot()));
    connect(buttonReset,SIGNAL(clicked(bool)),this,SLOT(resetSlot()));
//    connect(buttonOptionen,SIGNAL(clicked(bool)),this,SLOT(optionenSlot()));
    connect(buttonBeenden,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(buttonIArtenAktivieren,SIGNAL(clicked(bool)),this,SLOT(aktiviereIArtenSlot()));
    connect(buttonIArtenDeaktivieren,SIGNAL(clicked(bool)),this,SLOT(deaktiviereIArtenSlot()));
    connect(buttonAlleIArtenAktivieren,SIGNAL(clicked(bool)),this,SLOT(aktiviereAlleIArtenSlot()));
    connect(buttonAlleIArtenDeaktivieren,SIGNAL(clicked(bool)),this,SLOT(deaktiviereAlleIArtenSlot()));

    //Achseninitialisierung
    spinBoxXMin->setMinimum(MINIMUM);
    spinBoxXMin->setMaximum(MAXIMUM);
    spinBoxXMax->setMinimum(MINIMUM);
    spinBoxXMax->setMaximum(MAXIMUM);

    spinBoxYMin->setMinimum(MINIMUM);
    spinBoxYMin->setMaximum(MAXIMUM);
    spinBoxYMax->setMinimum(MINIMUM);
    spinBoxYMax->setMaximum(MAXIMUM);

    spinBoxXMin->setValue(0);
    spinBoxXMax->setValue(100);
    spinBoxYMin->setValue(0);
    spinBoxYMax->setValue(50);

    spinBoxXKoord->setMinimum(0);
    spinBoxXKoord->setMaximum(100);
    spinBoxYKoord->setMinimum(0);
    spinBoxYKoord->setMaximum(50);

    spinBoxXKoord->setValue(50);
    spinBoxYKoord->setValue(25);

    //Interpolationsarten initialisieren
    listWidgetInaktiveIArten->setSelectionMode(QAbstractItemView::MultiSelection);
    listWidgetAktiveIArten->setSelectionMode(QAbstractItemView::MultiSelection);

    QList<QString> labels = mapAlleIArten.keys();
    QList<QString>::iterator it=labels.begin();
    for(;it!=labels.end();++it){
//        QListWidgetItem * tmp = new QListWidgetItem(*it,listWidgetAktiveIArten);
//        tmp->setHidden(true);
        listWidgetInaktiveIArten->addItem(*it);
    }

    buttonIArtenDeaktivieren->setDisabled(true);
    buttonAlleIArtenDeaktivieren->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete widgetCentral;
    QList<Interpolationsart*> tmp = mapAlleIArten.values();
    QList<Interpolationsart*>::iterator it=tmp.begin();
    for(;it!=tmp.end();++it) delete (*it);
}

void MainWindow::achsenUpdatenSlot(){
    double newXMin = spinBoxXMin->value();
    double newXMax = spinBoxXMax->value();
    double newYMin = spinBoxYMin->value();
    double newYMax = spinBoxYMax->value();
    if (newXMin >= newXMax || newYMin >= newYMax){
        plot->getRange(newXMin,newXMax,newYMin,newYMax);
        spinBoxXMin->setValue(newXMin);
        spinBoxXMax->setValue(newXMax);
        spinBoxYMin->setValue(newYMin);
        spinBoxYMax->setValue(newYMax);
        return;
    }
    plot->setRange(newXMin,newXMax,newYMin,newYMax);
    spinBoxXKoord->setMinimum(newXMin);
    spinBoxXKoord->setMaximum(newXMax);
    spinBoxYKoord->setMinimum(newYMin);
    spinBoxYKoord->setMaximum(newYMax);
}

void MainWindow::neuerPunktPerTastaturSlot(){
    emit plot->plotOnClickEvent(spinBoxXKoord->value(),spinBoxYKoord->value(),Qt::LeftButton);
    double xMin,xMax,yMin,yMax;
    plot->getRange(xMin,xMax,yMin,yMax);
    spinBoxXKoord->setValue(0.5*(xMax-xMin));
    spinBoxYKoord->setValue(0.5*(yMax-yMin));
}

//void MainWindow::optionenSlot(){

//}

void MainWindow::resetSlot(){
    while(listWidgetAktiveIArten->count()>0){
        QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(0);
        listWidgetInaktiveIArten->addItem(tmpItem);
    }
    spinBoxXMin->setValue(0);
    spinBoxXMax->setValue(100);
    spinBoxYMin->setValue(0);
    spinBoxYMax->setValue(50);

    spinBoxXKoord->setMinimum(0);
    spinBoxXKoord->setMaximum(100);
    spinBoxYKoord->setMinimum(0);
    spinBoxYKoord->setMaximum(50);

    spinBoxXKoord->setValue(50);
    spinBoxYKoord->setValue(25);

    buttonIArtenAktivieren->setDisabled(false);
    buttonAlleIArtenAktivieren->setDisabled(false);
    buttonIArtenDeaktivieren->setDisabled(true);
    buttonAlleIArtenDeaktivieren->setDisabled(true);

    plot->reset();
}

void MainWindow::aktiviereIArtenSlot(){
    QList<QListWidgetItem*> changedIArten = listWidgetInaktiveIArten->selectedItems();
    if(changedIArten.size()==0) return;
    while(changedIArten.size()>1){
        double tmpRow = listWidgetInaktiveIArten->row(changedIArten.takeFirst());
        QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(tmpRow);
        listWidgetAktiveIArten->addItem(tmpItem);
        plot->addIArtOhnePlotten(mapAlleIArten[tmpItem->text()]);
    }
    double tmpRow = listWidgetInaktiveIArten->row(changedIArten.takeFirst());
    QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(tmpRow);
    listWidgetAktiveIArten->addItem(tmpItem);
    plot->addIArt(mapAlleIArten[tmpItem->text()]);


    buttonIArtenDeaktivieren->setDisabled(false);
    buttonAlleIArtenDeaktivieren->setDisabled(false);
    if(listWidgetInaktiveIArten->count()==0){
        buttonIArtenAktivieren->setDisabled(true);
        buttonAlleIArtenAktivieren->setDisabled(true);
    }
}

void MainWindow::deaktiviereIArtenSlot(){
    QList<QListWidgetItem*> changedIArten = listWidgetAktiveIArten->selectedItems();
    if(changedIArten.size()==0) return;
    while(changedIArten.size()>1){
        double tmpRow = listWidgetAktiveIArten->row(changedIArten.takeFirst());
        QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(tmpRow);
        listWidgetInaktiveIArten->addItem(tmpItem);
        plot->removeIArtOhnePlotten(mapAlleIArten[tmpItem->text()]);
    }
    double tmpRow = listWidgetAktiveIArten->row(changedIArten.takeFirst());
    QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(tmpRow);
    listWidgetInaktiveIArten->addItem(tmpItem);
    plot->removeIArt(mapAlleIArten[tmpItem->text()]);


    buttonIArtenAktivieren->setDisabled(false);
    buttonAlleIArtenAktivieren->setDisabled(false);
    if(listWidgetAktiveIArten->count()==0){
        buttonIArtenDeaktivieren->setDisabled(true);
        buttonAlleIArtenDeaktivieren->setDisabled(true);
    }
}

void MainWindow::aktiviereAlleIArtenSlot(){
    while(listWidgetInaktiveIArten->count()>1){
        QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(0);
        listWidgetAktiveIArten->addItem(tmpItem);
        plot->addIArtOhnePlotten(mapAlleIArten[tmpItem->text()]);
    }
    QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(0);
    listWidgetAktiveIArten->addItem(tmpItem);
    plot->addIArt(mapAlleIArten[tmpItem->text()]);

    buttonIArtenAktivieren->setDisabled(true);
    buttonAlleIArtenAktivieren->setDisabled(true);
    buttonIArtenDeaktivieren->setDisabled(false);
    buttonAlleIArtenDeaktivieren->setDisabled(false);
}

void MainWindow::deaktiviereAlleIArtenSlot(){
    while(listWidgetAktiveIArten->count()>1){
        QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(0);
        listWidgetInaktiveIArten->addItem(tmpItem);
        plot->removeIArtOhnePlotten(mapAlleIArten[tmpItem->text()]);
    }
    QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(0);
    listWidgetInaktiveIArten->addItem(tmpItem);
    plot->removeIArt(mapAlleIArten[tmpItem->text()]);

    buttonIArtenAktivieren->setDisabled(false);
    buttonAlleIArtenAktivieren->setDisabled(false);
    buttonIArtenDeaktivieren->setDisabled(true);
    buttonAlleIArtenDeaktivieren->setDisabled(true);

    plot->removeAlleIArten();
}
