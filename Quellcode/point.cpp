#include "../Header-Dateien/point.h"
#include <cassert>

custom_types::Point::Point(): x(0), y(0),
    statusX(false), statusY(false){

}

custom_types::Point::Point(double x, double y): x(x), y(y),
    statusX(true), statusY(true){

}

custom_types::Point::Point(const Point & rhs): x(rhs.x), y(rhs.y),
    statusX(rhs.statusX), statusY(rhs.statusY){

}

custom_types::Point& custom_types::Point::operator =(const custom_types::Point & rhs){
    if(this==&rhs) return (*this);
    x = rhs.x;
    y = rhs.y;
    statusX = rhs.statusX;
    statusY = rhs.statusY;
    return (*this);
}

bool custom_types::Point::operator <(const custom_types::Point & rhs){
    if(x < rhs.x) return true;
    else if (x == rhs.x && y < rhs.y) return true;
    return false;
}

double custom_types::Point::getX() const{
    assert(isSet());
    return x;
}

void custom_types::Point::setX(double x){
    this->x = x;
    statusX = true;
}

double custom_types::Point::getY() const{
    assert(isSet());
    return y;
}

void custom_types::Point::setY(double y){
    this->y = y;
    statusY = true;
}

bool custom_types::Point::isSet() const{
    return statusX && statusY;
}
