#ifndef INTERPOLATIONSART_H
#define INTERPOLATIONSART_H

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
#include "customqpunktevektor.h"
class Interpolationsart {


public:
    virtual void berechneInterpolation(CustomQPunkteVector & in, CustomQPunkteVector & out,
                                       double xMin, double xMax, int n) = 0;
    virtual ~Interpolationsart(){}
};

#endif // INTERPOLATIONSART_H
