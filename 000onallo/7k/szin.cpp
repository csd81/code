#include "szin.h"
#include <iostream>
Szin::Szin()
{
    std::cout << "*\n";
}

Szin::~Szin()
{
    std::cout << "~\n";
}

char Szin::szamotHexava(const int& szam)
{
    if (szam >= 0 && szam < 10)
        return '0' + szam;           // '0'..'9'
    else if (szam >= 10 && szam < 16)
        return 'A' + (szam - 10);    // 'A'..'F'
    else
        return '?';
}

int Szin::hexatSzamma(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    else
        return -1;  // hibás karakter esetén jelzés (pl. -1)
}

std::string Szin::printCode() const
{
    std::string s =  "#";
    s+=szamotHexava(R()/16),
    s+=szamotHexava(R()%16);
    s+=szamotHexava(G()/16);
    s+=szamotHexava(G()%16);
    s+=szamotHexava(B()/16);
    s+=szamotHexava(B()%16);
    return s;
}

bool Szin::megegyezik(Szin& sz) const
{
    return (this->R()==sz.R() &&
            this->G()==sz.G() &&
            this->B()==sz.B());
}
