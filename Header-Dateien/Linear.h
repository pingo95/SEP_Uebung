#ifndef LINEAR_H
#define LINEAR_H

#include "interpolationtype.h"

namespace numeric{
/*!
    \brief Linear implements the numeric algorithm for the linear interpolation.
*/
class Linear : public InterpolationType {
public:

    /*!
        \brief Calculates the linear interpolation based on the given parameters.
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

#endif // LINEAR_H

