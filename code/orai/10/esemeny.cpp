#include "esemeny.h"

Esemeny::Esemeny(const string &_nev, const string &_datum, int _kezdete, int _vege, int _resztvevok):
	nev(_nev),
	datum(_datum),
	kezdete(_kezdete),
	vege(_vege),
	resztvevokSzama(_resztvevok)
{
}

string Esemeny::getNev() const
{
	return nev;
}

void Esemeny::setNev(const string &newNev)
{
	nev = newNev;
}

string Esemeny::getDatum() const
{
	return datum;
}

void Esemeny::setDatum(const string &newDatum)
{
	datum = newDatum;
}

int Esemeny::getKezdete() const
{
	return kezdete;
}

void Esemeny::setKezdete(int newKezdete)
{
	kezdete = newKezdete;
}

int Esemeny::getVege() const
{
	return vege;
}

void Esemeny::setVege(int newVege)
{
	vege = newVege;
}

int Esemeny::getResztvevokSzama() const
{
	return resztvevokSzama;
}

void Esemeny::setResztvevokSzama(int newResztvevokSzama)
{
	resztvevokSzama = newResztvevokSzama;
}
