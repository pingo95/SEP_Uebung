#include "..\Header-Dateien\interpolationsplot.h"

Interpolationsplot::Interpolationsplot(QWidget * parent): QStcePlot(parent,true){
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
        Punkte.sort();
        int n = 1000 /*ceil((100*(xMax-xMin)/((double)plot->size().width())))*/;    // relative Wahl von n??
        CustomQPunkteVector PunkteOut;
        QVector<double> xOut, yOut;
        QList<Interpolationsart*>::iterator it = aktiveIArten.begin();
        for(int i=2; it != aktiveIArten.end(); ++it, ++i){
            (*it)->berechneInterpolation(Punkte,PunkteOut,xMin,xMax,n);
            PunkteOut.getPointsAsSeperateVektors(xOut,yOut);
            setPoints(xOut,yOut,i,mapIArtenFarben.value(*it,Qt::black));
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

void Interpolationsplot::addIArt(Interpolationsart *art){
    aktiveIArten.append(art);
    replot();
}

void Interpolationsplot::addIArtOhnePlotten(Interpolationsart *art){
    aktiveIArten.append(art);
}

void Interpolationsplot::removeIArt(Interpolationsart *art){
    aktiveIArten.removeOne(art);
    replot();
}

void Interpolationsplot::removeIArtOhnePlotten(Interpolationsart *art){
    aktiveIArten.removeOne(art);
}

void Interpolationsplot::removeAlleIArten(){
    aktiveIArten.clear();
    replot();
}

void Interpolationsplot::addColor(Interpolationsart *key, Qt::GlobalColor color){
    mapIArtenFarben[key]=color;
}

void Interpolationsplot::changePunkteSlot(double x, double y, Qt::MouseButton btn){
    if(btn==Qt::LeftButton){
        Punkte.append(Punkt(x,y));
    }else{
        double epsilonX = 10 * (xMax-xMin)/plot->size().width();
        double epsilonY = 10 * (yMax-yMin)/plot->size().height();
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
        if(posBestMatch==-1) return;
        Punkte.remove(posBestMatch);
    }
    replot();
}

void Interpolationsplot::allePunkteLoeschenSlot(){
    Punkte.clear();
    replot();
}
