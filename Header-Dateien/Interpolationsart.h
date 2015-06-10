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

class Interpolationsart {


public:
    virtual void berechneInterpolation(QVector<double>& xIn,  QVector<double>& yIn,
                                       QVector<double>& xOut, QVector<double>& yOut) = 0;
};

#endif // INTERPOLATIONSART_H
