#ifndef INTERPOLATIONSPLOT_H
#define INTERPOLATIONSPLOT_H

#include "qstceplot.h"
#include <QList>
#include "interpolationsart.h"
#include <QMessageBox>

class Interpolationsplot : public QStcePlot {
    Q_OBJECT
public:
    Interpolationsplot(QWidget * parent);
    ~Interpolationsplot();

    void replot();
    void reset();
    void addIArt(QString art);
    void addIArtOhnePlotten(QString art);
    void removeIArt(QString art);
    void removeIArtOhnePlotten(QString art);
    void removeAlleIArten();

protected:
private:
    CustomQPunkteVector Punkte;
    QList<QString> aktiveIArten;
    QMessageBox * msgBox;
    int epsilon;

    int findBestMatch(double x, double y);

protected slots:
    void changePunkteSlot(double x, double y, Qt::MouseButton btn);
    void allePunkteLoeschenSlot();
signals:
};

#endif // INTERPOLATIONSPLOT_H
