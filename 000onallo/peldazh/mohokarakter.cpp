#include "mohokarakter.h"


int Mohokarakter::darab=0;

int Mohokarakter::getNehezseg() const
{
    return nehezseg;
}

bool Mohokarakter::vegrehajt(Akcio & a)
{
    if(a.getNehezseg()<=nehezseg && a.getErtek()>=5 )
    {
    this->setPont(a.getErtek()+this->getPont());
    return true;
    } else return false;
}

int Mohokarakter::getDarab()
{
    return darab;
}

Mohokarakter::Mohokarakter(const string &nev, int pont, int nehezseg) : Karakter(nev, pont),
    nehezseg(nehezseg)
{
    this->setTipus("Mohokarakter");
}
