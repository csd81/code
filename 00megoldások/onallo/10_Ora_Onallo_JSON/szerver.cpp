#include "szerver.h"
#include "harcos.h"
#include "ijasz.h"
#include "magus.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using namespace nlohmann;

// • A Szerver osztály destruktora szabadítson fel minden lefoglalt memóriát.

Szerver::~Szerver()
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		delete jatekosok[i];
}

// • A Szerver osztálynak legyen egy betolt metódusa, amely a karakterek.json fájlból betölti a szerveren játszó játékosokat.
// A fájl JSON formátumú, egy tömböt tartalmaz, amiben a karakterek találhatóak.
// Minden karakterhez adott a neve, kasztja, szintje, valamint a kaszthoz tartozó extra adat (fegyver, pontosság, vagy mana).
// A metódus töltse fel a tárolt karakterek tömbjét a megfelelő típusú karakterekkel.

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

// • A Szerver osztálynak legyen egy listaz metódusa, amely kilistázza a játékosokat (a Karakter osztály kiir metódusát felhasználva).

void Szerver::listaz() const
{
	for (unsigned i=0; i<jatekosok.size(); i++)
		jatekosok[i]->kiir();
}

// • A Szerver osztálynak legyen egy legtobbElet metódusa, amely visszaadja a legtöbb élettel rendelkező karaktert (Karakter mutatóként, értelemszerűen).

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

// • Legyen a Szerver osztálynak egy csata metódusa, amely megkapja kettő játékos nevét (szövegek), eldönti, hogy ha ez a két játékos összecsap, 
// akkor ki lesz a nyertes, és ennek megfelelően visszaadja a nyertes nevét (szöveg). 
// Feltehetjük, hogy létező játékos neveket adunk meg.
// Ha a csata döntetlenre jönne ki, akkor az „X” szöveget adja vissza.
// o Hogy megy a csata? Mindkét játékosnak van egy életereje és egy sebzése. 
// A csata minden körében a játékosok a sebzésüknek megfelelően csökkentik a másik játékos életét. 
// Ha valaki élete 0-ra, vagy ez alá csökken, akkor a másik nyer. 
// Ha egyszerre csökken 0-ra (vagy az alá) az életük, akkor döntetlen. 
// Ha mindketten élnek még, akkor jön a következő kör.
// Értelemszerűen a játékosok tárolt adatai nem változhatnak, az „élet csökkenést” átmeneti adatokkal kell kezelni.

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

// • Legyen a Szerver osztálynak egy tornaSzimulacio metódusa, amely több csatát is végrehajt (az előző csata függvényt felhasználva).
// A lejátszandó csatákat a merkozesek.json fájl tárolja JSON formátumban. 
// Egy tömböt tartalmaz, aminek minden eleme két adatból áll: jatekos1 és jatekos2, a két játékos neve.
// A függvény mindegyik csatát futtassa le, majd az eredményt írja ki az eredmenyek.json fájlba, JSON formátumban.
// A kimeneten ugyanaz az adatszerkezet legyen, mint amit be is olvas, de a tömb minden eleme egészüljön ki egy nyertes adattal, ami:
// 1, ha az első játékos nyert
// 2, ha a második
// 0, ha döntetlen

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
