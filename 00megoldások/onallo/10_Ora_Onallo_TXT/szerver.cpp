#include "szerver.h"
#include "harcos.h"
#include "ijasz.h"
#include "magus.h"
#include <fstream>
#include <iostream>

// A Szerver osztály destruktora szabadítson fel minden lefoglalt memóriát.

Szerver::~Szerver()
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		delete jatekosok[i];
}

// A Szerver osztálynak legyen egy betolt metódusa, amely a karakterek.txt fájlból betölti a szerveren játszó játékosokat.
// A fájl több sort tartalmaz, minden sorban egy-egy karakter adataival.
// Minden karakterhez adott a neve, kasztja, szintje, valamint a kaszthoz tartozó extra adat (fegyver, pontosság, vagy mana).
// A bemenetet a "*" karakter zárja. A metódus töltse fel a tárolt karakterek tömbjét a megfelelő típusú karakterekkel.

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

// A Szerver osztálynak legyen egy listaz metódusa, amely kilistázza a játékosokat (a Karakter osztály kiir metódusát felhasználva).

void Szerver::listaz() const
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		jatekosok[i]->kiir();
}

// A Szerver osztálynak legyen egy legtobbElet metódusa, amely visszaadja a legtöbb élettel rendelkező karaktert (Karakter mutatóként).

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

// Legyen a Szerver osztálynak egy csata metódusa, amely megkapja kettő játékos nevét (szövegek),
// eldönti, hogy ha ez a két játékos összecsap, akkor ki lesz a nyertes, és ennek megfelelően visszaadja a nyertes nevét (szöveg).
// Ha a csata döntetlenre jönne ki, akkor az "X" szöveget adja vissza.

// Hogy megy a csata? Mindkét játékosnak van egy életereje és egy sebzése.
// A csata minden körében a játékosok a sebzésüknek megfelelően csökkentik a másik játékos életét.
// Ha valaki élete 0-ra, vagy ez alá csökken, akkor a másik nyer.
// Ha egyszerre csökken 0-ra (vagy az alá) az életük, akkor döntetlen.
// Ha mindketten élnek még, akkor jön a következő kör.
// Értelemszerűen a játékosok tárolt adatai nem változhatnak, az "élet csökkenést" átmeneti adatokkal kell kezelni.

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

// Legyen a Szerver osztálynak egy tornaSzimulacio metódusa, amely több csatát is végrehajt (az előző csata függvényt felhasználva).
// A lejátszandó csatákat a merkozesek.txt fájl tárolja. A fájlban minden sor két nevet tartalmaz, a két játékos nevét, akik között a csatát le kell futtatni.
// A bemenetet a fájl vége karakter zárja. A függvény mindegyik csatát futtassa le, majd az eredményt írja ki az eredmenyek.txt fájlba.
// A kimeneten ugyanaz az adatszerkezet legyen, mint amit be is olvas, de minden sor egészüljön ki egy új adattal,
// ami 1, ha az első játékos nyert, 2, ha a második, és 0, ha döntetlen.

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
