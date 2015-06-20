#include "../Header-Dateien/mainwindow.h"
#include "../Header-Dateien/linear.h"
#include "../Header-Dateien/polynom.h"
#include "../Header-Dateien/spline.h"
#include "../Header-Dateien/interpolationsverzeichnis.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), MINIMUM(-5000), MAXIMUM(5000)
{
    //Interpolationsarten hinzufügen
    InterpolationsVerzeichnis::instanz()->fuegeIArtenHinzu("Lineare Interpolation",new Linear(),Qt::red);
    InterpolationsVerzeichnis::instanz()->fuegeIArtenHinzu("Polynom-Interpolation",new Polynom(),Qt::darkGreen);
    InterpolationsVerzeichnis::instanz()->fuegeIArtenHinzu("kubische Spline-Interpolation",new Spline(),Qt::darkBlue);

    //centrales Widget initialisieren
    widgetCentral = new QWidget(this);

    //Plot initialisieren
    plot = new Interpolationsplot(widgetCentral);
    plot->setMinimumSize(560,480);

    //Titel und Hintergrund einstellen
    setWindowTitle("SEP Interpolation Gruppe 11");
//    QPalette Pal(palette());
//    Pal.setColor(QPalette::Background,Qt::white);
//    widgetCentral->setPalette(Pal);
//    widgetCentral->setAutoFillBackground(true);

    //Buttons initialisieren
    buttonPunktHinzufuegen = new QPushButton("Punkt hinzufügen",widgetCentral);
    buttonAchsenAktualisieren = new QPushButton("Achsen aktualisieren",widgetCentral);
    buttonAllePunkteLoeschen = new QPushButton("Alle Punkte löschen",widgetCentral);
    buttonIArtenAktivieren = new QPushButton(widgetCentral);
    buttonIArtenDeaktivieren = new QPushButton(widgetCentral);
    buttonAlleIArtenAktivieren = new QPushButton(widgetCentral);
    buttonAlleIArtenDeaktivieren = new QPushButton(widgetCentral);
    buttonReset = new QPushButton("Reset",widgetCentral);
    buttonHilfe = new QPushButton("Hilfe",widgetCentral);
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

    listWidgetInaktiveIArten->setMinimumWidth(180);
    listWidgetAktiveIArten->setMinimumWidth(180);
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
    labelListeAktiv = new QLabel("Aktive Interpolationsarten:",widgetCentral);
    labelListeInaktiv = new QLabel("Inaktive Interpolationsarten:",widgetCentral);

    //Ausrichtung der Labels
    labelXMin->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelXMax->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYMin->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYMax->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelXKoord->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    labelYKoord->setAlignment(Qt::AlignVCenter | Qt::AlignRight);

    //Platzhalter initialisieren
    spacerItem = new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding);

    //Box für Fehlermeldungen & Warnungen initialisieren
    msgBox = new QMessageBox(widgetCentral);

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
    subGridLayout->addItem(spacerItem,0,6);

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
    subGridLayout->addWidget(labelListeInaktiv,3,0,1,2);
    subGridLayout->addWidget(labelListeAktiv,3,3,1,2);

    //fünfte Zeile
    subGridLayout->addWidget(listWidgetInaktiveIArten,4,0,4,2);
    subGridLayout->addWidget(buttonIArtenAktivieren,4,2);
    subGridLayout->addWidget(listWidgetAktiveIArten,4,3,4,2);
    subGridLayout->addWidget(buttonAllePunkteLoeschen,4,5);

    //sechste Zeile
    subGridLayout->addWidget(buttonIArtenDeaktivieren,5,2);
    subGridLayout->addWidget(buttonReset,5,5);

    //siebte Zeile
    subGridLayout->addWidget(buttonAlleIArtenAktivieren,6,2);
    subGridLayout->addWidget(buttonHilfe,6,5);

    //achte Zeile
    subGridLayout->addWidget(buttonAlleIArtenDeaktivieren,7,2);
    subGridLayout->addWidget(buttonBeenden,7,5);

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
    connect(buttonHilfe,SIGNAL(clicked(bool)),this,SLOT(hilfeSlot()));
    connect(buttonBeenden,SIGNAL(clicked(bool)),this,SLOT(beendenSlot()));
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

    spinBoxXKoord->setMinimum(MINIMUM);
    spinBoxXKoord->setMaximum(MAXIMUM);
    spinBoxYKoord->setMinimum(MINIMUM);
    spinBoxYKoord->setMaximum(MAXIMUM);

    spinBoxXKoord->setValue(0);
    spinBoxYKoord->setValue(0);

    //Interpolationsarten initialisieren
    listWidgetInaktiveIArten->setSelectionMode(QAbstractItemView::MultiSelection);
    listWidgetAktiveIArten->setSelectionMode(QAbstractItemView::MultiSelection);

    QList<QString> labels = InterpolationsVerzeichnis::instanz()->holeNamen();
    QList<QString>::iterator it=labels.begin();
    for(;it!=labels.end();++it){
        new QListWidgetItem(*it,listWidgetInaktiveIArten);
    }

    buttonIArtenDeaktivieren->setDisabled(true);
    buttonAlleIArtenDeaktivieren->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete widgetCentral;
    if(spacerItem != NULL) delete spacerItem;
    Proxy::loescheIV();
}

void MainWindow::achsenUpdatenSlot(){
    double xMin = spinBoxXMin->value();
    double xMax = spinBoxXMax->value();
    double yMin = spinBoxYMin->value();
    double yMax = spinBoxYMax->value();
    if (xMin >= xMax || yMin >= yMax){
        msgBox->setWindowTitle("Ungueltige Achsenwerte");
        msgBox->setText("Die Werte, die Sie eingegeben haben, ergeben keinen "
                        "gültigen Definitions- bzw Wertebereich. \nMöchten Sie"
                        " die Werte verwerfen oder überarbeiten?");
        QString str = "Sie haben versucht [" + QString().setNum(xMin) + ", "
                + QString().setNum(xMax) + "] als neuen Definitionsbereich und ["
                + QString().setNum(yMin) + ", " + QString().setNum(yMax) + "] als "
                "neuen Wertebereich zu setzen.\n=> Fehler:\n";
        if(xMin >= xMax) str += "\txMin >= xMax\n";
        if(yMin >= yMax) str += "\tyMin >= yMax";
        msgBox->setDetailedText("");
        msgBox->setDetailedText(str);
        msgBox->setIcon(QMessageBox::Critical);
        msgBox->setStandardButtons(QMessageBox::Discard);
        QPushButton * tmpButton = new QPushButton("Überarbeiten");
        msgBox->addButton(tmpButton,QMessageBox::AcceptRole);
        msgBox->setDefaultButton(QMessageBox::Discard);
        int ret = msgBox->exec();
        msgBox->removeButton(tmpButton);
        delete tmpButton;
        if(ret == QMessageBox::AcceptRole) return;
        plot->getRange(xMin,xMax,yMin,yMax);
        spinBoxXMin->setValue(xMin);
        spinBoxXMax->setValue(xMax);
        spinBoxYMin->setValue(yMin);
        spinBoxYMax->setValue(yMax);
        return;
    }
    plot->setRange(xMin,xMax,yMin,yMax);
}

void MainWindow::neuerPunktPerTastaturSlot(){
    double x = spinBoxXKoord->value();
    double y = spinBoxYKoord->value();
    double xMin,xMax,yMin,yMax;
    plot->getRange(xMin,xMax,yMin,yMax);
    if(x < xMin || x > xMax || y < yMin || y > yMax){
        msgBox->setWindowTitle("Punkt nicht im Plot");
        msgBox->setText("Der Punkt, den Sie hinzufügen möchten, liegt "
                        "außerhalb des sichtbaren Koordinatensystems. \n"
                        "Möchten Sie ihn trotzdem hinzufügen, verwerfen"
                        " oder die Koordinaten überarbeiten?");
        QString str= "Sie haben versucht einen Punkt an den folgenden "
                     "Koordinaten hinzuzufügen (" + QString().setNum(x)
                     + ", " + QString().setNum(y) + "). \nDer aktuelle "
                     "Definitionsbereich ist [" + QString().setNum(xMin)
                     + ", " + QString().setNum(xMax) + "]. \nDer aktuelle "
                     "Wertebereich ist [" + QString().setNum(yMin)
                     + ", " + QString().setNum(yMax) + "].\n=> Warnung:\n";
        if(x < xMin) str += "\tx < xMin\n";
        if(x > xMax) str += "\tx > xMax\n";
        if(y < yMin) str += "\ty < yMin\n";
        if(y > yMax) str += "\ty > yMax";
        msgBox->setDetailedText("");
        msgBox->setDetailedText(str);
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->setStandardButtons(QMessageBox::Discard);
        QPushButton * tmpButton = new QPushButton("Hinzufügen");
        QPushButton * tmpButton2 = new QPushButton("Überarbeiten");
        msgBox->addButton(tmpButton,QMessageBox::ApplyRole);
        msgBox->addButton(tmpButton2,QMessageBox::AcceptRole);
        msgBox->setDefaultButton(QMessageBox::Discard);
        int ret = msgBox->exec();
        msgBox->removeButton(tmpButton);
        msgBox->removeButton(tmpButton2);
        delete tmpButton;
        delete tmpButton2;
        if(ret == QMessageBox::AcceptRole) return;
        spinBoxXKoord->setValue(0);
        spinBoxYKoord->setValue(0);
        if(ret == QMessageBox::Discard) return;
        emit plot->plotOnClickEvent(x,y,Qt::LeftButton);
    }
    else {
        spinBoxXKoord->setValue(0);
        spinBoxYKoord->setValue(0);
        emit plot->plotOnClickEvent(x,y,Qt::LeftButton);
    }
}

void MainWindow::resetSlot(){
    while(listWidgetAktiveIArten->count()>0){
        QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(0);
        listWidgetInaktiveIArten->addItem(tmpItem);
    }
    spinBoxXMin->setValue(0);
    spinBoxXMax->setValue(100);
    spinBoxYMin->setValue(0);
    spinBoxYMax->setValue(50);

    spinBoxXKoord->setValue(0);
    spinBoxYKoord->setValue(0);

    buttonIArtenAktivieren->setDisabled(false);
    buttonAlleIArtenAktivieren->setDisabled(false);
    buttonIArtenDeaktivieren->setDisabled(true);
    buttonAlleIArtenDeaktivieren->setDisabled(true);

    plot->reset();
}

void MainWindow::hilfeSlot(){
    msgBox->setWindowTitle("Hilfe");
    msgBox->setText("Diese Programm bietet folgende Funktionalitäten:\n\n"
                    "1. Einen Punkt hinzufügen:\nUm einen Punkt hinzu"
                    "zufügen, klicken Sie entweder mit der linken Maustaste "
                    "an die gewünschte Stelle im Koordinatensystem oder geben "
                    "Sie die Koordinaten über die Felder 'x-Koordinate' und '"
                    "y-Koordinate' ein und bestätigen Sie mit 'Punkt hinzufügen'.\n"
                    "\n2. Einen Punkt löschen:\nUm einen Punkt zu löschen, "
                    "klicken Sie auf den zu löschenden Punkt im Koordinaten"
                    "system.\n\n3. Definitions- und Wertebereich ändern:\nUm den "
                    "Definitions- oder Wertebereich zu ändern, ändern Sie den "
                    "gewünschten Wert in den Feldern 'xMin', 'xMax', 'yMin' oder "
                    "'yMax' und bestätigen Sie mit 'Achsen aktualisieren'.\n\n4. "
                    "Interpolationsarten zu (de-)aktivieren:\nUm Interpolationsarten"
                    "zu (de-)aktivieren, markieren Sie die gewünschten Arten per Maus"
                    "klick in der entsprechenden Liste und drücken Sie den einfachen "
                    "Pfeil, der in Richtung der anderen Liste zeigt. Um alle Interpol"
                    "ationsarten zu (de-)aktivieren, drücken Sie den entsprechenden "
                    "Doppelpfeil.\n\n5. Alle Punkte löschen:\nUm alle Punkte zu "
                    "löschen, drücken Sie 'Alle Punkte löschen'.\n\n6. Das Programm "
                    "zurücksetzen:\nUm das Programm zurückzusetzen, drücken Sie 'Reset"
                    "'.\n\n7. Das Programm beenden:\nUm das Programm zu beenden, "
                    "drücken Sie 'Beenden' und bestätigen Sie mit der 'Enter'-Taste.");
    msgBox->setDetailedText("");
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->setDefaultButton(QMessageBox::Close);
    msgBox->exec();
}

void MainWindow::beendenSlot(){
    msgBox->setWindowTitle("Programm beenden");
    msgBox->setText("Sind Sie sicher, dass Sie das Programm beenden möchten?");
    msgBox->setDetailedText("");
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox->setDefaultButton(QMessageBox::Yes);
    int ret = msgBox->exec();
    if (ret == QMessageBox::Yes) close();
}

void MainWindow::aktiviereIArtenSlot(){
    QList<QListWidgetItem*> changedIArten = listWidgetInaktiveIArten->selectedItems();
    if(changedIArten.size()==0) return;
    while(changedIArten.size()>1){
        double tmpRow = listWidgetInaktiveIArten->row(changedIArten.takeFirst());
        QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(tmpRow);
        listWidgetAktiveIArten->addItem(tmpItem);
        plot->addIArtOhnePlotten(tmpItem->text());
    }
    double tmpRow = listWidgetInaktiveIArten->row(changedIArten.takeFirst());
    QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(tmpRow);
    listWidgetAktiveIArten->addItem(tmpItem);
    plot->addIArt(tmpItem->text());


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
        plot->removeIArtOhnePlotten(tmpItem->text());
    }
    double tmpRow = listWidgetAktiveIArten->row(changedIArten.takeFirst());
    QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(tmpRow);
    listWidgetInaktiveIArten->addItem(tmpItem);
    plot->removeIArt(tmpItem->text());


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
        plot->addIArtOhnePlotten(tmpItem->text());
    }
    QListWidgetItem * tmpItem = listWidgetInaktiveIArten->takeItem(0);
    listWidgetAktiveIArten->addItem(tmpItem);
    plot->addIArt(tmpItem->text());

    buttonIArtenAktivieren->setDisabled(true);
    buttonAlleIArtenAktivieren->setDisabled(true);
    buttonIArtenDeaktivieren->setDisabled(false);
    buttonAlleIArtenDeaktivieren->setDisabled(false);
}

void MainWindow::deaktiviereAlleIArtenSlot(){
    while(listWidgetAktiveIArten->count()>0){
        QListWidgetItem * tmpItem = listWidgetAktiveIArten->takeItem(0);
        listWidgetInaktiveIArten->addItem(tmpItem);
    }

    buttonIArtenAktivieren->setDisabled(false);
    buttonAlleIArtenAktivieren->setDisabled(false);
    buttonIArtenDeaktivieren->setDisabled(true);
    buttonAlleIArtenDeaktivieren->setDisabled(true);

    plot->removeAlleIArten();
}
