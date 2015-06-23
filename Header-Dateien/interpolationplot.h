#ifndef INTERPOLATIONPLOT_H
#define INTERPOLATIONPLOT_H

#include "qstceplot.h"
#include <QList>
#include "interpolationtype.h"
#include <QMessageBox>

class InterpolationPlot : public QStcePlot {
    Q_OBJECT
public:
    InterpolationPlot(QWidget * parent);
    ~InterpolationPlot();

    void replot();
    void reset();
    void addIType(QString type);
    void addITypeWithoutPlotting(QString type);
    void removeIType(QString type);
    void removeITypeWithoutPlotting(QString type);
    void removeAllITypes();

protected:
private:
    PointsVector Points;
    QList<QString> activeITypes;
    QMessageBox * errormessageBox;
    int epsilon;

    int findBestMatch(double x, double y);

protected slots:
    void changePointsSlot(double x, double y, Qt::MouseButton btn);
    void deleteAllPointsSlot();
signals:
};

#endif // INTERPOLATIONPLOT_H
