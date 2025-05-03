#ifndef MAGUS_H
#define MAGUS_H

#include "karakter.h"

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
