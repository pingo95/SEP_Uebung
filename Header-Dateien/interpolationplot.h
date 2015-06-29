#ifndef INTERPOLATIONPLOT_H
#define INTERPOLATIONPLOT_H

#include "qstceplot.h"
#include <QList>
#include "interpolationtype.h"
#include <QMessageBox>
#include <QMap>


class InterpolationPlot : public QStcePlot {
    Q_OBJECT

struct IType{
    InterpolationType * algorithm;
    Qt::GlobalColor color;
};

public:
    InterpolationPlot(QWidget * parent);
    ~InterpolationPlot();

    void replot();
    void reset();
    void addIType(QString name, InterpolationType * algorithm,
                         Qt::GlobalColor color = Qt::black);
    QList<QString> getITypesNames();
    void activateIType(QString type);
    void activateITypeWithoutPlotting(QString type);
    void deactivateIType(QString type);
    void deactivateITypeWithoutPlotting(QString type);
    void deactivateAllITypes();

private:
    PointsVector Points;
    QMap<QString,IType*> ITypes;
    QList<QString> activeITypes;
    int activeITypesCount;
    QMessageBox * errormessageBox;
    int epsilon;

    int findBestMatch(double x, double y);

protected slots:
    void changePointsSlot(double x, double y, Qt::MouseButton btn);
    void deleteAllPointsSlot();
signals:
};

#endif // INTERPOLATIONPLOT_H
