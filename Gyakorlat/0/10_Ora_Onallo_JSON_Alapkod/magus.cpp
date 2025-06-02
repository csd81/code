#include "magus.h"



int Magus::eletero() const
{
    return  8 + 3 * getSzint() + mana/5;
}

int Magus::sebzes() const
{
    return 4 + 2 * getSzint() + 3 * (mana/10);
}

void Magus::kiir() const
{
    cout << getNev() << ": " << getSzint() << ". szintu magus, mana: " << mana << "\n";

}

Magus::Magus(const string &nev, int szint, int mana) : Karakter(nev, szint),
    mana(mana)
{}
