#include "ijasz.h"
#include <iostream>

Ijasz::Ijasz(const string &_nev, unsigned int _szint, unsigned int _pontossag):
	Karakter(_nev, _szint),
	pontossag(_pontossag)
{
}

int Ijasz::eletero() const
{
	return 10 + szint*3;
}

int Ijasz::sebzes() const
{
	int alap = 3 + szint*2;
	if (pontossag>=90) return alap*2;
	else return alap;
}

void Ijasz::kiir() const
{
	cout << nev << ": " << szint << ". szintu ijasz, pontossag: " << pontossag << endl;
}
