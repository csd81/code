#ifndef PONT_H
#define PONT_H

#include <iostream>
using namespace std;

class Pont
{
    double x, y;
public:
    Pont(double x, double y);
    double getX () const;
    double getY () const;
    void kiir (ostream& os=std::cout) const;
    static double tavolsag (const Pont& p1, const Pont& p2);
};

#endif // PONT_H
