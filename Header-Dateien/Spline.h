#ifndef SPLINE_H
#define SPLINE_H

#include "Interpolationsart.h"
class Spline : public Interpolationsart {


public:
	QList<double> berechneInterpolation(int x, QList<double> y);
};

#endif // SPLINE_H
