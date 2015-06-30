#ifndef POINT
#define POINT

/*!
    \brief custom_types contains the two classe providing the datatypes used by the classes in graphics and numeric.
*/
namespace custom_types{
/*!
    \brief Point implements the datatype for 2D cartesian coordinates system points with a x- and a y-value.

    It provides:
    - constructor, copy-constructor and assignment operator
    - getter and setter functions for the coordinates
    - comparison operator smaller than
    - a initialization status function
*/
class Point{
public:

    /*!
        \brief Standard constructor for Point.

        Constructs a new Point without initial values for the coordinates and sets the initialization status to false. Mainly implemented for the resize() function from PointsVector, i.e. for effiency.
    */
    Point();

    /*!
        \brief Constructor for Point
        \param x Initial x value for the new Point.
        \param y Initial y value for the new Point.

        The new Point is constructed with initial values x and y, and its initialization status is set to true.
    */
    Point(double x, double y);

    /*!
        \brief Copy constructor.
        \param rhs Other Point whom will be used to construct the new Point.

        Constructs a new Point with all the values from rhs including the initialization status.
    */
    Point(const Point & rhs);

    /*!
        \brief Overloaded assignment operator.
        \param rhs Other Point whose values will be assigned to the current Point.

        Assigns all the values from rhs to the current Point including the initialization status.
    */
    Point& operator=(const Point & rhs);

    /*!
        \brief Overloaded comparison operator smaller than.
        \param rhs Other Point whom the current Point will be compared to.

        Requires both, the current Point and rhs, to be initialized. Compares the Points only regarding the x-koordinate, i.e. equivalent to getX() < rhs.getX().
    */
    bool operator<(const Point & rhs);

    /*!
        \brief Getter function for the x-coordinate of the Point.

        Requires the Point to be initialized before.
    */
    double getX() const;

    /*!
        \brief Setter function for the x-koordinate of the Point.
        \param x New value for the x-koordinate.

        Also sets the initialization status for the x-koordinate to true.
    */
    void setX(double x);

    /*!
        \brief Getter function for the y-koordinate of the Point.

        Requires the Point to be initialized before.
    */
    double getY() const;

    /*!
        \brief Setter function for the y-koordinate of the Point.
        \param y New value for the y-koordinate.

        Also sets the initialization status for the y-koordinate to true.
    */
    void setY(double y);

    /*!
        \brief Returns the initialization status of the Point.

        A Point is considered initialized, if both, the x- and y-value, are set, either through the constructer or through the setter functions.
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

