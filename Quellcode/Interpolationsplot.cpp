#include "..\Header-Dateien\interpolationsplot.h"
#include "../Header-Dateien/interpolationsverzeichnis.h"

Interpolationsplot::Interpolationsplot(QWidget * parent): QStcePlot(parent,true),
    msgBox(new QMessageBox(this)), epsilon(10){
    //Standard Definitions- und Wertebereich
    setRange(0,100,0,50);
    connect(this,SIGNAL(plotOnClickEvent(double,double,Qt::MouseButton)),this,SLOT(changePunkteSlot(double,double,Qt::MouseButton)));
}

Interpolationsplot::~Interpolationsplot(){

}

void Interpolationsplot::replot(){
    for(int i=0; i<plot->graphCount(); ++i) plot->graph(i)->clearData();
    QVector<double> xIn,yIn;
    Punkte.getPointsAsSeperateVektors(xIn,yIn);
    setKeyPoints(xIn,yIn);
    if(Punkte.size() > 2){
//        Punkte.sort();
        int n =1000 /*ceil(xMax-xMin/(((100*(xMax-xMin)/((double)plot->size().width())))))*/;    // relative Wahl von n??
        CustomQPunkteVector PunkteOut;
        QVector<double> xOut, yOut;
        QList<QString>::iterator it = aktiveIArten.begin();
        for(int i=2; it != aktiveIArten.end(); ++it, ++i){
            PunkteOut.clear();
            IArt * tmpIArt = InterpolationsVerzeichnis::instanz()->holeInformationen(*it);
            tmpIArt->algorithmus->berechneInterpolation(Punkte,PunkteOut,xMin,xMax,n);
            PunkteOut.getPointsAsSeperateVektors(xOut,yOut);
            setPoints(xOut,yOut,tmpIArt->id,tmpIArt->farbe);
        }
    }
    QStcePlot::replot();
}

void Interpolationsplot::reset(){
    aktiveIArten.clear();
    Punkte.clear();
    setRange(0,100,0,50);
    replot();
}

void Interpolationsplot::addIArt(QString art){
    aktiveIArten.append(art);
    replot();
}

void Interpolationsplot::addIArtOhnePlotten(QString art){
    aktiveIArten.append(art);
}

void Interpolationsplot::removeIArt(QString art){
    aktiveIArten.removeOne(art);
    replot();
}

void Interpolationsplot::removeIArtOhnePlotten(QString art){
    aktiveIArten.removeOne(art);
}

void Interpolationsplot::removeAlleIArten(){
    aktiveIArten.clear();
    replot();
}

int Interpolationsplot::findBestMatch(double x, double y){
    double epsilonX = epsilon * (xMax-xMin)/plot->size().width();
    double epsilonY = epsilon * (yMax-yMin)/plot->size().height();
    double bestMatch=100000;
    int posBestMatch=-1;
    for(int i=0; i < Punkte.size();++i){
        double diffX=abs(x-Punkte[i].getX());
        double diffY=abs(y-Punkte[i].getY());
        double tmp=sqrt(diffX*diffX+diffY*diffY);
        if(diffX <= epsilonX && diffY <= epsilonY && tmp < bestMatch){
            bestMatch = tmp;
            posBestMatch = i;
        }
    }
    return posBestMatch;
}

void Interpolationsplot::changePunkteSlot(double x, double y, Qt::MouseButton btn){
    if(btn==Qt::LeftButton){
        int pos = Punkte.findEqualX(x);
        if(pos != -1){
            msgBox->setWindowTitle("Punkt existiert schon");
            msgBox->setText("An der x-Position, an der Sie einen Punkt hinzufügen wollen,"
                            " existiert bereits ein Punkt.\n Soll dieser Punkt mit den neuen"
                            " Werten überschrieben werden oder soll der neue Punkt verworfen "
                            "werden?");
            QString str= "Damit korrekte Interpolationen durchgeführt werden können, dürfen keine "
                         "zwei Punkte mit dem gleichen x-Wert existieren. Sie haben versucht einen"
                         " Punkt an den folgenden Koordinaten hinzuzufügen (" + QString().setNum(x)
                         + ", " + QString().setNum(y) + "). Dort existiert aber bereits der Punkt ("
                         + QString().setNum(x) + ", " + QString().setNum(Punkte[pos].getY()) + ").";
            msgBox->setDetailedText("");
            msgBox->setDetailedText(str);
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setStandardButtons(QMessageBox::Apply | QMessageBox::Discard);
            msgBox->setDefaultButton(QMessageBox::Discard);
            int ret = msgBox->exec();
            if(ret == QMessageBox::Discard) return;
            Punkte[pos].setY(y);
        }
        else Punkte.append(Punkt(x,y));
        Punkte.sort();
    }else{
        do{
            int posBestMatch = findBestMatch(x,y);
            if (posBestMatch != -1){
                Punkte.remove(posBestMatch);
                epsilon = 10;
                break;
            }
            msgBox->setWindowTitle("Punkt nicht gefunden");
            msgBox->setText("Es konnte kein Punkt in der Nähe ihres Mausklickes "
                            "gefunden werden.\n Soll in einer größeren Umgebung nach "
                            "einem Punkt gesucht werden oder soll der der Löschvorgang"
                            " abgebrochen werden?");
            QString str= "Sie haben versucht einen Punkt an den folgenden "
                         "Koordinaten zu löschen (" + QString().setNum(x)
                         + ", " + QString().setNum(y) + ").";
            msgBox->setDetailedText("");
            msgBox->setDetailedText(str);
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setStandardButtons(QMessageBox::Retry | QMessageBox::Discard);
            msgBox->setDefaultButton(QMessageBox::Discard);
            int ret = msgBox->exec();
            if(ret == QMessageBox::Discard) return;
            epsilon *= 1.5;
        }while(true);
    }
    replot();
}

void Interpolationsplot::allePunkteLoeschenSlot(){
    Punkte.clear();
    replot();
}
