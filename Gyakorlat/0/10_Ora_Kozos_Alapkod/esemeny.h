#ifndef ESEMENY_H
#define ESEMENY_H

#include <string>

using namespace std;

class Esemeny
{
	string nev;
	string datum;
	int kezdete, vege, resztvevokSzama;
public:
	Esemeny() = default;
	Esemeny(const string &_nev, const string &_datum, int _kezdete, int _vege, int _resztvevok);
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
