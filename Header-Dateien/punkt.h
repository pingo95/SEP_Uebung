#ifndef PUNKT
#define PUNKT
#include <QVector>
class Punkt{
    friend class QVector<Punkt>;
public:

    Punkt(double x, double y);
    Punkt(const Punkt & rhs);
    Punkt& operator=(const Punkt & rhs);
    bool operator==(const Punkt & rhs);
    bool operator<(const Punkt & rhs);

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);

private:
    Punkt();
    double x;
    double y;
};

#endif // PUNKT

