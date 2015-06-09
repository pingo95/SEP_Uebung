#ifndef INTERPOLATIONSART_H
#define INTERPOLATIONSART_H

#include <QWidget>
class Interpolationsart : public QWidget {


public:
	virtual QList<double> berechneInterpolation(int x, QList<double> y) = 0;
};

#endif // INTERPOLATIONSART_H
