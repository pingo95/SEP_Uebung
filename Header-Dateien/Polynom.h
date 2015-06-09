#ifndef POLYNOM_H
#define POLYNOM_H

#include "Interpolationsart.h"
class Polynom : public Interpolationsart {


public:
	QList<double> berechneInterpolation(int x, QList<double> y);
};

#endif //POLYNOM_H
