#ifndef HATARIDO_H
#define HATARIDO_H

#include "datum.h"

#include <string>

using namespace std;

class Hatarido
{
	string nev;
	Datum *alphaDatum=nullptr;
	Datum *betaDatum=nullptr;
	Datum *vegsoDatum=nullptr;
	static Datum aktualisDatum;
public:
	Hatarido(const string &n);
	~Hatarido();
	Hatarido(const Hatarido &h);

	string getNev() const;
	void setNev(const string &_nev);
	const Datum *getAlphaDatum() const;
	void setAlphaDatum(const Datum &_alpha);
	const Datum *getBetaDatum() const;
	void setBetaDatum(const Datum &_beta);
	const Datum *getVegsoDatum() const;
	void setVegsoDatum(const Datum &_vegso);
	void hataridoTorol(const string &melyik);
	static const Datum &getAktualisDatum(); // Mivel a változó static, itt nem lehet baj a const ref visszatérési értékből
	static void setAktualisDatum(const Datum &newAktualisDatum);
	void lejart() const;
};

#endif // HATARIDO_H
