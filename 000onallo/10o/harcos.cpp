#include "harcos.h"



int Harcos::eletero() const
{
    return   12 + 6 * getSzint();

}

int Harcos::sebzes() const
{
    return   5 + 2 * getSzint();
}

void Harcos::kiir() const
{
    cout << getNev() << ": " << getSzint() << ". szintu harcos, fegyver: " << fegyver << std::endl;
}

Harcos::Harcos(const string &nev, int szint, string fegyver) : Karakter(nev, szint), fegyver(fegyver)
{}
