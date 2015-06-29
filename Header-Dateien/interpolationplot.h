#ifndef INTERPOLATIONPLOT_H
#define INTERPOLATIONPLOT_H

#include "qstceplot.h"
#include <QList>
#include "interpolationtype.h"
#include <QMessageBox>
#include <QMap>

namespace graphics{
class InterpolationPlot : public graphics::QStcePlot {
    Q_OBJECT

struct IType{
    numeric::InterpolationType * algorithm;
    Qt::GlobalColor color;
};

public:
    InterpolationPlot(QWidget * parent);
    ~InterpolationPlot();

    void reset();
    void addIType(QString name, numeric::InterpolationType * algorithm,
                         Qt::GlobalColor color = Qt::black);
    QList<QString> getITypesNames();
    void activateIType(QString type);
    void activateITypeWithoutPlotting(QString type);
    void deactivateIType(QString type);
    void deactivateITypeWithoutPlotting(QString type);
    void deactivateAllITypes();

private:
    custom_types::PointsVector Points;
    QMap<QString,IType*> ITypes;
    QList<QString> activeITypes;
    int activeITypesCount;
    QMessageBox * errormessageBox;
    int epsilon;

    void replot();
    int findBestMatch(double x, double y);

protected slots:
    void changePointsSlot(double x, double y, Qt::MouseButton btn);
    void deleteAllPointsSlot();
signals:
};

}

#endif // INTERPOLATIONPLOT_H
