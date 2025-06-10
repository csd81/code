#include "szin.h"

Szin::~Szin()
{
}

char Szin::szamotHexava(int i)
{
	if (i>=0 && i<=9) return i+'0'; // 0 és 9 között -> '0' - '9'
	else if (i>=10 && i<=15) return i-10+'A'; // 10 és 15 között -> 'A' - 'F'
	else return '0';
}

int Szin::hexatSzamma(char c)
{
	if (c>='0' && c<='9') return c-'0';
	else if (c>='A' && c<='F') return c-'A'+10;
	else return 0;
}

string Szin::printCode() const
{
	unsigned char r=R(), g=G(), b=B();
	string ertek="#";
	// először átalakítjuk r-t: az első karakter r/16-ból, a második karakter r%16-ból jön
	ertek+=szamotHexava(r/16);
	ertek+=szamotHexava(r%16);
	// majd ugyanez a többire
	ertek+=szamotHexava(g/16);
	ertek+=szamotHexava(g%16);
	ertek+=szamotHexava(b/16);
	ertek+=szamotHexava(b%16);

	return ertek;
}

bool Szin::megegyezik(const Szin &sz) const
{
	return (R()==sz.R() && G()==sz.G() && B()==sz.B());
}
