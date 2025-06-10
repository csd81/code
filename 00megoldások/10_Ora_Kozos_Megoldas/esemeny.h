#ifndef ESEMENY_H
#define ESEMENY_H

#include <string>

using namespace std;

// Az Esemeny osztály egy esemény (rendezvény) adatait tárolja:
// név, dátum (string), kezdési idő, befejezési idő, résztvevők száma (egész számok)
// Feltesszük, hogy minden esemény egész órakor kezdődik és végződik
class Esemeny
{
	string nev;                 // Esemény neve
	string datum;              // Dátum (pl. "2023.06.20.")
	int kezdete, vege;         // Kezdési és befejezési idő egész órában
	int resztvevokSzama;       // Résztvevők száma

public:
	Esemeny() = default;  // Paraméter nélküli konstruktor

	// Konstruktor, ami minden adatot elvár (a specifikáció szerint)
	Esemeny(const string &_nev, const string &_datum, int _kezdete, int _vege, int _resztvevok);

	// Getter és setter minden adattagra (a specifikáció szerint)
	string getNev() const;
	void setNev(const string &newNev);

	string getDatum() const;
	void setDatum(const string &newDatum);

	int getKezdete() const;
	void setKezdete(int newKezdete);

	int getVege() const;
	void setVege(int newVege);

	int getResztvevokSzama() const;
	void setResztvevokSzama(int newResztvevokSzama);
};

#endif // ESEMENY_H
