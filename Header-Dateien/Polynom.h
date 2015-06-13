#ifndef POLYNOM_H
#define POLYNOM_H

#include "interpolationsart.h"
class Polynom : public Interpolationsart {


public:
    void berechneInterpolation(CustomQPunkteVector & in, CustomQPunkteVector & out,
                               double xMin, double xMax, int n);
};

#endif //POLYNOM_H
