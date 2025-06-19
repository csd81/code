#include "szin.h"

char Szin::szamotHexava(int szam)
{
    if (szam<10 && szam>=0)
        return '0'+szam;
        else return 'A'+ szam-10;
}

int Szin::hexatSzamma(char hex)
{
    if (hex>='0' && hex<='9')
        return 0+(hex-'0');
        else return 10+(hex-'A');
}

string Szin::printCode() const
{
    string kod = "#";
    kod += szamotHexava(R()/16);
    kod += szamotHexava(R()%16);
    kod += szamotHexava(G()/16);
    kod += szamotHexava(G()%16);
    kod += szamotHexava(B()/16);
    kod += szamotHexava(B()%16);
    return kod;
}

bool Szin::megegyezik(const Szin &masik) const
{
    return R() == masik.R() && G() == masik.G() && B() == masik.B();

}
