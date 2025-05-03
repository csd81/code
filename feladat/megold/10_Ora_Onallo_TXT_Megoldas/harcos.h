#ifndef HARCOS_H
#define HARCOS_H

#include "karakter.h"

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
