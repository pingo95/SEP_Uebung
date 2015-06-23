#include "..\Header-Dateien\spline.h"
#include "../Header-Dateien/splineLib.h"
#include "../Header-Dateien/pointsvector.h"
void Spline::calculateInterpolation(PointsVector &in,  PointsVector &out,
                                   double xMin, double xMax, int n) {
    tk::spline s;
    QVector<double> x,y;
    in.getPointsAsSeperateVectors(x,y);
    s.set_points(x.toStdVector(),y.toStdVector());
    double h = (xMax-xMin)/n;
    out.resize(n+1);
    for(int i=0; i<=n; ++i){
        double tmpX = i*h+xMin;
        Point tmpPoint(tmpX,s(tmpX));
        out[i] = tmpPoint;
    }
}
