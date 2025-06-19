#include "szoveg.h"

string Szoveg::getSzoveg() const
{
    return szooveg;
}

int Szoveg::getBetumeret() const
{
    return betumeret;
}

void Szoveg::megjelenit() const
{
    if (getLathato())
        cout << "Szoveg: " << szooveg << ", szin: " << getSzin() << ", betumeret: " << betumeret << endl;
    else
        cout << "----------------------" << endl;
}


Szoveg&  Szoveg::operator=(const string& st){
    this->szooveg = st;
    return *this;
}
Szoveg::Szoveg(const string &szooveg, int betumeret, const string &szin, bool lathato) : AdatMegjelenito(szin, lathato),
    szooveg(szooveg),
    betumeret(betumeret)
{
if (getLathato()==true)
    setLathatocount(3);

else
    setLathatocount(2);
}
