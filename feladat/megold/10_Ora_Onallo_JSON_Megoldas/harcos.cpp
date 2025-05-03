#include "harcos.h"
#include <iostream>

Harcos::Harcos(const string &_nev, unsigned int _szint, const string &_fegyver):
	Karakter(_nev,_szint),
	fegyver(_fegyver)
{
}

int Harcos::eletero() const
{
	return 12 + szint*6;
}

int Harcos::sebzes() const
{
	return 5 + szint*2;
}

void Harcos::kiir() const
{
	cout << nev << ": " << szint << ". szintu harcos, fegyver: " << fegyver << endl;
}
