#include "ijasz.h"
#include <iostream>

// • Fejtsd ki az Ijasz osztályban az ősosztály metódusait az alábbiaknak megfelelően:
// o eletero: az íjász életereje alapból 10, és ez minden egyes szintért 3-mal növekszik,
// o sebzes: az íjász sebzése alapból 3, és ez minden egyes szintért 2-vel növekszik, azonban,
// ha a karakter pontossága legalább 90, akkor a sebzés duplázódik,
// o kiir: megjeleníti az adatokat a minta szerint.

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
