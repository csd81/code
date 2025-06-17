#ifndef PONT_H
#define PONT_H

#include <iostream>
using namespace std;

class Pont
{
    double x, y;
    static double M;
public:
    Pont();
    Pont(const double x, const double y);
    Pont(const Pont& masik);
    Pont& operator=(const Pont& masik);

    double getX () const;
    double getY () const;
    void kiir (ostream& os=std::cout) const;
    static double tavolsag (const Pont& p1, const Pont& p2);
    static double getM();
    static void setM(double newM);
};

#endif // PONT_H
