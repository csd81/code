#include "magus.h"



Magus::Magus(const string &nev, int szint, int mana) : Karakter(nev, szint),
    mana(mana)
{}

int Magus::eletero() const
{
    return 8 + 3*getSzint()+ mana/5;
}

int Magus::sebzes() const
{
    return 4 + 2* getSzint() + (mana/10)*3;
}

void Magus::kiir() const
{
    cout << getNev() << ": " << getSzint() << ". szintu magus, mana: " << mana << std::endl;
}
