#include "..\Header-Dateien\linear.h"
#include "../Header-Dateien/customqpunktevektor.h"
void Linear::berechneInterpolation(CustomQPunkteVector &in,  CustomQPunkteVector &out,
                                   double xMin, double xMax, int n){
    out = in;
    double Steigung = (in[1].getY()-in[1].getY())/(in[1].getX()-in[0].getX());
    out.append(Punkt(xMin,in[0].getY()+Steigung*(xMin-in[0].getX())));
    Steigung = (in[in.size()-1].getY()-in[in.size()-2].getY())/(in[in.size()-1].getX()-in[in.size()-2].getX());
    out.append(Punkt(xMax,in[in.size()-1].getY()+Steigung*(xMax-in[in.size()-1].getX())));

}
