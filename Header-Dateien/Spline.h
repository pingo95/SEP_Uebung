#ifndef SPLINE_H
#define SPLINE_H

/* Klasse für Spline-Interpolation, Header fertig
 *
 * TODO: Doxygendokumentation
 *
 */


#include "interpolationtype.h"
class Spline : public InterpolationType {


public:
    void calculateInterpolation(PointsVector & in, PointsVector & out,
                               double xMin, double xMax, int n);
};

#endif // SPLINE_H
