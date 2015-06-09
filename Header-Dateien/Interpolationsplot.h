#ifndef INTERPOLATIONSPLOT_H
#define INTERPOLATIONSPLOT_H

#include "qstceplot.h"
#include <QList>
#include <QLabel>


class Interpolationsplot : public QStcePlot {

private:
	QList<QLabel*> aktiveInterpolationen;
	QList<double> xPos;
	QList<double> yPos;

private:
	void reset();

	void replotSlot();

public:
	void addInterpolationsartSlot(QLabel* art);

    Interpolationsplot(QWidget* parent);

	void removeInterpolationsartSlot(QLabel* art);

	void changePuntkeSlot(double x, double y, Qt::MouseButton btn);

	void allePunktLoeschenSlot();
};

#endif // INTERPOLATIONSPLOT_H
