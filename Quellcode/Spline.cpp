#include "..\Header-Dateien\spline.h"
#include "../Header-Dateien/splineLib.h"
#include "../Header-Dateien/customqpunktevektor.h"
void Spline::berechneInterpolation(CustomQPunkteVector &in,  CustomQPunkteVector &out,
                                   double xMin, double xMax, int n) {
    tk::spline s;
    QVector<double> x,y;
    in.getPointsAsSeperateVektors(x,y);
    s.set_points(x.toStdVector(),y.toStdVector());
    double h = (xMax-xMin)/n;
    out.resize(n+1);
    for(int i=0; i<=n; ++i){
        double tmpX = i*h+xMin;
        Punkt tmpPunkt(tmpX,s(tmpX));
        out[i] = tmpPunkt;
    }
}
