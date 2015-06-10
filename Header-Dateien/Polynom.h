#ifndef POLYNOM_H
#define POLYNOM_H

#include "interpolationsart.h"
class Polynom : public Interpolationsart {


public:
    void berechneInterpolation(QVector<double>& xIn,  QVector<double>& yIn,
                               QVector<double>& xOut, QVector<double>& yOut);
};

#endif //POLYNOM_H
