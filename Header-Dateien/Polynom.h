#ifndef POLYNOM_H
#define POLYNOM_H

#include "interpolationtype.h"

namespace numeric{
/*!
    \brief Polynom implements the numeric algorithm for the polynom interpolation.
*/
class Polynom : public InterpolationType {
public:

    /*!
        \brief Calculates the polynom interpolation based on the given parameters.
        \param in Input vector of points through which will be interpolated
        \param out  Output vector containing all the calculated points
        \param xMin Lower bound of the domain of definition
        \param xMax Upper bound of the domain of definition
        \param n Number of points that will be calculated and returned through out
    */
    void calculateInterpolation(custom_types::PointsVector & in, custom_types::PointsVector & out,
                               double xMin, double xMax, int n);

};

}

#endif //POLYNOM_H
