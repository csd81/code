#include "harcos.h"
#include <iostream>

// • Fejtsd ki a Harcos osztályban az ősosztály metódusait az alábbiaknak megfelelően:
// o eletero: a harcos életereje alapból 12, és ez minden egyes szintért 6-tal növekszik,
// o sebzes: a harcos sebzése alapból 5, és ez minden egyes szintért 2-vel növekszik,
// o kiir: megjeleníti az adatokat a minta szerint.

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
