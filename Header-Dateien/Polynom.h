#ifndef POLYNOM_H
#define POLYNOM_H

#include "interpolationtype.h"
class Polynom : public InterpolationType {


public:
    void calculateInterpolation(PointsVector & in, PointsVector & out,
                               double xMin, double xMax, int n);
};

#endif //POLYNOM_H
