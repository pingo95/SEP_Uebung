#include "../Header-Dateien/point.h"
#include <cassert>

Point::Point(): x(0), y(0),
    statusX(false), statusY(false){

}

Point::Point(double x, double y): x(x), y(y),
    statusX(true), statusY(true){

}

Point::Point(const Point & rhs): x(rhs.x), y(rhs.y),
    statusX(rhs.statusX), statusY(rhs.statusY){

}

Point& Point::operator =(const Point & rhs){
    if(this==&rhs) return (*this);
    x = rhs.x;
    y = rhs.y;
    statusX = rhs.statusX;
    statusY = rhs.statusY;
    return (*this);
}

bool Point::operator <(const Point & rhs){
    if(x < rhs.x) return true;
    else if (x == rhs.x && y < rhs.y) return true;
    return false;
}

double Point::getX() const{
    assert(isSet());
    return x;
}

void Point::setX(double x){
    this->x = x;
    statusX = true;
}

double Point::getY() const{
    assert(isSet());
    return y;
}

void Point::setY(double y){
    this->y = y;
    statusY = true;
}

bool Point::isSet() const{
    return statusX && statusY;
}
