#ifndef CUSTOMQPUNKTEVEKTOR
#define CUSTOMQPUNKTEVEKTOR


#include <QVector>
#include "punkt.h"
class CustomQPunkteVector : public QVector<Punkt>{
   public:
    void getPointsAsSeperateVektors(QVector<double> &x, QVector<double> &y);
    void getPointsAsSortedSeperateVektors(QVector<double> &x, QVector<double> &y);
};




#endif // CUSTOMQPUNKTEVEKTOR

