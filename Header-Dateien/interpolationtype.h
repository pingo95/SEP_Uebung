#ifndef INTERPOLATIONTYPE_H
#define INTERPOLATIONTYPE_H

#include <QVector>
#include "pointsvector.h"

namespace numeric{
class InterpolationType {


public:
    virtual void calculateInterpolation(custom_types::PointsVector & in, custom_types::PointsVector & out,
                                       double xMin, double xMax, int n) = 0;
    virtual ~InterpolationType(){}
};

}

#endif // INTERPOLATIONTYPE_H
