#include "karakter.h"



string Karakter::getNev() const
{
    return nev;
}

int Karakter::getPont() const
{
    return pont;
}

void Karakter::setPont(int newPont)
{
    pont = newPont;
}

string Karakter::getTipus() const
{
    return tipus;
}

void Karakter::setTipus(const string &newTipus)
{
    tipus = newTipus;
}

Karakter::Karakter(const string &nev, int pont) : nev(nev),
    pont(pont)
{}

Karakter::~Karakter()
{

}
