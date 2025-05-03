#include "helyszin.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using namespace nlohmann;

void Helyszin::betolt(const string &jsonfajl)
{
	ifstream input(jsonfajl);
	if (!input.is_open())
	{
		cout << "Nem sikerult megnyitni: " << jsonfajl << endl;
		return;
	}

	json adatok = json::parse(input);
	// vagy:
//	json adatok;
//	input >> adatok;

	nev = adatok["nev"];
	cim = adatok["cim"];

	esemenyek.clear(); // Csak a biztonság kedvéért

	for (unsigned i=0; i<adatok["esemenyek"].size(); i++)
	{
//		Esemeny uj(adatok["esemenyek"][i]["nev"], adatok["esemenyek"][i]["datum"], adatok["esemenyek"][i]["kezdete"], adatok["esemenyek"][i]["vege"], adatok["esemenyek"][i]["resztvevok"]);
//		esemenyek.push_back(uj);
		// vagy:
		const json &e = adatok["esemenyek"][i];
		Esemeny uj(e["nev"], e["datum"], e["kezdete"], e["vege"], e["resztvevok"]);
		esemenyek.push_back(uj);
	}
}

void Helyszin::kiir() const
{
	cout << "Helyszin: " << nev;
	cout << " (" << cim << ")" << endl;
	cout << "Esemenyek:" << endl;
	for (unsigned i=0; i<esemenyek.size(); i++)
	{
		cout << "  " << esemenyek[i].getNev() << ": ";
		cout << esemenyek[i].getDatum() << " ";
		cout << esemenyek[i].getKezdete() << ":00 - ";
		cout << esemenyek[i].getVege() << ":00 ";
		cout << "(" << esemenyek[i].getResztvevokSzama() << " fo)" << endl;
	}
}

void Helyszin::esemenyHosszKiir(const string &fajlnev) const
{
	ofstream output(fajlnev);
	if (!output.is_open())
	{
		cout << "Nem sikerult megnyitni: " << fajlnev << endl;
		return;
	}

	// Akár így röviden is elfogadja
//	json eredmeny;
//	for (unsigned i=0; i<esemenyek.size(); i++)
//	{
//		eredmeny[i]["esemeny"] = esemenyek[i].getNev();
//		eredmeny[i]["hossz"] = esemenyek[i].getVege() - esemenyek[i].getKezdete();
//	}
	// De ki lehet írni hosszan is
	json eredmeny = json::array();
	for (unsigned i=0; i<esemenyek.size(); i++)
	{
		json egyertek = json::object();
		egyertek["esemeny"] = esemenyek[i].getNev();
		egyertek["hossz"] = esemenyek[i].getVege() - esemenyek[i].getKezdete();
		eredmeny.push_back(egyertek);
	}

//	output << eredmeny.dump(4);
	// vagy:
	output << setw(4) << eredmeny;
}
