#ifndef PUNKT
#define PUNKT
class Punkt{
public:
    Punkt();
    Punkt(double x, double y);
    Punkt(const Punkt & rhs);
    Punkt& operator=(const Punkt & rhs);
    bool operator==(const Punkt & rhs);

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);

private:
    double x;
    double y;
};

#endif // PUNKT

