#include "karakter.h"

// • Készíts egy Karakter osztályt, ami egy absztrakt ősosztály lesz a különböző típusú karakterekhez.
// Az osztály tárolja a karakter nevét (szöveg) és szintjét (egész). 
// Mindkét adatot a konstruktor várja, és legyen hozzájuk getter (getNev, getSzint).

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
