#include "..\Header-Dateien\polynom.h"
#include "../Header-Dateien/pointsvector.h"
void Polynom::calculateInterpolation(PointsVector &in,  PointsVector &out,
                                    double xMin, double xMax, int n) {
//    out = in;
//    double Steigung = (in[1].getY()-in[0].getY())/(in[1].getX()-in[0].getX());
//    out.append(Punkt(xMin,in[0].getY()+Steigung*(xMin-in[0].getX())));
//    Steigung = (in[in.size()-1].getY()-in[in.size()-2].getY())/(in[in.size()-1].getX()-in[in.size()-2].getX());
//    out.append(Punkt(xMax,in[in.size()-1].getY()+Steigung*(xMax-in[in.size()-1].getX())));
    int nIn = in.size();
    double coefficients[nIn-1][nIn-1];
    for(int i=0; i < nIn-1; ++i){
        coefficients[i][0] = (in[i].getY()-in[i+1].getY())/(in[i].getX()-in[i+1].getX());
    }
    for(int j=1; j < nIn-1; ++j){
        for(int i=0; i < nIn-1-j; ++i){
            coefficients[i][j] = (coefficients[i][j-1]-coefficients[i+1][j-1])/(in[i].getX()-in[i+j+1].getX());
        }
    }



    //Auswertung mit dem Hornerschema:
    double h = (xMax-xMin)/n;
    out.resize(n+1);
    for(int i=0; i<=n; ++i){
        double tmpX = i*h+xMin;
        double tmpY = coefficients[0][nIn-2];
        for(int j=nIn-3; j>0; --j){
            tmpY = tmpY * (tmpX - in[j].getX()) + coefficients[0][j-1];
        }
        tmpY = tmpY * (tmpX - in[0].getX()) + out[0].getY();
        Point tmpPoint(tmpX,tmpY);
        out[i] = tmpPoint;
    }

}
