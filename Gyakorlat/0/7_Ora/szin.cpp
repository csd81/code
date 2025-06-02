#include "szin.h"

string Szin::printCode() const
{
    ostringstream oss;
    oss << "#" << hex << uppercase << setfill('0')
        << setw(2)  << (int)R()
        << setw(2)  << (int)G()
        << setw(2)  << (int)B();
    return oss.str();
}

bool Szin::megegyezik(const Szin &masik) const
{
    return R() == masik.R() &&
            G() == masik.G() &&
           B() == masik.B();
}

char Szin::szamotHexava(int szam)
{
    if (szam >=0 && szam <= 9) return '0' + szam;
    return 'A' + (szam - 10);

}

int Szin::hexatSzamma(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    return toupper(c) - 'A' + 10;
}
