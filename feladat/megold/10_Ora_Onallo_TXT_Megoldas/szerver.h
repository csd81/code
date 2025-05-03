#ifndef SZERVER_H
#define SZERVER_H

#include <vector>
#include "karakter.h"

class Szerver
{
	vector<Karakter*> jatekosok;
public:
	~Szerver();
	void betolt();
	void listaz() const;
	Karakter *legtobbElet() const;
	string csata(const string &nev1, const string &nev2) const;
	void tornaSzimulacio() const;
};

#endif // SZERVER_H
