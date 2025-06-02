#include "huszar.h"
#include <cmath>



Huszar::Huszar(const string &pos) : Figura(pos)
{

}

bool Huszar::lephet(string poz) const
{
    if (poz == getPozicio()) return false;
    int dx = abs(poz[0] - getPozicio()[0]);
    int dy = abs(poz[1] - getPozicio()[1]);
    return (dx == 2 && dy ==1) || (dx == 1 && dy ==2);
}

char Huszar::jeloles() const
{
     return 'H';
}
