#include "futo.h"



bool Futo::lephet(const string &pos) const
{
    if (pos==pozicio)
        return false;
    else if (abs(pos[0]-pozicio[0]) == abs(pos[1]-pozicio[1]))
        return true;
    else
        return false;
}

char Futo::jeloles() const
{
    return 'F';
}
