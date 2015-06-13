#include "..\Header-Dateien\interpolationsplot.h"

Interpolationsplot::Interpolationsplot(QWidget * parent): QStcePlot(parent,true){
    //Standard Definitions- und Wertebereich
    setRange(0,100,0,50);
}

Interpolationsplot::~Interpolationsplot(){

}

void Interpolationsplot::replot(){
    QVector<double> xIn,yIn;
    Punkte.getPointsAsSeperateVektors(xIn,yIn);
    setKeyPoints(xIn,yIn);
    if(Punkte.size()<=2) return;
    int n = round(1. / (100*(xMax-xMin)/((double)plotSize.width())));
    CustomQPunkteVector PunkteOut;
    QVector<double> xOut, yOut;
    QList<Interpolationsart*>::iterator it = aktiveIArten.begin();
    for(int i=1; it != aktiveIArten.end(); ++it, ++i){
        (*it)->berechneInterpolation(Punkte,PunkteOut,xMin,xMax,n);
        PunkteOut.getPointsAsSeperateVektors(xOut,yOut);
        setPoints(xOut,yOut,i,QColor((i % 7)/6.,(i % 37)/36.,(i % 13)/12.,255));
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
        Punkte.removeOne(Punkt(x,y));
    }
    replot();
}

void Interpolationsplot::allePunkteLoeschenSlot(){
    Punkte.clear();
    replot();
}
