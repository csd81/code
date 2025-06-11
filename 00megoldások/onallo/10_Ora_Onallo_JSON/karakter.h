#ifndef KARAKTER_H
#define KARAKTER_H

#include <string>

using namespace std;

// • Készíts egy Karakter osztályt, ami egy absztrakt ősosztály lesz a különböző típusú karakterekhez.
// Az osztály tárolja a karakter nevét (szöveg) és szintjét (egész). 
// Mindkét adatot a konstruktor várja, és legyen hozzájuk getter (getNev, getSzint).

// • Legyen a Karakter osztálynak három tisztán virtuális metódusa:
// o eletero: a karakter életerejét adja majd vissza egész számként, az adatokon nem módosít,
// o sebzes: a karakter sebzését adja majd vissza egész számként, az adatokon nem módosít,
// o kiir: megjeleníti majd a karakter adatait, és nem módosít rajtuk.

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
