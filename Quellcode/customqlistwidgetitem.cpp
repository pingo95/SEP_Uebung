#include "../Header-Dateien/customqlistwidgetitem.h"

customQListWidgetItem::customQListWidgetItem(const Interpolationsart * art, const QIcon &icon, const QString &text, QListWidget *view, int type) :
    QListWidgetItem(icon,text,view,type), art(art){

}

customQListWidgetItem::customQListWidgetItem(const Interpolationsart * art, const QString &text, QListWidget *view, int type):
    QListWidgetItem(text,view,type),art(art){

}

customQListWidgetItem::customQListWidgetItem(const customQListWidgetItem & rhs): QListWidgetItem(rhs),art(rhs.art){

}

const Interpolationsart* customQListWidgetItem::getIArt(){
    return art;
}


