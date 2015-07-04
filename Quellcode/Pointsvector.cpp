#include "../Header-Dateien/Pointsvector.h"

void custom_types::PointsVector::getPointsAsSeperateVectors(QVector<double> &x, QVector<double> &y){
    x.clear();
    y.clear();
    for(int i=0; i<this->size(); ++i){
        x.append(this->at(i).getX());
        y.append(this->at(i).getY());
    }
}

void custom_types::PointsVector::sort(){
    int j;
    for(int i=1; i < size(); ++i){
        custom_types::Point tmp = (*this)[i];
        for(j=i; j>0 && tmp < (*this)[j-1]; --j){
            (*this)[j] = (*this)[j-1];
        }
        (*this)[j] = tmp;
    }
}

int custom_types::PointsVector::findEqualX(double x){
    for(int i=0; i < size(); ++i){
        if((*this)[i].getX() == x) return i;
        if((*this)[i].getX() > x ) return -1;
    }
    return -1;
}
