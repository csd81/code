#include "pont.h"

#include <cmath>

Pont::Pont(double x, double y):
    x(x),
    y(y)
{
}

double Pont::getX() const
{
    return x;
}

double Pont::getY() const
{
    return y;
}

void Pont::kiir(ostream &os) const
{
    os << "(" << x << "," << y << ")";
}

double Pont::tavolsag(const Pont &p1, const Pont &p2)
{
    double xdiff = p1.x-p2.x;
    double ydiff = p1.y-p2.y;
    return std::sqrt(xdiff*xdiff + ydiff*ydiff);
}
