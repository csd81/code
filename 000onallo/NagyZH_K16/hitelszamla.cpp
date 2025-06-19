#include "hitelszamla.h"



HitelSzamla::HitelSzamla(const string &szamlaszam, int egyenleg, int hitelkeret) : Szamla(szamlaszam, egyenleg),
    hitelkeret(hitelkeret)
{
this->tipus="h";
}

bool HitelSzamla::vegrehajt(Tranzakcio & t)
{

    if (!*t) {
        return false; // érvénytelen tranzakció
    }
    if (t.getJovairas()) {
        egyenleg+=t.getOsszeg();
    } else {
        if (egyenleg+hitelkeret-t.getOsszeg()>=0)
            egyenleg-=t.getOsszeg();
    }

    return true;
}

void HitelSzamla::kiir() const
{
        Szamla::kiir();
        cout << hitelkeret;
}
