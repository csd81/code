#include "szovegesszin.h"

SzovegesSzin::SzovegesSzin(const string &sz):
	szoveg(sz)
{
	if (szoveg=="fekete")
	{
		r=0;
		g=0;
		b=0;
	}
	else if (szoveg=="feher")
	{
		r=255;
		g=255;
		b=255;
	}
	else if (szoveg=="kek")
	{
		r=0;
		g=0;
		b=255;
	}
	else if (szoveg=="zold")
	{
		r=0;
		g=255;
		b=0;
	}
	else if (szoveg=="piros")
	{
		r=255;
		g=0;
		b=0;
	}
	else if (szoveg=="cian")
	{
		r=0;
		g=255;
		b=255;
	}
	else if (szoveg=="magenta")
	{
		r=255;
		g=0;
		b=255;
	}
	else if (szoveg=="sarga")
	{
		r=255;
		g=255;
		b=0;
	}
	else if (szoveg[0]=='#' && szoveg.length()>=7)
	{
		r=hexatSzamma(szoveg[1])*16+hexatSzamma(szoveg[2]);
		g=hexatSzamma(szoveg[3])*16+hexatSzamma(szoveg[4]);
		b=hexatSzamma(szoveg[5])*16+hexatSzamma(szoveg[6]);
	}
	else // a default a fekete
	{
		szoveg="fekete";
		r=0;
		g=0;
		b=0;
	}
}

string SzovegesSzin::printCode() const
{
	return szoveg;
}
