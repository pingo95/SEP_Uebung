#include "../Header-Dateien/polynom.h"
#include "../Header-Dateien/pointsvector.h"

void numeric::Polynom::calculateInterpolation(custom_types::PointsVector &in,  custom_types::PointsVector &out,
                                    double xMin, double xMax, int n) {
    int nIn = in.size();
    double coef[nIn-1][nIn-1];
    for (int i=0; i< nIn-1; ++i){
        for(int j=0; j <nIn-1;++j){
            coef[i][j]=0;
        }
    }
    for(int i=0; i < nIn-1; ++i){
        coef[i][0] = (in[i].getY()-in[i+1].getY())/(in[i].getX()-in[i+1].getX());
    }
    for(int j=1; j < nIn-1; ++j){
        for(int i=0; i < nIn-1-j; ++i){
            coef[i][j] = (coef[i][j-1]-coef[i+1][j-1])/(in[i].getX()-in[i+j+1].getX());
        }
    }


    //Auswertung mit dem Hornerschema:
    double h = (xMax-xMin)/n;
    out.resize(n+1);
    for(int i=0; i<=n; ++i){
        double tmpX = i*h+xMin;
        double tmpY = coef[0][nIn-2];
        for(int j=nIn-3; j>=0; --j){
            tmpY = tmpY * (tmpX - in[j+1].getX()) + coef[0][j];

        }
        tmpY = tmpY * (tmpX - in[0].getX()) + in[0].getY();
        custom_types::Point tmpPoint(tmpX,tmpY);
        out[i] = tmpPoint;
    }

}
