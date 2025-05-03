#include "szerver.h"
#include "harcos.h"
#include "ijasz.h"
#include "magus.h"
#include <fstream>
#include <iostream>

Szerver::~Szerver()
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		delete jatekosok[i];
}

void Szerver::betolt()
{
	ifstream input("karakterek.txt");
	if (!input.is_open())
	{
		cout << "Cannot open input file" << endl;
		return ;
	}

	string nev;
	input >> nev;
	while (nev!="*")
	{
		string kaszt;
		int szint;
		input >> kaszt >> szint;

		if (kaszt=="harcos")
		{
			string fegyver;
			input >> fegyver;
			jatekosok.push_back(new Harcos(nev, szint, fegyver));
		}
		else if (kaszt=="ijasz")
		{
			int pontossag;
			input >> pontossag;
			jatekosok.push_back(new Ijasz(nev, szint, pontossag));
		}
		else if (kaszt=="magus")
		{
			int mana;
			input >> mana;
			jatekosok.push_back(new Magus(nev, szint, mana));
		}

		input >> nev;
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
	ifstream input("merkozesek.txt");
	if (!input.is_open())
	{
		cout << "Cannot open input merkozesek.txt" << endl;
		return ;
	}
	ofstream output("eredmenyek.txt");
	if (!output.is_open())
	{
		cout << "Cannot open input eredmenyek.txt" << endl;
		return ;
	}

	string nev1;
	input >> nev1;
	while (!input.eof())
	{
		string nev2;
		input >> nev2;
		string nyertes = csata(nev1, nev2);
		output << nev1 << " " << nev2 << " ";
		if (nyertes == nev1)
			output << 1;
		else if (nyertes == nev2)
			output << 2;
		else
			output << 0;
		output << endl;

		input >> nev1;
	}
}
