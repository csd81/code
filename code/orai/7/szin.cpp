#include "szin.h"

char Szin::szamotHexava(int ertek)
{
    // static const string chars="0123456789ABCDEF";
    // return chars[ertek];

    if (ertek<10) return ertek + '0';
    else return 'A' + ertek - 10;
}

int Szin::hexatSzamma(char ch)
{
    if ('0'<=ch && ch<='9') return ch - '0';
    else return ch - 'A' + 10;
}

string Szin::printCode() const
{
    string code = "#";
    code += szamotHexava(R()/16);
    code += szamotHexava(R()%16);
    code += szamotHexava(G()/16);
    code += szamotHexava(G()%16);
    code += szamotHexava(B()/16);
    code += szamotHexava(B()%16);
    return code;
}
