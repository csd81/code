#include "ijasz.h"



Ijasz::Ijasz(const string &nev, int szint, int pontossag) : Karakter(nev, szint), pontossag(pontossag)
{}

int Ijasz::eletero() const
{
    return 10 + 3*getSzint();
}

int Ijasz::sebzes() const
{
    int szorzo=1;
        if (pontossag >=90) szorzo =2;
    return szorzo*(3+ 2*getSzint());
}

void Ijasz::kiir() const
{
    cout << getNev() << ": " << getSzint() << ". szintu ijasz, pontossag: " << pontossag << std::endl;
}
