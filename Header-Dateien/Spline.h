#ifndef SPLINE_H
#define SPLINE_H

#include "interpolationtype.h"

namespace numeric {
class Spline : public InterpolationType {
public:
    void calculateInterpolation(custom_types::PointsVector & in, custom_types::PointsVector & out,
                               double xMin, double xMax, int n);
};

}

#endif // SPLINE_H
