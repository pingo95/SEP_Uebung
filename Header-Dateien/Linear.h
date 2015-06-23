#ifndef LINEAR_H
#define LINEAR_H

#include "interpolationtype.h"
class Linear : public InterpolationType {


public:
    void calculateInterpolation(PointsVector & in, PointsVector & out,
                               double xMin, double xMax, int n);
};

#endif // LINEAR_H

