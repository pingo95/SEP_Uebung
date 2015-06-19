#ifndef CUSTOMQPUNKTEVEKTOR
#define CUSTOMQPUNKTEVEKTOR


#include <QVector>
#include "punkt.h"
class CustomQPunkteVector : public QVector<Punkt>{
   public:
    void sort();
    void getPointsAsSeperateVektors(QVector<double> &x, QVector<double> &y);
    int findEqualX(double x);
};




#endif // CUSTOMQPUNKTEVEKTOR

