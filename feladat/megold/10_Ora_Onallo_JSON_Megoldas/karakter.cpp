#include "karakter.h"

Karakter::Karakter(const string &_nev, unsigned int _szint):
	nev(_nev),
	szint(_szint)
{
}

string Karakter::getNev() const
{
	return nev;
}

unsigned int Karakter::getSzint() const
{
	return szint;
}
