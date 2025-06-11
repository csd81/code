#ifndef SZERVER_H
#define SZERVER_H

#include <vector>
#include "karakter.h"

// Készíts egy Szerver osztályt, ami a játékteret valósítja meg.
// A szerver a karakterek tömbjét tárolja (célszerű vector segítségével, de nem kötelező).
// Mivel minden fajta karaktert egyben kell kezelni, értelemszerűen Karakter mutatók tömbjét kell tárolni.

class Szerver
{
	vector<Karakter*> jatekosok;
public:
	~Szerver(); // A Szerver osztály destruktora szabadítson fel minden lefoglalt memóriát.
	void betolt(); // A Szerver osztálynak legyen egy betolt metódusa, amely a karakterek.txt fájlból betölti a szerveren játszó játékosokat.
	void listaz() const; // A Szerver osztálynak legyen egy listaz metódusa, amely kilistázza a játékosokat (a Karakter osztály kiir metódusát felhasználva).
	Karakter *legtobbElet() const; // A Szerver osztálynak legyen egy legtobbElet metódusa, amely visszaadja a legtöbb élettel rendelkező karaktert.
	string csata(const string &nev1, const string &nev2) const; // Legyen a Szerver osztálynak egy csata metódusa (leírás a PDF-ben).
	void tornaSzimulacio() const; // Legyen a Szerver osztálynak egy tornaSzimulacio metódusa (leírás a PDF-ben).
};

#endif // SZERVER_H
