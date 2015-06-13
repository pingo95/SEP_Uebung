#ifndef LINEAR_H
#define LINEAR_H

#include "interpolationsart.h"
class Linear : public Interpolationsart {


public:
    void berechneInterpolation(CustomQPunkteVector & in, CustomQPunkteVector & out,
                               double xMin, double xMax, int n);
};

#endif // LINEAR_H

