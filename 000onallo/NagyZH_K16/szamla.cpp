#include "szamla.h"



string Szamla::getTipus() const
{
    return tipus;
}

string Szamla::getSzamlaszam() const
{
    return szamlaszam;
}

Szamla::Szamla(const string &szamlaszam, int egyenleg) : szamlaszam(szamlaszam),
    egyenleg(egyenleg)

{}

Szamla::~Szamla()
{

}

void Szamla::kiir() const
{
 cout << szamlaszam << " "
    << egyenleg
    << endl;
}
