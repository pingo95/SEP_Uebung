#ifndef PUNKT
#define PUNKT
class Punkt{
public:
    Punkt(double x, double y);
    Punkt(const Punkt & rhs);
    Punkt& operator=(const Punkt & rhs);

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

private:
    double x;
    double y;

    Punkt();
};

#endif // PUNKT

