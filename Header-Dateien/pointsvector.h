#ifndef POINTSVECTOR
#define POINTSVECTOR

#include <QVector>
#include "point.h"

namespace custom_types{
class PointsVector : public QVector<Point>{
   public:
    void sort();
    void getPointsAsSeperateVectors(QVector<double> &x, QVector<double> &y);
    int findEqualX(double x);
};

}


#endif // POINTSVECTOR


