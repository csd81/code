#include "valogatos.h"

string Valogatos::getTipus() const
{
    return tipus;
}

bool Valogatos::vegrehajt(Akcio & a)
{
    if (a.getTipus()==tipus)
        {   this->setPont(pont+a.getErtek());
            return true;
        } else
            return false;
}



Valogatos::Valogatos(const string &nev, int pont, const string &tipus) : Karakter(nev, pont),
    tipus(tipus)
{
this->setTipus("Valogatos");
}
