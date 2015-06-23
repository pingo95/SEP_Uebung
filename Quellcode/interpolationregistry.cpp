#include "..\Header-Dateien\interpolationregistry.h"

InterpolationRegistry* InterpolationRegistry::_Instance = 0;

int InterpolationRegistry::idCounter = 0;

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
}

IType* InterpolationRegistry::getInformations(QString name){
    return ITypes[name];
}

QList<QString> InterpolationRegistry::getNames(){
    return ITypes.keys();
}

void InterpolationRegistry::deleteInstance(){
    delete _Instance;
}
