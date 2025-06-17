#include "pont.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

double Pont::M = 106.0;

double Pont::getM()
{
    return M;
}

void Pont::setM(double newM)
{
    M = newM;
}

Pont::Pont():  x(0), y(0)
{}

Pont::Pont(const double x, const double y):
    x(x), y(y)
{
    if  ( abs(x) > M || abs(y) > M ){
        stringstream ss;
        ss << "Figyelem: Pont limiten tul!: " << "(" << x << "," << y << ")" << std::endl;
        cout << ss.str();
        ofstream ofs("warnings.log", std::ios::app);
        if (!ofs) cerr <<"cerr";
        ofs << ss.str();
        ofs.close();
    }
}

Pont::Pont(const Pont &masik) : x(masik.x), y(masik.y)
{
    if  ( abs(x) > M || abs(y) > M ){
        stringstream ss;
        ss << "Figyelem: Pont limiten tul!: " << "(" << x << "," << y << ")" << std::endl;

        cout << ss.str();
        ofstream ofs("warnings.log", std::ios::app);
        if (!ofs) cerr <<"cerr";
        ofs << ss.str();
        ofs.close();
    }
}

Pont &Pont::operator=(const Pont &masik)
{
    if (this != &masik){
        x=masik.x;
        y=masik.y;
        }
    return *this;
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
