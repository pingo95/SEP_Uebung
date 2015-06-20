#ifndef CUSTOMQPUNKTEVEKTOR
#define CUSTOMQPUNKTEVEKTOR


#include <QVector>
#include "punkt.h"
class CustomQPunkteVector : public QVector<Punkt>{
   public:
    void sortieren();
    void getPointsAsSeperateVektors(QVector<double> &x, QVector<double> &y);
    int findeGleichesX(double x);
};




#endif // CUSTOMQPUNKTEVEKTOR

