#include "karakter.h"



string Karakter::getNev() const
{
    return nev;
}

int Karakter::getSzint() const
{
    return szint;
}

Karakter::Karakter(const string &nev, int szint) : nev(nev),
    szint(szint)
{}

Karakter::~Karakter()
{

}
