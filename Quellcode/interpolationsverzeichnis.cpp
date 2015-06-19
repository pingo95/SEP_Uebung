#include "..\Header-Dateien\interpolationsverzeichnis.h"

InterpolationsVerzeichnis* InterpolationsVerzeichnis::_Instanz = 0;

int InterpolationsVerzeichnis::idZaehler = 0;

InterpolationsVerzeichnis::InterpolationsVerzeichnis(){

}

InterpolationsVerzeichnis* InterpolationsVerzeichnis::instanz(){
    if(_Instanz == 0){
        _Instanz = new InterpolationsVerzeichnis();
    }
    return _Instanz;
}

void InterpolationsVerzeichnis::fuegeIArtenHinzu(QString name, Interpolationsart *algorithmus,
                                                Qt::GlobalColor farbe){
    IArt * tmpIArt = new IArt;
    tmpIArt->id = ++InterpolationsVerzeichnis::idZaehler;
    tmpIArt->algorithmus = algorithmus;
    tmpIArt->farbe = farbe;
    IArten[name] = tmpIArt;
}

IArt* InterpolationsVerzeichnis::holeInformationen(QString name){
    return IArten[name];
}

QList<QString> InterpolationsVerzeichnis::holeNamen(){
    return IArten.keys();
}

void InterpolationsVerzeichnis::loescheInstanz(){
    delete _Instanz;
}
