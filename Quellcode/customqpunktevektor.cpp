#include "../Header-Dateien/customqpunktevektor.h"

void CustomQPunkteVector::getPointsAsSeperateVektors(QVector<double> &x, QVector<double> &y){
    for(int i=0; i<this->size(); ++i){
        x.append(this->at(i).getX());
        y.append(this->at(i).getY());
    }
}

void CustomQPunkteVector::sort(){
    int j;
    for(int i=1; i < size(); ++i){
        Punkt tmp = (*this)[i];
        for(j=i; j>0 && tmp < (*this)[j-1]; --j){
            (*this)[j] = (*this)[j-1];
        }
        (*this)[j] = tmp;
    }
}

//void CustomQPunkteVector::getPointsAsSortedSeperateVektors(QVector<double> &x, QVector<double> &y){
//    CustomQPunkteVector tmpVektor=*this;
//    int n = tmpVektor.size();
//    x.resize(n);
//    y.resize(n);
//    for(int k=0; k<n; ++k){
//        double min=tmpVektor[0].getX();
//        int min_id=0;
//        for(int i=0; i<tmpVektor.size(); ++i){
//            if(tmpVektor[i].getX()<min){
//                min = tmpVektor[i].getX();
//                min_id = i;
//            }
//        }
//        Punkt tmpPunkt = tmpVektor.takeAt(min_id);
//        x[k] = tmpPunkt.getX();
//        y[k] = tmpPunkt.getY();
//    }
//}
