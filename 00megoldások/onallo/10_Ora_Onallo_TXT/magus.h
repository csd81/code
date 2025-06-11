#ifndef MAGUS_H
#define MAGUS_H

#include "karakter.h"

// Származtass a Karakter osztályból egy Magus osztályt, ami a mágus típusú karaktert valósítja meg.
// Extra adatként a varázsláshoz rendelkezésre álló mana mennyiségét tárolja (egész). 
// A konstruktor mindhárom adatot várja (név, szint, mana).

class Magus : public Karakter
{
	unsigned mana;
public:
	Magus(const string &_nev, unsigned _szint, unsigned _mana);
	int eletero() const override;
	int sebzes() const override;
	void kiir() const override;
};

#endif // MAGUS_H
