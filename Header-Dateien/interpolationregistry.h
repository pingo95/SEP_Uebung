#ifndef INTERPOLATIONREGISTRY_H
#define INTERPOLATIONREGISTRY_H

#include <QMap>
#include <QString>
#include "interpolationtype.h"

struct IType{
    int id;
    InterpolationType * algorithm;
    Qt::GlobalColor color;
};

class InterpolationRegistry
{
public:
    static InterpolationRegistry * instance();
    void addIType(QString name, InterpolationType * algorithm,
                         Qt::GlobalColor color = Qt::black);
    IType * getInformations(QString name);
    QList<QString> getNames();
protected:
    InterpolationRegistry();
private:
    static InterpolationRegistry * _Instance;
    QMap<QString,IType*> ITypes;
    static int idCounter;
    void deleteInstance();
    friend class Proxy;
};

class Proxy{
    static void deleteInstance(){
        InterpolationRegistry::instance()->deleteInstance();
    }
    friend class MainWindow;
};

#endif // INTERPOLATIONREGISTRY_H
