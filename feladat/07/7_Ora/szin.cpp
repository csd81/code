#include "szin.h"

Szin::~Szin() {} // virtual destructor

char Szin::szamotHexava(int i){
    if (i>=0 && i<=9) return i+'0';
    else if (i>=10 && i<=15) return i-10+'A';
    else return '0';
}


int Szin::hexatSzamma(char c){
    if (c>='0' && c<='9') return c-'0';
    else if  (c>='A' && c<='F') return c-'A'+10;
            else return 0;
}



string Szin::printCode() const{
    unsigned char r = R();
    unsigned char g = G();
    unsigned char b = B();
    string ertek = "#";

    ertek +=  szamotHexava(r / 16);
    ertek +=  szamotHexava(r % 16);
    ertek +=  szamotHexava(g / 16);
    ertek +=  szamotHexava(g % 16);
    ertek +=  szamotHexava(b / 16);
    ertek +=  szamotHexava(b % 16);
    return ertek;
}



bool Szin::megegyezik(const Szin &sz) const
{ return    (R() == sz.R() &&
            G() == sz.G() &&
            B() == sz.B());
}
