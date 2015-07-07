#include "../Header-Dateien/Interpolationplot.h"

graphics::InterpolationPlot::InterpolationPlot(QWidget * parent): graphics::QStcePlot(parent,true),
    activeITypesCount(0), errormessageBox(new QMessageBox(this)), epsilon(10){
    //Standard Definitions- und Wertebereich
    setRange(0,100,0,50);
    connect(this,SIGNAL(plotOnClickEvent(double,double,Qt::MouseButton)),this,SLOT(changePointsSlot(double,double,Qt::MouseButton)));
}

graphics::InterpolationPlot::~InterpolationPlot(){
    delete errormessageBox;
    QList<IType*> toBeDeletedITypes = iTypes.values();
    QList<IType*>::iterator it = toBeDeletedITypes.begin();
    for(;it!=toBeDeletedITypes.end();++it) delete (*it);
}

QList<custom_types::Point> graphics::InterpolationPlot::testPointOutOfNewRange(double xmin, double xmax, double ymin, double ymax){
    QList<custom_types::Point> exteriorPoints;
    int i=0,j=points.size()-1;
    for(;i<points.size()&&points[i].getX()<xmin;++i) exteriorPoints.append(points[i]);
    for(;j>0&&points[j].getX()>xmax;--j) exteriorPoints.append(points[j]);
    for(;i<=j;++i) if(points[i].getY() < ymin || points[i].getY() > ymax) exteriorPoints.append(points[i]);
    return exteriorPoints;
}

void graphics::InterpolationPlot::setRange(double xmin, double xmax, double ymin, double ymax){
    QStcePlot::setRange(xmin,xmax,ymin,ymax);
    replot();
}

void graphics::InterpolationPlot::reset(){
    activeITypes.clear();
    points.clear();
    QStcePlot::setRange(0,100,0,50);
    replot();
}

void graphics::InterpolationPlot::addIType(QString name, numeric::InterpolationType *algorithm,
                                                Qt::GlobalColor color){
    IType * tmpIType = new IType;
    tmpIType->algorithm = algorithm;
    tmpIType->color = color;
    iTypes.insert(name,tmpIType);
}

QList<QString> graphics::InterpolationPlot::getITypesNames(){
    return iTypes.keys();
}

void graphics::InterpolationPlot::activateIType(QString type){
    activeITypes.append(type);
    replot();
}

void graphics::InterpolationPlot::activateITypeWithoutPlotting(QString type){
    activeITypes.append(type);
}

void graphics::InterpolationPlot::deactivateIType(QString type){
    activeITypes.removeOne(type);
    replot();
}

void graphics::InterpolationPlot::deactivateITypeWithoutPlotting(QString type){
    activeITypes.removeOne(type);
}

void graphics::InterpolationPlot::deactivateAllITypes(){
    activeITypes.clear();
    replot();
}

void graphics::InterpolationPlot::replot(){
    QVector<double> xIn,yIn;
    points.getPointsAsSeperateVectors(xIn,yIn);
    setKeyPoints(xIn,yIn);
    int i=1;
    if(points.size() > 2){
        int n =1000;
        custom_types::PointsVector PointsOut;
        QVector<double> xOut, yOut;
        double xMin,xMax,yMin,yMax;
        getRange(xMin,xMax,yMin,yMax);
        QList<QString>::iterator it = activeITypes.begin();
        for(;it != activeITypes.end(); ++it){
            PointsOut.clear();
            IType * tmpIType = iTypes[*it];
            tmpIType->algorithm->calculateInterpolation(points,PointsOut,xMin,xMax,n);
            PointsOut.getPointsAsSeperateVectors(xOut,yOut);
            setPoints(xOut,yOut,i,tmpIType->color);
            ++i;
        }
    }
    int oldActiveITypesCount = activeITypesCount;
    activeITypesCount = i-1;
    xIn.clear();
    yIn.clear();
    for(; i <= oldActiveITypesCount; ++i) setPoints(xIn,yIn,i);
    graphics::QStcePlot::replot();
}

int graphics::InterpolationPlot::findBestMatch(double x, double y){
    double xMin,xMax,yMin,yMax;
    getRange(xMin,xMax,yMin,yMax);
    QSize plotSize = getPlotSize();
    double epsilonX = epsilon * (xMax-xMin)/plotSize.width();
    double epsilonY = epsilon * (yMax-yMin)/plotSize.height();
    double bestMatch=100000;
    int posBestMatch=-1;
    for(int i=0; i < points.size();++i){
        double diffX=abs(x-points[i].getX());
        double diffY=abs(y-points[i].getY());
        double tmp=sqrt(diffX*diffX+diffY*diffY);
        if(diffX <= epsilonX && diffY <= epsilonY && tmp < bestMatch){
            bestMatch = tmp;
            posBestMatch = i;
        }
    }
    return posBestMatch;
}

void graphics::InterpolationPlot::changePointsSlot(double x, double y, Qt::MouseButton btn){
    if(btn==Qt::LeftButton){
        int pos = points.findEqualX(x);
        if(pos != -1){
            errormessageBox->setWindowTitle("Punkt existiert schon");
            errormessageBox->setText("An der x-Position, an der Sie einen Punkt hinzufügen wollen,"
                            " existiert bereits ein Punkt.\nSoll dieser Punkt mit den neuen"
                            " Werten überschrieben werden oder soll der neue Punkt verworfen "
                            "werden?");
            QString str= "Damit korrekte Interpolationen durchgeführt werden können, dürfen keine "
                         "zwei Punkte mit dem gleichen x-Wert existieren. Sie haben versucht einen"
                         " Punkt an den folgenden Koordinaten hinzuzufügen (" + QString().setNum(x)
                         + ", " + QString().setNum(y) + "). Dort existiert aber bereits der Punkt ("
                         + QString().setNum(x) + ", " + QString().setNum(points[pos].getY()) + ").";
            errormessageBox->setDetailedText("");
            errormessageBox->setDetailedText(str);
            errormessageBox->setIcon(QMessageBox::Warning);
            QPushButton * tmpButton1 = errormessageBox->addButton(QMessageBox::Discard);
            QPushButton * tmpButton2 = new QPushButton("Überschreiben");
            errormessageBox->addButton(tmpButton2,QMessageBox::ApplyRole);
            errormessageBox->setDefaultButton(tmpButton1);
            errormessageBox->exec();
            if(errormessageBox->clickedButton()==tmpButton2) points[pos].setY(y);
            errormessageBox->removeButton(tmpButton1);
            errormessageBox->removeButton(tmpButton2);
            delete tmpButton1;
            delete tmpButton2;
        }
        else{
            points.append(custom_types::Point(x,y));
            points.sort();
        }
    }else{
        int posBestMatch = findBestMatch(x,y);
        if (posBestMatch != -1){
            points.remove(posBestMatch);
        }else{
            errormessageBox->setWindowTitle("Punkt nicht gefunden");
            errormessageBox->setText("Es konnte kein Punkt in der Nähe ihres Mausklickes "
                            "gefunden werden.\nSoll in einer größeren Umgebung nach "
                            "einem Punkt gesucht werden oder soll der Löschvorgang"
                            " abgebrochen werden?");
            QString str= "Sie haben versucht einen Punkt an den folgenden "
                         "Koordinaten zu löschen (" + QString().setNum(x)
                         + ", " + QString().setNum(y) + ").";
            errormessageBox->setDetailedText("");
            errormessageBox->setIcon(QMessageBox::Warning);
            QPushButton * tmpButton1 = new QPushButton("Abbrechen");
            errormessageBox->addButton(tmpButton1,QMessageBox::DestructiveRole);
            QPushButton * tmpButton2 = errormessageBox->addButton(QMessageBox::Retry);
            errormessageBox->setDefaultButton(tmpButton1);
            QString str2 = str + "\nAktueller Radius: " + QString().setNum(epsilon) + " Pixel.";
            errormessageBox->setDetailedText(str2);
            errormessageBox->exec();
            if(errormessageBox->clickedButton()==tmpButton1){
                errormessageBox->removeButton(tmpButton1);
                errormessageBox->removeButton(tmpButton2);
                delete tmpButton1;
                delete tmpButton2;
                return;
            }
            do{
                epsilon *= 1.5;
                int posBestMatch = findBestMatch(x,y);
                if (posBestMatch != -1){
                    points.remove(posBestMatch);
                    epsilon = 10;
                    break;
                }
                str2 = str + "\nAktueller Radius: " + QString().setNum(epsilon) + " Pixel.";
                errormessageBox->setDetailedText(str2);
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

void graphics::InterpolationPlot::deleteAllPointsSlot(){
    points.clear();
    replot();
}
