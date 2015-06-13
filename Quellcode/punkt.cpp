#include "../Header-Dateien/punkt.h"

Punkt::Punkt(double x, double y): x(x), y(y){

}

Punkt::Punkt(const Punkt & rhs): x(rhs.x), y(rhs.y){

}

Punkt& Punkt::operator=(const Punkt & rhs){
    if(this==&rhs) return (*this);
    x = rhs.x;
    y = rhs.y;
    return (*this);
}

double Punkt::getX(){
    return x;
}

void Punkt::setX(double x){
    this->x = x;
}

double Punkt::getY(){
    return y;
}

void Punkt::setY(double y){
    this->y = y;
}
