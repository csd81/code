#include "bastya.h"

Bastya::Bastya(string p): Figura(p) {}

bool Bastya::lephet(const string &pos) const
{
    if (pos==pozicio) return false;
    else if((pos[0]==pozicio[0] && pos[1]<='8' && pos[1]>'0')
    ||  (pos[1]==pozicio[1] && pos[0]<='F' && pos[0]>='A'))
    return true;
    else return false;
}

char Bastya::jeloles() const
{
    return 'B';
}
