#ifndef LINEAR_H
#define LINEAR_H

#include "Interpolationsart.h"
class Linear : public Interpolationsart {


public:
	QList<double> berechneInterpolation(int x, QList<double> y);
};

#endif // LINEAR_H
