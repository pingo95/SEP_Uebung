#include "../Header-Dateien/punkt.h"

Punkt::Punkt(): x(0), y(0){

}

Punkt::Punkt(double x, double y): x(x), y(y){

}

Punkt::Punkt(const Punkt & rhs): x(rhs.x), y(rhs.y){

}

Punkt& Punkt::operator =(const Punkt & rhs){
    if(this==&rhs) return (*this);
    x = rhs.x;
    y = rhs.y;
    return (*this);
}

bool Punkt::operator ==(const Punkt & rhs){
    if(x==rhs.x&&y==rhs.y) return true;
    return false;
}

bool Punkt::operator <(const Punkt & rhs){
    if(x < rhs.x) return true;
    else if (x == rhs.x && y < rhs.y) return true;
    return false;
}

double Punkt::getX() const{
    return x;
}

void Punkt::setX(double x){
    this->x = x;
}

double Punkt::getY() const{
    return y;
}

void Punkt::setY(double y){
    this->y = y;
}
