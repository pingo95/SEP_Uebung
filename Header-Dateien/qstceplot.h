#ifndef Q_STCE_PLOT
#define Q_STCE_PLOT

#include "qcustomplot.h"
#include <QObject>
#include <QVBoxLayout>

class QCustomPlot;
namespace graphics{
/*!
  \brief QStcePlot provides a wrapper for basic functions of <a href="http://www.qcustomplot.com/">QCustomPlot</a> designed for easier usage.

  It provides methods for:
  - setting the key points of the plot ( will be drawn as filled circles)
  - setting line data
  - setting and getting the plot range
  - refreshing the current plot
  - passing of mouse click events
*/
class QStcePlot : public QWidget{
    Q_OBJECT
public:
    /*! \brief Constructor for the QStcePlotWidget

        Sets default range to [0:100]x[0:50], creates graph(0), set up the mouse signal reciever
    */
    QStcePlot(QWidget* q, bool sorted);
    /*!
    \brief assigns the visible range of the plot to the passed arguments
    \param xmin minimal value of the x-axis
    \param ymax maximal value of the x-axis
    \param ymin minimal value of the y-axis
    \param ymax maximal value of the y-axis
    */
    void setRange(double xmin, double xmax, double ymin, double ymax);
    /*!
    \brief assigns the visible range of the plot to the passed arguments
    \param xmin minimal value of the x-axis
    \param ymax maximal value of the x-axis
    \param ymin minimal value of the y-axis
    \param ymax maximal value of the y-axis
    */
    void getRange(double &xmin, double &xmax, double &ymin, double &ymax);

    /*!
    \brief  Sets the key values of the plot. Key values will be plotted as filled blue circles.

            Key points will stay the same until a new set of QVectors is passed.
            The key points correspond to graph(0).
    \param x QVector of x-coordinates for the key values
    \param y corresponding QVector of y-coordinates
    \see QVector
    */
    void setKeyPoints(QVector<double> &x, QVector<double> &y);
    /*!
    \brief  Sets the line-data for graph(graphI). The individual points will be connected using straight lines.

            If no color is given black will be used.
            If the specified graph does not exist yet it (and all graphs up to the specified index) will be created.
            Note that as graph(0) is reserved for the key points graphI must be >= 1
            The plot will be refreshed automatically.

            Unless UNSORTED is defined in the header the points will be sorted automatically by the x-coordinate.
            If you need the lines to be plotted in exactly the specified order define UNSORTED which will slightly
            increase memory usage.

    \param x QVector of x-coordinates for the line
    \param y corresponding QVector of y-coordinates
    \param graphI index of the graph to set, must be >= 1
    \param color  color being used to connect the points, if no color is given Qt::black is used
    \see QVector
    \see QColor
    */    
    void setPoints(QVector<double> &x, QVector<double> &y, int graph, QColor color = QColor(Qt::black));

    /*!
    \brief force the QStcePlot widget to refresh itself
    */    
    void replot();
protected:
    QSize getPlotSize() const;

private:
    QVBoxLayout* layout;
    QCustomPlot* plot;
    QList<QCPItemEllipse> markers;
    double xMin, xMax, yMin, yMax;

protected slots:
    /*!
        recieve the QCustomPlot mouse event convert to plot coordinate system
        and emit plotOnClickEvent
    */
    void mouseClickRecv (QMouseEvent *  event  );
signals:
    /*!
    \brief  Signal which is emmited after some part of the plot has been clicked.

            Has to be connected to a corresponding slot.
            The coorinates returned are already transformed from pixels into the plots coordinate space.
    \param  xVal x-coordinate of the point clicked in coordinate space
    \param  yVal y-coordinate of the point clicked in coordinate space
    \param  btn  Mousebutton which was pressed, e.g. Qt::LeftButton
    \see Qt::MouseButton
    \see signals and slots
    */
    void plotOnClickEvent (double xVal, double yVal, Qt::MouseButton btn);
};

}

#endif
