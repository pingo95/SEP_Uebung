#include "../Header-Dateien/interpolationplot.h"

int InterpolationPlot::idCounter = 1;

InterpolationPlot::InterpolationPlot(QWidget * parent): QStcePlot(parent,true),
    errormessageBox(new QMessageBox(this)), epsilon(10){
    //Standard Definitions- und Wertebereich
    setRange(0,100,0,50);
    connect(this,SIGNAL(plotOnClickEvent(double,double,Qt::MouseButton)),this,SLOT(changePointsSlot(double,double,Qt::MouseButton)));
}

InterpolationPlot::~InterpolationPlot(){
    delete errormessageBox;
    QList<IType*>::iterator it = ITypes.values().begin();
        for(;it!=ITypes.values().end();++it) delete (*it);
}

void InterpolationPlot::replot(){
    QVector<double> xIn,yIn;
    for(int i=2; i <= ITypes.count()+1; ++i) setPoints(xIn,yIn,i);
    Points.getPointsAsSeperateVectors(xIn,yIn);
    setKeyPoints(xIn,yIn);
    if(Points.size() > 2){
        int n =1000;
        PointsVector PointsOut;
        QVector<double> xOut, yOut;
        double xMin,xMax,yMin,yMax;
        getRange(xMin,xMax,yMin,yMax);
        QMap<int,IType*> tmpITypes;
        QList<QString>::iterator it = activeITypes.begin();
        for(;it != activeITypes.end(); ++it){
            IType * tmpIType = ITypes[*it];
            tmpITypes.insert(tmpIType->id,tmpIType);
        }
        QList<int> tmpIdList = tmpITypes.keys();
        QList<int>::iterator it2 = tmpIdList.begin();
        for(;it2 != tmpIdList.end(); ++it2){
            PointsOut.clear();
            IType * tmpIType = tmpITypes[*it2];
            tmpIType->algorithm->calculateInterpolation(Points,PointsOut,xMin,xMax,n);
            PointsOut.getPointsAsSeperateVectors(xOut,yOut);
            setPoints(xOut,yOut,tmpIType->id,tmpIType->color);
        }
    }
    QStcePlot::replot();
}

void InterpolationPlot::reset(){
    activeITypes.clear();
    Points.clear();
    setRange(0,100,0,50);
    replot();
}

void InterpolationPlot::addIType(QString name, InterpolationType *algorithm,
                                                Qt::GlobalColor color){
    IType * tmpIType = new IType;
    tmpIType->id = ++InterpolationPlot::idCounter;
    tmpIType->algorithm = algorithm;
    tmpIType->color = color;
    ITypes.insert(name,tmpIType);
    QVector<double> x;
    setPoints(x,x,tmpIType->id,tmpIType->color);
}

QList<QString> InterpolationPlot::getITypesNames(){
    return ITypes.keys();
}

void InterpolationPlot::activateIType(QString type){
    activeITypes.append(type);
    replot();
}

void InterpolationPlot::activateITypeWithoutPlotting(QString type){
    activeITypes.append(type);
}

void InterpolationPlot::deactivateIType(QString type){
    activeITypes.removeOne(type);
    replot();
}

void InterpolationPlot::deactivateITypeWithoutPlotting(QString type){
    activeITypes.removeOne(type);
}

void InterpolationPlot::deactivateAllITypes(){
    activeITypes.clear();
    replot();
}

int InterpolationPlot::findBestMatch(double x, double y){
    double xMin,xMax,yMin,yMax;
    getRange(xMin,xMax,yMin,yMax);
    QSize plotSize = getPlotSize();
    double epsilonX = epsilon * (xMax-xMin)/plotSize.width();
    double epsilonY = epsilon * (yMax-yMin)/plotSize.height();
    double bestMatch=100000;
    int posBestMatch=-1;
    for(int i=0; i < Points.size();++i){
        double diffX=abs(x-Points[i].getX());
        double diffY=abs(y-Points[i].getY());
        double tmp=sqrt(diffX*diffX+diffY*diffY);
        if(diffX <= epsilonX && diffY <= epsilonY && tmp < bestMatch){
            bestMatch = tmp;
            posBestMatch = i;
        }
    }
    return posBestMatch;
}

void InterpolationPlot::changePointsSlot(double x, double y, Qt::MouseButton btn){
    if(btn==Qt::LeftButton){
        int pos = Points.findEqualX(x);
        if(pos != -1){
            errormessageBox->setWindowTitle("Punkt existiert schon");
            errormessageBox->setText("An der x-Position, an der Sie einen Punkt hinzufügen wollen,"
                            " existiert bereits ein Punkt.\n Soll dieser Punkt mit den neuen"
                            " Werten überschrieben werden oder soll der neue Punkt verworfen "
                            "werden?");
            QString str= "Damit korrekte Interpolationen durchgeführt werden können, dürfen keine "
                         "zwei Punkte mit dem gleichen x-Wert existieren. Sie haben versucht einen"
                         " Punkt an den folgenden Koordinaten hinzuzufügen (" + QString().setNum(x)
                         + ", " + QString().setNum(y) + "). Dort existiert aber bereits der Punkt ("
                         + QString().setNum(x) + ", " + QString().setNum(Points[pos].getY()) + ").";
            errormessageBox->setDetailedText("");
            errormessageBox->setDetailedText(str);
            errormessageBox->setIcon(QMessageBox::Warning);
            QPushButton * tmpButton1 = errormessageBox->addButton(QMessageBox::Discard);
            QPushButton * tmpButton2 = new QPushButton("Überschreiben");
            errormessageBox->addButton(tmpButton2,QMessageBox::ApplyRole);
            errormessageBox->setDefaultButton(tmpButton1);
            errormessageBox->exec();
            if(errormessageBox->clickedButton()==tmpButton2) Points[pos].setY(y);
            errormessageBox->removeButton(tmpButton1);
            errormessageBox->removeButton(tmpButton2);
            delete tmpButton1;
            delete tmpButton2;
        }
        else Points.append(Point(x,y));
        Points.sort();
    }else{
        int posBestMatch = findBestMatch(x,y);
        if (posBestMatch != -1){
            Points.remove(posBestMatch);
        }else{
            errormessageBox->setWindowTitle("Punkt nicht gefunden");
            errormessageBox->setText("Es konnte kein Punkt in der Nähe ihres Mausklickes "
                            "gefunden werden.\n Soll in einer größeren Umgebung nach "
                            "einem Punkt gesucht werden oder soll der der Löschvorgang"
                            " abgebrochen werden?");
            QString str= "Sie haben versucht einen Punkt an den folgenden "
                         "Koordinaten zu löschen (" + QString().setNum(x)
                         + ", " + QString().setNum(y) + ").";
            errormessageBox->setDetailedText("");
            errormessageBox->setDetailedText(str);
            errormessageBox->setIcon(QMessageBox::Warning);
            QPushButton * tmpButton1 = errormessageBox->addButton(QMessageBox::Discard);
            QPushButton * tmpButton2 = errormessageBox->addButton(QMessageBox::Retry);
            errormessageBox->setDefaultButton(tmpButton1);
            do{
                epsilon *= 1.5;
                int posBestMatch = findBestMatch(x,y);
                if (posBestMatch != -1){
                    Points.remove(posBestMatch);
                    epsilon = 10;
                    break;
                }
                errormessageBox->exec();
                if(errormessageBox->clickedButton()==tmpButton1){
                    errormessageBox->removeButton(tmpButton1);
                    errormessageBox->removeButton(tmpButton2);
                    delete tmpButton1;
                    delete tmpButton2;
                    return;
                }
            }while(true);
            errormessageBox->removeButton(tmpButton1);
            errormessageBox->removeButton(tmpButton2);
            delete tmpButton1;
            delete tmpButton2;
        }
    }
    replot();
}

void InterpolationPlot::deleteAllPointsSlot(){
    Points.clear();
    replot();
}
