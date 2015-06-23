#include "../Header-Dateien/point.h"

Point::Point(): x(0), y(0){

}

Point::Point(double x, double y): x(x), y(y){

}

Point::Point(const Point & rhs): x(rhs.x), y(rhs.y){

}

Point& Point::operator =(const Point & rhs){
    if(this==&rhs) return (*this);
    x = rhs.x;
    y = rhs.y;
    return (*this);
}

bool Point::operator <(const Point & rhs){
    if(x < rhs.x) return true;
    else if (x == rhs.x && y < rhs.y) return true;
    return false;
}

double Point::getX() const{
    return x;
}

void Point::setX(double x){
    this->x = x;
}

double Point::getY() const{
    return y;
}

void Point::setY(double y){
    this->y = y;
}
