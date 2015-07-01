#include "../Header-Dateien/mainwindow.h"
#include "../Header-Dateien/linear.h"
#include "../Header-Dateien/polynom.h"
#include "../Header-Dateien/spline.h"

graphics::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), MINIMUM(-5000), MAXIMUM(5000)
{
    //centrales Widget initialisieren
    widgetCentral = new QWidget(this);

    //Plot initialisieren
    plot = new graphics::InterpolationPlot(widgetCentral);
    plot->setMinimumSize(560,480);

    //Interpolationsarten hinzufügen
    plot->addIType("Lineare Interpolation",new numeric::Linear(),Qt::red);
    plot->addIType("Polynom-Interpolation",new numeric::Polynom(),Qt::darkGreen);
    plot->addIType("kubische Spline-Interpolation",new numeric::Spline(),Qt::darkBlue);

    //Titel und Hintergrund einstellen
    setWindowTitle("SEP Interpolation Gruppe 11");
//    QPalette Pal(palette());
//    Pal.setColor(QPalette::Background,Qt::white);
//    widgetCentral->setPalette(Pal);
//    widgetCentral->setAutoFillBackground(true);

    //Buttons initialisieren
    buttonAddPoint = new QPushButton("Punkt hinzufügen",widgetCentral);
    buttonUpdateAxes = new QPushButton("Achsen aktualisieren",widgetCentral);
    buttonDeleteAllPoints = new QPushButton("Alle Punkte löschen",widgetCentral);
    buttonActivateITypes = new QPushButton(widgetCentral);
    buttonDeactivateIType = new QPushButton(widgetCentral);
    buttonActivateAllITypes = new QPushButton(widgetCentral);
    buttonDeactivateAllITypes = new QPushButton(widgetCentral);
    buttonReset = new QPushButton("Reset",widgetCentral);
    buttonHelp = new QPushButton("Hilfe",widgetCentral);
    buttonShutDown = new QPushButton("Beenden", widgetCentral);

    //Icons+Groesse
    buttonActivateITypes->setLayoutDirection(Qt::RightToLeft);
    buttonActivateITypes->setIcon(QIcon(":/Icons/right"));
//    buttonIArtenAktivieren->setText("        Aktivieren");
    buttonActivateITypes->setIconSize(QSize(15,15));

    buttonDeactivateIType->setIcon(QIcon(":/Icons/left"));
//    buttonIArtenDeaktivieren->setText("Deaktivieren");
    buttonDeactivateIType->setIconSize(QSize(15,15));

    buttonActivateAllITypes->setLayoutDirection(Qt::RightToLeft);
    buttonActivateAllITypes->setIcon(QIcon(":/Icons/2right"));
//    buttonAlleIArtenAktivieren->setText("   Alle aktivieren");
    buttonActivateAllITypes->setIconSize(QSize(15,15));

    buttonDeactivateAllITypes->setIcon(QIcon(":/Icons/2left"));
//    buttonAlleIArtenDeaktivieren->setText("Alle deaktivieren");
    buttonDeactivateAllITypes->setIconSize(QSize(15,15));

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
    listWidgetActiveITypes = new QListWidget(widgetCentral);
    listWidgetInactiveITypes = new QListWidget(widgetCentral);

    listWidgetInactiveITypes->setMinimumWidth(180);
    listWidgetActiveITypes->setMinimumWidth(180);
    listWidgetInactiveITypes->setMaximumWidth(180);
    listWidgetActiveITypes->setMaximumWidth(180);

    //Label initialisieren
    labelDomainOfDefinition = new QLabel("Definitionsbereich:",widgetCentral);
    labelXMin = new QLabel("xMin",widgetCentral);
    labelXMax = new QLabel("xMax",widgetCentral);
    labelRange = new QLabel("Wertebereich:",widgetCentral);
    labelYMin = new QLabel("yMin",widgetCentral);
    labelYMax = new QLabel("yMax",widgetCentral);
    labelPointPerKeyboard = new QLabel("Punkt per Tastatur:",widgetCentral);
    labelXKoord = new QLabel("x-Koordinate",widgetCentral);
    labelYKoord = new QLabel("y-Koordinate",widgetCentral);
    labelListeActive = new QLabel("Aktive Interpolationsarten:",widgetCentral);
    labelListeInactive = new QLabel("Inaktive Interpolationsarten:",widgetCentral);

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
    messageBox = new QMessageBox(widgetCentral);

    //Layouts initialisieren
    mainLayout = new QVBoxLayout(widgetCentral);
    subGridLayout = new QGridLayout(widgetCentral);
    subHBoxLayout = new QHBoxLayout(widgetCentral);

    mainLayout->addWidget(plot,6);
    mainLayout->addLayout(subGridLayout,0);

    //erste Zeile
    subGridLayout->addWidget(labelDomainOfDefinition,0,0);
    subGridLayout->addWidget(labelXMin,0,1);
    subGridLayout->addWidget(spinBoxXMin,0,2);
    subGridLayout->addWidget(labelXMax,0,3);
    subGridLayout->addWidget(spinBoxXMax,0,4);
    subGridLayout->addWidget(buttonUpdateAxes,0,5,2,1);
    subGridLayout->addItem(spacerItem,0,6);

    //zweite Zeile
    subGridLayout->addWidget(labelRange,1,0);
    subGridLayout->addWidget(labelYMin,1,1);
    subGridLayout->addWidget(spinBoxYMin,1,2);
    subGridLayout->addWidget(labelYMax,1,3);
    subGridLayout->addWidget(spinBoxYMax,1,4);

    //dritte Zeile
    subGridLayout->addWidget(labelPointPerKeyboard,2,0);
    subGridLayout->addWidget(labelXKoord,2,1);
    subGridLayout->addWidget(spinBoxXKoord,2,2);
    subGridLayout->addWidget(labelYKoord,2,3);
    subGridLayout->addWidget(spinBoxYKoord,2,4);
    subGridLayout->addWidget(buttonAddPoint,2,5);

    //vierte Zeile
    subGridLayout->addWidget(labelListeInactive,3,0,1,2);
    subGridLayout->addWidget(labelListeActive,3,3,1,2);

    //fünfte Zeile
    subGridLayout->addWidget(listWidgetInactiveITypes,4,0,4,2);
    subGridLayout->addWidget(buttonActivateITypes,4,2);
    subGridLayout->addWidget(listWidgetActiveITypes,4,3,4,2);
    subGridLayout->addWidget(buttonDeleteAllPoints,4,5);

    //sechste Zeile
    subGridLayout->addWidget(buttonDeactivateIType,5,2);
    subGridLayout->addWidget(buttonReset,5,5);

    //siebte Zeile
    subGridLayout->addWidget(buttonActivateAllITypes,6,2);
    subGridLayout->addWidget(buttonHelp,6,5);

    //achte Zeile
    subGridLayout->addWidget(buttonDeactivateAllITypes,7,2);
    subGridLayout->addWidget(buttonShutDown,7,5);

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
    connect(buttonUpdateAxes,SIGNAL(clicked(bool)),this,SLOT(updateAxesSlot()));
    connect(buttonAddPoint,SIGNAL(clicked(bool)),this,SLOT(newPointPerKeyboardSlot()));
    connect(buttonDeleteAllPoints,SIGNAL(clicked(bool)),plot,SLOT(deleteAllPointsSlot()));
    connect(buttonReset,SIGNAL(clicked(bool)),this,SLOT(resetSlot()));
    connect(buttonHelp,SIGNAL(clicked(bool)),this,SLOT(helpSlot()));
    connect(buttonShutDown,SIGNAL(clicked(bool)),this,SLOT(shutDownSlot()));
    connect(buttonActivateITypes,SIGNAL(clicked(bool)),this,SLOT(activateITypesSlot()));
    connect(buttonDeactivateIType,SIGNAL(clicked(bool)),this,SLOT(deactivateITypesSlot()));
    connect(buttonActivateAllITypes,SIGNAL(clicked(bool)),this,SLOT(activateAllITypesSlot()));
    connect(buttonDeactivateAllITypes,SIGNAL(clicked(bool)),this,SLOT(deactivateAllITypesSlot()));

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
    listWidgetInactiveITypes->setSelectionMode(QAbstractItemView::MultiSelection);
    listWidgetActiveITypes->setSelectionMode(QAbstractItemView::MultiSelection);

    QList<QString> labels = plot->getITypesNames();
    QList<QString>::iterator it=labels.begin();
    for(;it!=labels.end();++it){
        new QListWidgetItem(*it,listWidgetInactiveITypes);
    }

    buttonDeactivateIType->setDisabled(true);
    buttonDeactivateAllITypes->setDisabled(true);
}

graphics::MainWindow::~MainWindow()
{
    delete widgetCentral;
}

void graphics::MainWindow::updateAxesSlot(){
    double xMin = spinBoxXMin->value();
    double xMax = spinBoxXMax->value();
    double yMin = spinBoxYMin->value();
    double yMax = spinBoxYMax->value();
    if (xMin >= xMax || yMin >= yMax){
        messageBox->setWindowTitle("Ungueltige Achsenwerte");
        messageBox->setText("Die Werte, die Sie eingegeben haben, ergeben keinen "
                        "gültigen Definitions- bzw Wertebereich. \nMöchten Sie"
                        " die Werte verwerfen oder überarbeiten?");
        QString str = "Sie haben versucht [" + QString().setNum(xMin) + ", "
                + QString().setNum(xMax) + "] als neuen Definitionsbereich und ["
                + QString().setNum(yMin) + ", " + QString().setNum(yMax) + "] als "
                "neuen Wertebereich zu setzen.\n=> Fehler:\n";
        if(xMin >= xMax) str += "\txMin >= xMax\n";
        if(yMin >= yMax) str += "\tyMin >= yMax";
        messageBox->setDetailedText("");
        messageBox->setDetailedText(str);
        messageBox->setIcon(QMessageBox::Critical);
        QPushButton * tmpButton1 = messageBox->addButton(QMessageBox::Discard);
        QPushButton * tmpButton2 = new QPushButton("Überarbeiten");
        messageBox->addButton(tmpButton2,QMessageBox::AcceptRole);
        messageBox->setDefaultButton(tmpButton1);
        messageBox->exec();
        if(messageBox->clickedButton()==tmpButton1){
            plot->getRange(xMin,xMax,yMin,yMax);
            spinBoxXMin->setValue(xMin);
            spinBoxXMax->setValue(xMax);
            spinBoxYMin->setValue(yMin);
            spinBoxYMax->setValue(yMax);
        }
        messageBox->removeButton(tmpButton1);
        messageBox->removeButton(tmpButton2);
        delete tmpButton1;
        delete tmpButton2;
        return;
    }
    plot->setRange(xMin,xMax,yMin,yMax);
}

void graphics::MainWindow::newPointPerKeyboardSlot(){
    double x = spinBoxXKoord->value();
    double y = spinBoxYKoord->value();
    double xMin,xMax,yMin,yMax;
    plot->getRange(xMin,xMax,yMin,yMax);
    if(x < xMin || x > xMax || y < yMin || y > yMax){
        messageBox->setWindowTitle("Punkt nicht im Plot");
        messageBox->setText("Der Punkt, den Sie hinzufügen möchten, liegt "
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
        messageBox->setDetailedText("");
        messageBox->setDetailedText(str);
        messageBox->setIcon(QMessageBox::Warning);
        QPushButton * tmpButton1 = messageBox->addButton(QMessageBox::Discard);
        QPushButton * tmpButton2 = new QPushButton("Hinzufügen");
        QPushButton * tmpButton3 = new QPushButton("Überarbeiten");
        messageBox->addButton(tmpButton2,QMessageBox::ApplyRole);
        messageBox->addButton(tmpButton3,QMessageBox::AcceptRole);
        messageBox->setDefaultButton(tmpButton1);
        messageBox->exec();
        if(messageBox->clickedButton()!=tmpButton3){
            spinBoxXKoord->setValue(0);
            spinBoxYKoord->setValue(0);
            if(messageBox->clickedButton()==tmpButton2) emit plot->plotOnClickEvent(x,y,Qt::LeftButton);
        }
        messageBox->removeButton(tmpButton1);
        messageBox->removeButton(tmpButton2);
        messageBox->removeButton(tmpButton3);
        delete tmpButton1;
        delete tmpButton2;
        delete tmpButton3;
        return;
    }
    spinBoxXKoord->setValue(0);
    spinBoxYKoord->setValue(0);
    emit plot->plotOnClickEvent(x,y,Qt::LeftButton);
}

void graphics::MainWindow::resetSlot(){
    while(listWidgetActiveITypes->count()>0){
        QListWidgetItem * tmpItem = listWidgetActiveITypes->takeItem(0);
        listWidgetInactiveITypes->addItem(tmpItem);
    }
    spinBoxXMin->setValue(0);
    spinBoxXMax->setValue(100);
    spinBoxYMin->setValue(0);
    spinBoxYMax->setValue(50);

    spinBoxXKoord->setValue(0);
    spinBoxYKoord->setValue(0);

    buttonActivateITypes->setDisabled(false);
    buttonActivateAllITypes->setDisabled(false);
    buttonDeactivateIType->setDisabled(true);
    buttonDeactivateAllITypes->setDisabled(true);

    plot->reset();
}

void graphics::MainWindow::helpSlot(){
    messageBox->setWindowTitle("Hilfe");
    messageBox->setText("Diese Programm bietet folgende Funktionalitäten:\n\n"
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
                    "Interpolationsarten (de-)aktivieren:\nUm Interpolationsarten "
                    "zu (de-)aktivieren, markieren Sie die gewünschten Arten per Maus"
                    "klick in der entsprechenden Liste und drücken Sie den einfachen "
                    "Pfeil, der in Richtung der anderen Liste zeigt. Um alle Interpol"
                    "ationsarten zu (de-)aktivieren, drücken Sie den entsprechenden "
                    "Doppelpfeil.\n\n5. Alle Punkte löschen:\nUm alle Punkte zu "
                    "löschen, drücken Sie 'Alle Punkte löschen'.\n\n6. Das Programm "
                    "zurücksetzen:\nUm das Programm zurückzusetzen, drücken Sie 'Reset"
                    "'.\n\n7. Das Programm beenden:\nUm das Programm zu beenden, "
                    "drücken Sie 'Beenden' und bestätigen Sie mit der 'Enter'-Taste.");
    messageBox->setDetailedText("");
    messageBox->setIcon(QMessageBox::Information);
    QPushButton * tmpButton1 = messageBox->addButton(QMessageBox::Close);
    messageBox->setDefaultButton(tmpButton1);
    messageBox->exec();
    messageBox->removeButton(tmpButton1);
    delete tmpButton1;
}

void graphics::MainWindow::shutDownSlot(){
    messageBox->setWindowTitle("Programm beenden");
    messageBox->setText("Sind Sie sicher, dass Sie das Programm beenden möchten?");
    messageBox->setDetailedText("");
    messageBox->setIcon(QMessageBox::Question);
    QPushButton * tmpButton1 = messageBox->addButton(QMessageBox::Yes);
    QPushButton * tmpButton2 = messageBox->addButton(QMessageBox::No);
    messageBox->setDefaultButton(tmpButton1);
    messageBox->exec();
    if (messageBox->clickedButton()==tmpButton1) close();
    messageBox->removeButton(tmpButton1);
    messageBox->removeButton(tmpButton2);
    delete tmpButton1;
    delete tmpButton2;
}

void graphics::MainWindow::activateITypesSlot(){
    QList<QListWidgetItem*> changedIArten = listWidgetInactiveITypes->selectedItems();
    if(changedIArten.size()==0) return;
    while(changedIArten.size()>1){
        double tmpRow = listWidgetInactiveITypes->row(changedIArten.takeFirst());
        QListWidgetItem * tmpItem = listWidgetInactiveITypes->takeItem(tmpRow);
        listWidgetActiveITypes->addItem(tmpItem);
        plot->activateITypeWithoutPlotting(tmpItem->text());
    }
    double tmpRow = listWidgetInactiveITypes->row(changedIArten.takeFirst());
    QListWidgetItem * tmpItem = listWidgetInactiveITypes->takeItem(tmpRow);
    listWidgetActiveITypes->addItem(tmpItem);
    plot->activateIType(tmpItem->text());


    buttonDeactivateIType->setDisabled(false);
    buttonDeactivateAllITypes->setDisabled(false);
    if(listWidgetInactiveITypes->count()==0){
        buttonActivateITypes->setDisabled(true);
        buttonActivateAllITypes->setDisabled(true);
    }
}

void graphics::MainWindow::deactivateITypesSlot(){
    QList<QListWidgetItem*> changedIArten = listWidgetActiveITypes->selectedItems();
    if(changedIArten.size()==0) return;
    while(changedIArten.size()>1){
        double tmpRow = listWidgetActiveITypes->row(changedIArten.takeFirst());
        QListWidgetItem * tmpItem = listWidgetActiveITypes->takeItem(tmpRow);
        listWidgetInactiveITypes->addItem(tmpItem);
        plot->deactivateITypeWithoutPlotting(tmpItem->text());
    }
    double tmpRow = listWidgetActiveITypes->row(changedIArten.takeFirst());
    QListWidgetItem * tmpItem = listWidgetActiveITypes->takeItem(tmpRow);
    listWidgetInactiveITypes->addItem(tmpItem);
    plot->deactivateIType(tmpItem->text());


    buttonActivateITypes->setDisabled(false);
    buttonActivateAllITypes->setDisabled(false);
    if(listWidgetActiveITypes->count()==0){
        buttonDeactivateIType->setDisabled(true);
        buttonDeactivateAllITypes->setDisabled(true);
    }
}

void graphics::MainWindow::activateAllITypesSlot(){
    while(listWidgetInactiveITypes->count()>1){
        QListWidgetItem * tmpItem = listWidgetInactiveITypes->takeItem(0);
        listWidgetActiveITypes->addItem(tmpItem);
        plot->activateITypeWithoutPlotting(tmpItem->text());
    }
    QListWidgetItem * tmpItem = listWidgetInactiveITypes->takeItem(0);
    listWidgetActiveITypes->addItem(tmpItem);
    plot->activateIType(tmpItem->text());

    buttonActivateITypes->setDisabled(true);
    buttonActivateAllITypes->setDisabled(true);
    buttonDeactivateIType->setDisabled(false);
    buttonDeactivateAllITypes->setDisabled(false);
}

void graphics::MainWindow::deactivateAllITypesSlot(){
    while(listWidgetActiveITypes->count()>0){
        QListWidgetItem * tmpItem = listWidgetActiveITypes->takeItem(0);
        listWidgetInactiveITypes->addItem(tmpItem);
    }

    buttonActivateITypes->setDisabled(false);
    buttonActivateAllITypes->setDisabled(false);
    buttonDeactivateIType->setDisabled(true);
    buttonDeactivateAllITypes->setDisabled(true);

    plot->deactivateAllITypes();
}
