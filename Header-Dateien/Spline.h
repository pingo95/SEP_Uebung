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
    void berechneInterpolation(CustomQPunkteVector & in, CustomQPunkteVector & out,
                               double xMin, double xMax, int n);
};

#endif // SPLINE_H
