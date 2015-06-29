#ifndef POLYNOM_H
#define POLYNOM_H

#include "interpolationtype.h"

namespace numeric{
class Polynom : public InterpolationType {
public:
    void calculateInterpolation(custom_types::PointsVector & in, custom_types::PointsVector & out,
                               double xMin, double xMax, int n);

};

}

#endif //POLYNOM_H
