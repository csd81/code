#ifndef HELYSZIN_H
#define HELYSZIN_H

#include <vector>
#include <string>
#include "esemeny.h"

class Helyszin
{
	string nev;
	string cim;
	vector<Esemeny> esemenyek;
public:
	void betolt(const string &jsonfajl);
	void kiir() const;
	void esemenyHosszKiir(const string &fajlnev) const;
};

#endif // HELYSZIN_H
