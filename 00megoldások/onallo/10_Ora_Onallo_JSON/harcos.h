#ifndef HARCOS_H
#define HARCOS_H

#include "karakter.h"

// • Származtass a Karakter osztályból egy Harcos osztályt, ami a harcos típusú karaktert valósítja meg. 
// Extra adatként a használt fegyver típusát tárolja (szöveg). 
// A konstruktor mindhárom adatot várja (név, szint, fegyver).

class Harcos : public Karakter
{
	string fegyver;
public:
	Harcos(const string &_nev, unsigned _szint, const string &_fegyver);
	int eletero() const override;
	int sebzes() const override;
	void kiir() const override;
};

#endif // HARCOS_H
