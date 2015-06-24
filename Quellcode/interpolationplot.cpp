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
}

void InterpolationPlot::replot(){
    for(int i=0; i<plot->graphCount(); ++i) plot->graph(i)->clearData();
    QVector<double> xIn,yIn;
    Points.getPointsAsSeperateVectors(xIn,yIn);
    setKeyPoints(xIn,yIn);
    if(Points.size() > 2){
        int n =1000;
        PointsVector PointsOut;
        QVector<double> xOut, yOut;
        QList<QString>::iterator it = activeITypes.begin();
        for(; it != activeITypes.end(); ++it){
            PointsOut.clear();
            IType * tmpIType = ITypes[*it];
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
    ITypes[name] = tmpIType;
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
    double epsilonX = epsilon * (xMax-xMin)/plot->size().width();
    double epsilonY = epsilon * (yMax-yMin)/plot->size().height();
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
            errormessageBox->setStandardButtons(QMessageBox::Discard);
            QPushButton * tmpButton = new QPushButton("Überschreiben");
            errormessageBox->addButton(tmpButton,QMessageBox::ApplyRole);
            errormessageBox->setDefaultButton(QMessageBox::Discard);
            int ret = errormessageBox->exec();
            errormessageBox->removeButton(tmpButton);
            delete tmpButton;
            if(ret == QMessageBox::Discard) return;
            Points[pos].setY(y);
        }
        else Points.append(Point(x,y));
        Points.sort();
    }else{
        do{
            int posBestMatch = findBestMatch(x,y);
            if (posBestMatch != -1){
                Points.remove(posBestMatch);
                epsilon = 10;
                break;
            }
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
            errormessageBox->setStandardButtons(QMessageBox::Retry | QMessageBox::Discard);
            errormessageBox->setDefaultButton(QMessageBox::Discard);
            int ret = errormessageBox->exec();
            if(ret == QMessageBox::Discard) return;
            epsilon *= 1.5;
        }while(true);
    }
    replot();
}

void InterpolationPlot::deleteAllPointsSlot(){
    Points.clear();
    replot();
}
