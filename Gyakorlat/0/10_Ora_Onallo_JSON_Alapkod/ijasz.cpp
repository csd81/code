#include "ijasz.h"



int Ijasz::eletero() const
{
    return 10 + (3 * getSzint());
}

int Ijasz::sebzes() const
{
    if (pontossag >= 90)
        return 6 + 4 * getSzint();
    return 3 + 2 * getSzint();
}

void Ijasz::kiir() const
{
    cout << getNev()<<": "<<getSzint() <<". szintu ijasz, pontossag: " << pontossag<<"\n";
}

Ijasz::Ijasz(const string &nev, int szint, int pontossag) : Karakter(nev, szint),
    pontossag(pontossag)
{}
