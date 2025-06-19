#include "karakter.h"



std::string Karakter::getNev() const
{
    return nev;
}

int Karakter::getSzint() const
{
    return szint;
}

Karakter::Karakter(std::string nev, int szint) : nev(nev), szint(szint)
{

}

Karakter::~Karakter()
{

}
