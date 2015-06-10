#ifndef SPLINE_H
#define SPLINE_H

/* Klasse für Spline-Interpolation, Header fertig
 *
 * TODO: Doxygendokumentation
 *
 */


#include "interpolationsart.h"
class Spline : public Interpolationsart {


public:
    void berechneInterpolation(QVector<double>& xIn,  QVector<double>& yIn,
                               QVector<double>& xOut, QVector<double>& yOut);
};

#endif // SPLINE_H
