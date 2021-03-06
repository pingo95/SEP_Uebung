#ifndef INTERPOLATIONPLOT_H
#define INTERPOLATIONPLOT_H

#include "Qstceplot.h"
#include <QList>
#include "Interpolationtype.h"
#include <QMessageBox>
#include <QMap>

/*!
    \brief graphics contains all the classes dealing with the user interface.
*/
namespace graphics{
/*!
    \brief InterpolationPlot specializes QStcePlot in order to provide functions for interpolation.

    It provides methods for:
    - resetting the graph to its default state
    - adding new interpolation-types
    - returning the names of every added interpolation-type
    - de-/activating interpolation-types with or without calculating and plotting the corresponding graphs
    - adding and deleting single points per mouse click event
    - deleting all points
*/
class InterpolationPlot : public QStcePlot {
    Q_OBJECT

    /*!
        \brief IType provides a simple wrapper for the informations about each interpolation-type.

        The struct consists of twp attributes:
        - algorithm a olymorphic pointer to the object which implements the algorithm for the interpolation-type
        - color a Qt::GlobalColor which will be used to draw the graph for the interpolation-type
    */
    struct IType{
        numeric::InterpolationType * algorithm;
        Qt::GlobalColor color;
    };

public:

    /*!
        \brief Constructor for the InterpolationPlot.
        \param parent Parent widget for the InterpolationPlot

        Sets default range to [0:100]x[0:50], creates graph(0), set up the mouse signal reciever
    */
    InterpolationPlot(QWidget * parent);

    /*!
        \brief Destructor for the InterpolationPlot
    */
    ~InterpolationPlot();

    /*!
        \brief Tests if any point currently in the InterpolationPlot exceeds any of the new boundaries.
        \param xmin new minimal value of the x-axis
        \param xmax new maximal value of the x-axis
        \param ymin new minimal value of the y-axis
        \param ymax new maximal value of the y-axis

        Test function meant to be used before changing the domain of definition and/or the range. Returns a list of the points exceeding any of the new axes (for the details of the warning).
    */
    QList<custom_types::Point> testPointOutOfNewRange(double xmin, double xmax, double ymin, double ymax);

    /*!
        \brief Assigns the visible range of the plot to the passed arguments.
        \param xmin minimal value of the x-axis
        \param xmax maximal value of the x-axis
        \param ymin minimal value of the y-axis
        \param ymax maximal value of the y-axis

        Reimplemenation of QStcePlot::setRange(), forces an InterpolationPlot::replot() instead of a QStcePlot::replot().
    */
    void setRange(double xmin, double xmax, double ymin, double ymax);

    /*!
        \brief Resets the InterpolationPlot to its default state.
    */
    void reset();

    /*!
        \brief Adds a new interpolation-type to the InterpolationPlot.
        \param name Name for the new interpolation-type, will be shown in the UI
        \param algorithm Polymorphic pointer to the object which implements the algorithm for the new interpolation-type
        \param color Qt::GlobalColor which will be used to draw the graph for the new interpolation-type


    */
    void addIType(QString name, numeric::InterpolationType * algorithm,
                         Qt::GlobalColor color = Qt::black);

    /*!
        \brief Returnes the names (as QStrings) of every interpolation-type, that was added to the InterpolationPlot before.

    */
    QList<QString> getITypesNames();

    /*!
        \brief Activates an interpolation-type and forces a replot.
        \param type Name of the type that will be activated

       The interpolation-type named typ must have been added to the InterpolationPlot before, the replot will i.a. calculate the new interpolation and plot its graph.
    */
    void activateIType(QString type);

    /*!
        \brief Activates an interpolation-type without forcing a replot
        \param type Name of the type that will be activated

        The interpolation-type named typ must have been added to the InterpolationPlot before.
    */
    void activateITypeWithoutPlotting(QString type);

    /*!
        \brief Deactivates an interpolation-type and forces a replot.
        \param type Name of the type that will be deactivated

        The interpolation-type named type must have been added to the InterpolationPlot and activated before.
    */
    void deactivateIType(QString type);

    /*!
        \brief Dectivates an interpolation-type without forcing a replot.
        \param type Name of the type that will be deactivated

        The interpolation-type named type must have been added to the InterpolationPlot and activated before.
    */
    void deactivateITypeWithoutPlotting(QString type);

    /*!
        \brief Deactivates all interpolation-types currently active in the InterpolationPlot and forces a replot.


    */
    void deactivateAllITypes();

private:
    custom_types::PointsVector points;
    QMap<QString,IType*> iTypes;
    QList<QString> activeITypes;
    int activeITypesCount;
    QMessageBox * errormessageBox;
    int epsilon;

    /*!
        \brief Replots the graph with the current settings.

        The replotting with the current setting includes:
        - setting the key points
        - clearing already existing graphs
        - for every active interpolation-type:
            - calculating the interpolation
            - plotting the corresponding graph
        - forcing a QStce::replot()
    */
    void replot();

    /*!
        \brief Searches for the nearest point around (x,y).
        \param x x-Value for the start point of the search
        \param y y-Value for the start point of the search

        The search is conducted within a neighbood with a size relativ to the current (widget) size of the InterpolationPlot. If succesfull returnes the position of the best match, otherwise it returnes -1
    */
    int findBestMatch(double x, double y);

public slots:

    /*!
        \brief Adds or removes a point from the InterpolationPlot.
        \param x x-Value for the new Point
        \param y y-Value for the new Point
        \param btn Mouse button which was used to click on the InterpolationPlot


    */
    void changePointsSlot(double x, double y, Qt::MouseButton btn);

    /*!
        \brief Deletes all points from the InterpolationPlot and forces a replot.


    */
    void deleteAllPointsSlot();
signals:
};

}

#endif // INTERPOLATIONPLOT_H
