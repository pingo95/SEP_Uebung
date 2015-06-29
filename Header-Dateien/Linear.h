#ifndef LINEAR_H
#define LINEAR_H

#include "interpolationtype.h"

namespace numeric{
class Linear : public InterpolationType {
public:
    void calculateInterpolation(custom_types::PointsVector & in, custom_types::PointsVector & out,
                               double xMin, double xMax, int n);
};

}

#endif // LINEAR_H

