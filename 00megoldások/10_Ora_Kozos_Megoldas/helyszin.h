#ifndef HELYSZIN_H
#define HELYSZIN_H

#include <vector>
#include <string>
#include "esemeny.h"

// A Helyszin osztály egy rendezvényszervező helyszín adatait tárolja:
// név, cím (szövegek), valamint az események (vector<Esemeny> használatával)
// Konstruktor nem kell (specifikáció szerint)

class Helyszin
{
	string nev;                       // Helyszín neve
	string cim;                       // Helyszín címe
	vector<Esemeny> esemenyek;       // Az itt rendezett események listája

public:
	// A JSON fájlból tölti be az összes adatot (név, cím, események tömbje)
	void betolt(const string &jsonfajl);

	// Megjeleníti az összes adatot a standard kimeneten
	void kiir() const;

	// JSON fájlba listázza ki az események hosszát (mennyi ideig tartanak)
	void esemenyHosszKiir(const string &fajlnev) const;
};

#endif // HELYSZIN_H
