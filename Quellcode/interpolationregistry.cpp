#include "../Header-Dateien/interpolationregistry.h"
#include <iostream>
#include <QColor>

InterpolationRegistry* InterpolationRegistry::_Instance = 0;

int InterpolationRegistry::idCounter = 1;

InterpolationRegistry::InterpolationRegistry(){

}

InterpolationRegistry* InterpolationRegistry::instance(){
    if(_Instance == 0){
        _Instance = new InterpolationRegistry();
    }
    return _Instance;
}

void InterpolationRegistry::addIType(QString name, InterpolationType *algorithm,
                                                Qt::GlobalColor color){
    IType * tmpIType = new IType;
    tmpIType->id = ++InterpolationRegistry::idCounter;
    tmpIType->algorithm = algorithm;
    tmpIType->color = color;
    ITypes[name] = tmpIType;
    std::cout << "ID: " << tmpIType->id << "\t Farbe: " << QColor(tmpIType->color).name().toStdString() << std::endl;
}

IType* InterpolationRegistry::getInformations(QString name){
    return ITypes[name];
}

QList<QString> InterpolationRegistry::getNames(){
    return ITypes.keys();
}

InterpolationRegistry::~InterpolationRegistry(){
    QList<IType*>::iterator it = ITypes.values().begin();
    for(;it!=ITypes.values().end();++it) delete (*it);
}

void InterpolationRegistry::deleteInstance(){
    delete _Instance;
}
