#ifndef INTERPOLATIONTYPE_H
#define INTERPOLATIONTYPE_H

/* Abstracte Basisklasse für die Interpolationsarten, stellt keinerlei
 * Funktionalität bereit -> es fehlt nur noch
 *
 * TODO: Doxygendokumentation
 *
 * QWIDGET: Eventl wird diese Klasse von QWidget abgeleitet, hängt davon ab
 * wie wir die I-Arten in das UI integrieren.
 *
 * */
#include <QVector>
#include "pointsvector.h"
class InterpolationType {


public:
    virtual void calculateInterpolation(PointsVector & in, PointsVector & out,
                                       double xMin, double xMax, int n) = 0;
    virtual ~InterpolationType(){}
};

#endif // INTERPOLATIONTYPE_H
