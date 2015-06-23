#include "..\Header-Dateien\linear.h"
#include "../Header-Dateien/pointsvector.h"
void Linear::calculateInterpolation(PointsVector &in,  PointsVector &out,
                                   double xMin, double xMax, int n){
    out = in;
    double slope = (in[1].getY()-in[0].getY())/(in[1].getX()-in[0].getX());
    out.append(Point(xMin,in[0].getY()+slope*(xMin-in[0].getX())));
    slope = (in[in.size()-1].getY()-in[in.size()-2].getY())/(in[in.size()-1].getX()-in[in.size()-2].getX());
    out.append(Point(xMax,in[in.size()-1].getY()+slope*(xMax-in[in.size()-1].getX())));
}

