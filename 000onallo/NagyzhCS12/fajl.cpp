#include "fajl.h"



std::string Fajl::getNev() const
{
    return nev;
}

int Fajl::getMeret() const
{
    return meret;
}

int Fajl::getFontos() const
{
    return fontossag;
}

void Fajl::setFontos(int newFontossag)
{
    fontossag = newFontossag;
}

Fajl::Fajl(const std::string &nev, int meret, int fontossag) : nev(nev),
    meret(meret),
    fontossag(fontossag)
{}

Fajl::~Fajl()
{

}
