#ifndef IJASZ_H
#define IJASZ_H

#include "karakter.h"

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
