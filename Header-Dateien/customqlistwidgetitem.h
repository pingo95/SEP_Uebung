#ifndef CUSTOMQLISTWIDGETITEM_H
#define CUSTOMQLISTWIDGETITEM_H

#include <QListWidgetItem>
#include "interpolationsart.h"
class customQListWidgetItem : public QListWidgetItem
{
public:
    customQListWidgetItem(const Interpolationsart * art, const QIcon &icon, const QString &text, QListWidget *view, int type);
    customQListWidgetItem(const Interpolationsart * art, const QString &text, QListWidget *view, int type);
    customQListWidgetItem(const customQListWidgetItem & rhs);

    const Interpolationsart* getIArt();

private:
    const Interpolationsart* art;

    customQListWidgetItem();
};

#endif // CUSTOMQLISTWIDGETITEM_H

