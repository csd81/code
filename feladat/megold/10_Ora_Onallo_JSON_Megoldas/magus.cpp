#include "magus.h"
#include <iostream>

Magus::Magus(const string &_nev, unsigned int _szint, unsigned int _mana):
	Karakter(_nev, _szint),
	mana(_mana)
{
}

int Magus::eletero() const
{
	return 8 + szint*3 + mana/5;
}

int Magus::sebzes() const
{
	return 4 + szint*2 + (mana/10)*3;
}

void Magus::kiir() const
{
	cout << nev << ": " << szint << ". szintu magus, mana: " << mana << endl;
}
