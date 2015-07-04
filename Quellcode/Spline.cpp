#include "../Header-Dateien/Spline.h"
#include "../Header-Dateien/SplineLib.h"
#include "../Header-Dateien/Pointsvector.h"
void numeric::Spline::calculateInterpolation(custom_types::PointsVector &in,  custom_types::PointsVector &out,
                                   double xMin, double xMax, int n) {
    tk::spline s;
    QVector<double> x,y;
    in.getPointsAsSeperateVectors(x,y);
    s.set_points(x.toStdVector(),y.toStdVector());
    double h = (xMax-xMin)/n;
    out.resize(n+1);
    for(int i=0; i<=n; ++i){
        double tmpX = i*h+xMin;
        custom_types::Point tmpPoint(tmpX,s(tmpX));
        out[i] = tmpPoint;
    }
}
