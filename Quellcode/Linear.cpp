#include "..\Header-Dateien\linear.h"
#include "../Header-Dateien/customqpunktevektor.h"
void Linear::berechneInterpolation(CustomQPunkteVector &in,  CustomQPunkteVector &out,
                                   double xMin, double xMax, int n){
    out = in;
// Randwerte wollen noch nicht!

//    QVector<double> x,y;
//    in.getPointsAsSortedSeperateVektors(x,y);
//    double Steigung = (y[1]-y[0])/(x[1]-x[0]);
//    out.append(Punkt(xMin,y[0]+Steigung*(xMin-x[0])));
//    Steigung = (y[y.size()-2]-y[y.size()-1])/(x[y.size()-2]-x[y.size()-1]);
//    out.append(Punkt(xMax,y[y.size()-2]+Steigung*(xMin-x[y.size()-2])));

}

