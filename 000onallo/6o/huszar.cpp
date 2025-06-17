#include "huszar.h"
#include <cmath>



bool Huszar::lephet(const string &pos) const
{
    int dx = std::abs(pos[0]-pozicio[0]);
    int dy = std::abs(pos[1]-pozicio[1]);
    if(pos==pozicio)
        return false;
    else if((dx==1 && dy==2) ||
        (dx==2 && dy==1))
        return true;
    else
        return false;
}

char Huszar::jeloles() const
{
    return 'H';
}
