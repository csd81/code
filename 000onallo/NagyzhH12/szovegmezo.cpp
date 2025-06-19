#include "szovegmezo.h"



string SzovegMezo::getSzoveg() const
{
    return szoveg;
}

void SzovegMezo::setSzoveg(const string &newSzoveg)
{
    if (getSzerkesztheto()==true)
        szoveg = newSzoveg;

}

int SzovegMezo::getMaxhossz() const
{
    return maxhossz;
}

bool SzovegMezo::megfelelo() const
{
    if (szoveg.length() <= (size_t)maxhossz) return true;
    else return false;
}

string SzovegMezo::operator~()
{
    return szoveg;
}



SzovegMezo::SzovegMezo(const string &megnevezes, bool szerkesztheto, int maxhossz) : BeviteliMezo(megnevezes, szerkesztheto),
    szoveg(""), maxhossz(maxhossz)
{}
