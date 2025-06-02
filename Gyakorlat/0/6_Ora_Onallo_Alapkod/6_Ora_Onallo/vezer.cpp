#include "vezer.h"
#include <cmath>

Vezer::Vezer(const string &pos) : Figura(pos)
{

}

bool Vezer::lephet(string poz) const
{
    if (poz == getPozicio()) return false;
    int dx = abs(poz[0] - getPozicio()[0]);
    int dy = abs(poz[1] - getPozicio()[1]);
    return (dy == 0 || dx == 0 || dy ==  dx);
}

char Vezer::jeloles() const
{
    return 'V';
}
