#include "futo.h"
#include <cmath>



Futo::Futo(const string &pos) :  Figura(pos)
{

}

bool Futo::lephet(string poz) const
{
    if (poz == getPozicio()) return false;
    int dx = abs(poz[0]-getPozicio()[0]);
    int dy = abs(poz[1]-getPozicio()[1]);
    return dx == dy;
 }

char Futo::jeloles() const
{
    return 'F';
}
