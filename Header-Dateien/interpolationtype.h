#ifndef INTERPOLATIONTYPE_H
#define INTERPOLATIONTYPE_H

#include <QVector>
#include "pointsvector.h"
/*!
    \brief numeric contains all the classes implementing the numerical algorithms.
*/
namespace numeric{
/*!
    \brief InterpolationType provides the abstract interface for all interpolation-types.

    Every interpolation-type class is derived from this class and implements its numeric alogrithm in calculateInterpolation.
*/
class InterpolationType {


public:
    /*!
        \brief Pure virtual function which in the derived classes calculates the interpolation based on the given parameters.
        \param in Input vector of points through which will be interpolated
        \param out  Output vector containing all the calculated points
        \param xMin Lower bound of the domain of definition
        \param xMax Upper bound of the domain of definition
        \param n Number of points that will be calculated and returned through out

        In the derived classes, this function calculates the interpolation function based on the points in the input vector and the algorithm. Then inter/extrapolates n equidistant points between xMin and xMax.
    */
    virtual void calculateInterpolation(custom_types::PointsVector & in, custom_types::PointsVector & out,
                                       double xMin, double xMax, int n) = 0;
    /*!
        \brief Virtual destructor, provided if needed in derived classes.
    */
    virtual ~InterpolationType(){}
};

}

#endif // INTERPOLATIONTYPE_H
