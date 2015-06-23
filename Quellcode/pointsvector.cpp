#include "../Header-Dateien/pointsvector.h"

void PointsVector::getPointsAsSeperateVectors(QVector<double> &x, QVector<double> &y){
    x.clear();
    y.clear();
    for(int i=0; i<this->size(); ++i){
        x.append(this->at(i).getX());
        y.append(this->at(i).getY());
    }
}

void PointsVector::sort(){
    int j;
    for(int i=1; i < size(); ++i){
        Point tmp = (*this)[i];
        for(j=i; j>0 && tmp < (*this)[j-1]; --j){
            (*this)[j] = (*this)[j-1];
        }
        (*this)[j] = tmp;
    }
}

int PointsVector::findEqualX(double x){
    for(int i=0; i < size(); ++i){
        if((*this)[i].getX() == x) return i;
    }
    return -1;
}
