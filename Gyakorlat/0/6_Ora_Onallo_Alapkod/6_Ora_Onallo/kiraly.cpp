#include "kiraly.h"



bool Kiraly::lephet(string poz) const
{
    if (((poz[0]==this->getPozicio()[0]-1)
        ||(poz[0]==this->getPozicio()[0]+1))
        &&((poz[1]==this->getPozicio()[1]-1)||(poz[1]==this->getPozicio()[1]+1)))
        return true;
    return false;
}

char Kiraly::jeloles() const
{
    return 'K';
}

Kiraly::Kiraly(const string &pos) : Figura(pos)
{}
