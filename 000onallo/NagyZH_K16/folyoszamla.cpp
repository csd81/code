#include "folyoszamla.h"


FolyoSzamla::FolyoSzamla(const string &szamlaszam, int egyenleg, const string &nev) : Szamla(szamlaszam, egyenleg),
    nev(nev)
{
this->tipus="f";
}

bool FolyoSzamla::vegrehajt(Tranzakcio & t)
{
    if (!*t) {
        return false; // érvénytelen tranzakció
    }
    if (t.getJovairas()) {
        egyenleg+=t.getOsszeg();
    } else {
        if (egyenleg-t.getOsszeg()>=0)
            egyenleg-=t.getOsszeg();
    }

    return true;
}

void FolyoSzamla::kiir() const
{
        Szamla::kiir();
        cout << nev;
}
