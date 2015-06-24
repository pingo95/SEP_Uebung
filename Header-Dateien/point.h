#ifndef POINT
#define POINT
#include <QVector>
class Point{
    friend class QVector<Point>;
public:

    Point(double x, double y);
    Point(const Point & rhs);
    Point& operator=(const Point & rhs);
    bool operator<(const Point & rhs);

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    bool isSet() const;
private:
    Point();
    double x;
    double y;
    bool statusX;
    bool statusY;
};

#endif // POINT

