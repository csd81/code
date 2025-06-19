#include "szambevitel.h"

int SzamBevitel::getErtek() const
{
    return ertek;
}

void SzamBevitel::kirajzol()
{
    Elem::kirajzol();
    cout << ertek;
}

void SzamBevitel::aktival(int egesz)
{
    ertek+= egesz;
    if (ertek>100) ertek=100;
    if (ertek<-100) ertek=-100;
}

SzamBevitel &SzamBevitel::operator<<(int szam)
{
    if ( szam>=-100 && szam<=100 ){
        ertek=szam;
        return *this;
        }
    else
        return *this;
}

Elem *SzamBevitel::clone() const
{
    return new SzamBevitel(*this);
}

SzamBevitel::SzamBevitel(int x, int y, int szelesseg, int magassag, int ertek) : Elem(x, y, szelesseg, magassag),
    ertek(ertek)
{}
