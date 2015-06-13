#ifndef INTERPOLATIONSPLOT_H
#define INTERPOLATIONSPLOT_H

#include "qstceplot.h"
#include <QList>
#include "interpolationsart.h"

class Interpolationsplot : public QStcePlot {
    Q_OBJECT
public:
    Interpolationsplot(QWidget * parent);
    ~Interpolationsplot();

    void replot();
    void reset();
    void addIArt(Interpolationsart * art);
    void addIArtOhnePlotten(Interpolationsart *art);
    void removeIArt(Interpolationsart * art);
    void removeIArtOhnePlotten(Interpolationsart *art);
    void removeAlleIArten();
protected:
private:
    CustomQPunkteVector Punkte;
    QList<Interpolationsart*> aktiveIArten;

protected slots:
    void changePunkteSlot(double x, double y, Qt::MouseButton btn);
    void allePunkteLoeschenSlot();
signals:
};

#endif // INTERPOLATIONSPLOT_H
