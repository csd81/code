#include "pont.h"

#include <cmath>
#include <sstream>
#include <iostream>
#include <fstream>

double Pont::M = 106;

double Pont::getM()
{
    return M;
}

void Pont::setM(double newM)
{
    M = newM;
}

void Pont::figyelmeztetes(const string &uzenet) const
{
    std::cout << uzenet << std::endl;
    std::ofstream fajl("warnings.log", std::ios::app);
    if (fajl.is_open()) {
        fajl << uzenet << std::endl;
    } else {

        std::cerr << "Hiba: nem sikerült megnyitni a warnings.log fájlt!" << std::endl;
    }
}

void Pont::ellenoriz() const
{

    if (std::abs(x) > M || std::abs(y) > M)
    {
        std::ostringstream ossz;
        ossz << "Figyelem: a pont koordinátái (" << x << ", " << y
                  << ") meghaladják az M=" << M << " értéket.\n";
        figyelmeztetes(ossz.str());

    }

}

Pont::Pont(double x, double y):     x(x),     y(y){
    ellenoriz();
}

Pont::Pont():     x(0),     y(0)
{}

Pont::Pont(const Pont &masik) : x(masik.x), y(masik.y) {
    ellenoriz();
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
