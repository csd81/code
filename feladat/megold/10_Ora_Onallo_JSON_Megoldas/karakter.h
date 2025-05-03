#ifndef KARAKTER_H
#define KARAKTER_H

#include <string>

using namespace std;

class Karakter
{
protected:
	string nev;
	unsigned szint;
public:
	Karakter(const string &_nev, unsigned _szint);
	string getNev() const;
	unsigned int getSzint() const;

	// Új függvények
	virtual ~Karakter() = default;
	virtual int eletero() const = 0;
	virtual int sebzes() const = 0;
	virtual void kiir() const = 0;
};

#endif // KARAKTER_H
