#include "helyszin.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using namespace nlohmann;

// A JSON fájl betöltése fájlnévből
// Tartalmazza: helyszín neve, címe, események tömbje
void Helyszin::betolt(const string &jsonfajl)
{
	ifstream input(jsonfajl);
	if (!input.is_open())
	{
		cout << "Nem sikerult megnyitni: " << jsonfajl << endl;
		return;
	}

	json adatok = json::parse(input);  // JSON betöltése

	nev = adatok["nev"];               // Helyszín neve
	cim = adatok["cim"];               // Helyszín címe
	esemenyek.clear();                 // Előző események törlése

	// Események listájának beolvasása
	for (unsigned i = 0; i < adatok["esemenyek"].size(); i++)
	{
		const json &e = adatok["esemenyek"][i];
		Esemeny uj(e["nev"], e["datum"], e["kezdete"], e["vege"], e["resztvevok"]);
		esemenyek.push_back(uj);
	}
}

// Helyszín adatainak és események megjelenítése a standard kimeneten
void Helyszin::kiir() const
{
	cout << "Helyszin: " << nev;
	cout << " (" << cim << ")" << endl;
	cout << "Esemenyek:" << endl;

	for (unsigned i = 0; i < esemenyek.size(); i++)
	{
		cout << "  " << esemenyek[i].getNev() << ": ";
		cout << esemenyek[i].getDatum() << " ";
		cout << esemenyek[i].getKezdete() << ":00 - ";
		cout << esemenyek[i].getVege() << ":00 ";
		cout << "(" << esemenyek[i].getResztvevokSzama() << " fo)" << endl;
	}
}

// Az események hosszát (óra) JSON fájlba írja ki
void Helyszin::esemenyHosszKiir(const string &fajlnev) const
{
	ofstream output(fajlnev);
	if (!output.is_open())
	{
		cout << "Nem sikerult megnyitni: " << fajlnev << endl;
		return;
	}

	json eredmeny = json::array();

	for (unsigned i = 0; i < esemenyek.size(); i++)
	{
		json egyertek = json::object();
		egyertek["esemeny"] = esemenyek[i].getNev();
		egyertek["hossz"] = esemenyek[i].getVege() - esemenyek[i].getKezdete();
		eredmeny.push_back(egyertek);
	}

	output << setw(4) << eredmeny;  // szépen formázott JSON kiírás
}
