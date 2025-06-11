#ifndef IJASZ_H
#define IJASZ_H

#include "karakter.h"

// • Származtass a Karakter osztályból egy Ijasz osztályt, ami az íjász típusú karaktert valósítja meg. 
// Extra adatként a célzás pontosságát tárolja (egész). 
// A konstruktor mindhárom adatot várja (név, szint, pontosság).

class Ijasz : public Karakter
{
	unsigned pontossag;
public:
	Ijasz(const string &_nev, unsigned _szint, unsigned _pontossag);
	int eletero() const override;
	int sebzes() const override;
	void kiir() const override;
};

#endif // IJASZ_H
