#include "harcos.h"




Harcos::Harcos(const string &nev, int szint, const string &fegyver) : Karakter(nev, szint),
    fegyver(fegyver)
{}

int Harcos::eletero() const
{
    return 12 + 6 * getSzint();
}

int Harcos::sebzes() const
{
    return 5 + 2 * getSzint();
}

void Harcos::kiir() const
{
    cout << getNev() << ": "<< getSzint() <<". szintu harcos, fegyver: "<< fegyver <<"\n";
}
