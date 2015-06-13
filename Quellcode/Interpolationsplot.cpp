#include "..\Header-Dateien\interpolationsplot.h"

Interpolationsplot::Interpolationsplot(QWidget * parent): QStcePlot(parent,true){
    //Standard Definitions- und Wertebereich
    setRange(0,100,0,50);
    connect(this,SIGNAL(plotOnClickEvent(double,double,Qt::MouseButton)),this,SLOT(changePunkteSlot(double,double,Qt::MouseButton)));
}

Interpolationsplot::~Interpolationsplot(){

}

void Interpolationsplot::replot(){
    QVector<double> xIn,yIn;
    Punkte.getPointsAsSeperateVektors(xIn,yIn);
    setKeyPoints(xIn,yIn);
    if(Punkte.size()<=2) return;
    int n = round(1. / (100*(xMax-xMin)/((double)plot->size().width())));
    CustomQPunkteVector PunkteOut;
    QVector<double> xOut, yOut;
    QList<Interpolationsart*>::iterator it = aktiveIArten.begin();
    for(int i=1; it != aktiveIArten.end(); ++it, ++i){
        (*it)->berechneInterpolation(Punkte,PunkteOut,xMin,xMax,n);
        PunkteOut.getPointsAsSeperateVektors(xOut,yOut);
        setPoints(xOut,yOut,i,QColor((10*i)%255,(20*i)%255,(30*i)%255,255));
    }
    //QStcePlot::replot(); called implicit by setPoints(...)
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
}

void Interpolationsplot::removeAlleIArt(){
    aktiveIArten.clear();
    replot();
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
