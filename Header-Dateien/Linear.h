#ifndef LINEAR_H
#define LINEAR_H

#include "interpolationsart.h"
class Linear : public Interpolationsart {


public:
    void berechneInterpolation(QVector<double>& xIn,  QVector<double>& yIn,
                               QVector<double>& xOut, QVector<double>& yOut);
};

#endif // LINEAR_H

