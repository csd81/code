#include "szerver.h"
#include "harcos.h"
#include "ijasz.h"
#include "magus.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace nlohmann;

Szerver::~Szerver()
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		delete jatekosok[i];
}

void Szerver::betolt()
{
	ifstream input("karakterek.json");
	if (!input.is_open())
	{
		cout << "Cannot open input karakterek.json" << endl;
		return ;
	}

	json karakterekAdatok = json::parse(input);

	for (unsigned i=0; i<karakterekAdatok.size(); i++)
	{
		const json &karakter = karakterekAdatok[i];
		if (karakter["kaszt"]=="harcos")
			jatekosok.push_back(new Harcos(karakter["nev"], karakter["szint"], karakter["fegyver"]));
		else if (karakter["kaszt"]=="ijasz")
			jatekosok.push_back(new Ijasz(karakter["nev"], karakter["szint"], karakter["pontossag"]));
		else if (karakter["kaszt"]=="magus")
			jatekosok.push_back(new Magus(karakter["nev"], karakter["szint"], karakter["mana"]));
	}
}

void Szerver::listaz() const
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		jatekosok[i]->kiir();
}

Karakter *Szerver::legtobbElet() const
{
	Karakter *maxelet=jatekosok[0];
	for (unsigned i=0; i<jatekosok.size(); i++)
	{
		if (jatekosok[i]->eletero() > maxelet->eletero())
			maxelet = jatekosok[i];
	}
	return maxelet;
}

string Szerver::csata(const string &nev1, const string &nev2) const
{
	Karakter *k1=nullptr, *k2=nullptr;
	for (unsigned i=0; i<jatekosok.size(); i++)
	{
		if (jatekosok[i]->getNev()==nev1) k1=jatekosok[i];
		if (jatekosok[i]->getNev()==nev2) k2=jatekosok[i];
	}

	int elet1=k1->eletero();
	int sebzes1=k1->sebzes();
	int elet2=k2->eletero();
	int sebzes2=k2->sebzes();

	while (elet1>0 && elet2>0)
	{
		elet1-=sebzes2;
		elet2-=sebzes1;
	}
	if (elet1>0) return nev1;
	else if (elet2>0) return nev2;
	else return "X";
}

void Szerver::tornaSzimulacio() const
{
	ifstream input("merkozesek.json");
	if (!input.is_open())
	{
		cout << "Cannot open input merkozesek.json" << endl;
		return ;
	}
	ofstream output("eredmenyek.json");
	if (!output.is_open())
	{
		cout << "Cannot open input eredmenyek.json" << endl;
		return ;
	}

	json merkozesek = json::parse(input);
	json eredmenyek = json::array();

	for (unsigned i=0; i<merkozesek.size(); i++)
	{
		string nyertes = csata(merkozesek[i]["jatekos1"], merkozesek[i]["jatekos2"]);
		eredmenyek[i]=merkozesek[i]; // Másoljuk az inputról, és egészítsük ki
		if (nyertes == merkozesek[i]["jatekos1"])
			eredmenyek[i]["nyertes"]=1;
		else if (nyertes == merkozesek[i]["jatekos2"])
			eredmenyek[i]["nyertes"]=2;
		else
			eredmenyek[i]["nyertes"]=0;
	}

	output << setw(2) << eredmenyek;
}
