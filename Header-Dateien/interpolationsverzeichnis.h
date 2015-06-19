#ifndef INTERPOLATIONSVERZEICHNIS_H
#define INTERPOLATIONSVERZEICHNIS_H

#include <QMap>
#include <QString>
#include "interpolationsart.h"

struct IArt{
    int id;
    Interpolationsart * algorithmus;
    Qt::GlobalColor farbe;
};

class InterpolationsVerzeichnis
{
public:
    static InterpolationsVerzeichnis * instanz();
    void fuegeIArtenHinzu(QString name, Interpolationsart * algorithmus,
                         Qt::GlobalColor farbe = Qt::black);
    IArt * holeInformationen(QString name);
    QList<QString> holeNamen();
protected:
    InterpolationsVerzeichnis();
private:
    static InterpolationsVerzeichnis * _Instanz;
    QMap<QString,IArt*> IArten;
    static int idZaehler;
    void loescheInstanz();
    friend class Proxy;
};

class Proxy{
    static void loescheIV(){
        InterpolationsVerzeichnis::instanz()->loescheInstanz();
    }
    friend class MainWindow;
};

#endif // INTERPOLATIONSVERZEICHNIS_H
