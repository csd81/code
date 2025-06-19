#include "elem.h"




int Elem::getX() const
{
    return x;
}

int Elem::getY() const
{
    return y;
}

int Elem::getSzelesseg() const
{
    return szelesseg;
}

int Elem::getMagassag() const
{
    return magassag;
}

void Elem::kirajzol()
{
    cout << x << y <<
    szelesseg << magassag << endl;
}

Elem::Elem(int x, int y, int szelesseg, int magassag) : x(x),
    y(y),
    szelesseg(szelesseg),
    magassag(magassag)
{}

Elem::~Elem()
{

}
