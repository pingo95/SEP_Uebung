#ifndef POINT
#define POINT
#include <QVector>

/*!
    \brief Point implements the ADT from chapter 3.2.1 of the development-document.


*/
namespace custom_types{
class Point{
public:

    /*!
        \brief

    */
    Point();

    /*!
        \brief Constructor

    */
    Point(double x, double y);

    /*!
        \brief Copy constructor.
        \param rhs Other point whom will be used to construct the new point.

        Constructs a new point with all the values from rhs including the initialization status.
    */
    Point(const Point & rhs);

    /*!
        \brief Overloaded assignment operator.
        \param rhs Other point whose values will be assigned to the current point.

        Assigns all the values from rhs to the current point including the initialization status.
    */
    Point& operator=(const Point & rhs);

    /*!
        \brief Overloaded comparison operator smaller than.
        \param rhs Other point whom the current point will be compared to.

        Requires both, the current point and rhs, to be initialized. Compares the points only regarding the x-koordinate, i.e. equivalent to getX() < rhs.getX().
    */
    bool operator<(const Point & rhs);

    /*!
        \brief Getter function for the x-koordinate of the point.

        Requires the point to be initialized before.
    */
    double getX() const;

    /*!
        \brief Setter function for the x-koordinate of the point.
        \param x New value for the x-koordinate.

        Also sets the initialization status for the x-koordinate to true.
    */
    void setX(double x);

    /*!
        \brief Getter function for the y-koordinate of the point.

        Requires the point to be initialized before.
    */
    double getY() const;

    /*!
        \brief Setter function for the y-koordinate of the point.
        \param y New value for the y-koordinate.

        Also sets the initialization status for the y-koordinate to true.
    */
    void setY(double y);

    /*!
        \brief Returns the initialization status of the point.

        A point is considered initialized, if both, the x- and y-value, are set, either through the constructer or through the setter functions.
    */
    bool isSet() const;
private:
    double x;
    double y;
    bool statusX;
    bool statusY;
};

}

#endif // POINT

