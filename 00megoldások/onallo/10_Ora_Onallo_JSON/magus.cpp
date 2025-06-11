#include "magus.h"
#include <iostream>

// • Fejtsd ki a Magus osztályban az ősosztály metódusait az alábbiaknak megfelelően:
// o eletero: a mágus életereje alapból 8, és ez minden egyes szintért 3-mal növekszik, 
// plusz 1 extra életet kap minden 5. manáért (törtrész nincs),
// o sebzes: a mágus sebzése alapból 4, és ez minden egyes szintért 2-vel növekszik, 
// plusz 3 extra sebzést kap minden 10. manáért (törtrész nincs),
// o kiir: megjeleníti az adatokat a minta szerint.

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
