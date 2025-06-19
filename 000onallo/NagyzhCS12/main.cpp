#include <iostream>
#include "fajl.h"
#include "szovegesfajl.h"
#include "kepfajl.h"
#include "mappa.h"

using namespace std;

int main()
{

	// SzovegesFajl teszt: konstruktor, getter, setter
	cout << endl << endl << "SzovegesFajl teszt: konstruktor, getter, setter" << endl;
    SzovegesFajl szoveg1("elso.txt", 400, 7, "Ez a tartalom");
    cout << szoveg1.getNev() << " " << szoveg1.getMeret() << endl; // elso.txt 400
    cout << szoveg1.getFontos() << " " << szoveg1.getTartalom() << endl; // 7 Ez a tartalom
    szoveg1.setFontos(9);
    cout << szoveg1.getNev() << " " << szoveg1.getMeret() << endl; // elso.txt 400
    cout << szoveg1.getFontos() << " " << szoveg1.getTartalom() << endl; // 9 Ez a tartalom

	// SzovegesFajl teszt: adatok
	cout << endl << endl << "SzovegesFajl teszt: adatok" << endl;
    szoveg1.setFontos(6);
    szoveg1.adatok(); // Nev: elso.txt, meret: 400, tartalom: Ez a tartalom
    szoveg1.setFontos(3);
    szoveg1.adatok(); // Nev: elso.txt
    szoveg1.setFontos(6);

	// SzovegesFajl teszt: operator +=
	cout << endl << endl << "SzovegesFajl teszt: operator +=" << endl;
    szoveg1.setFontos(6);
    cout << szoveg1.getFontos() << " " << szoveg1.getTartalom() << endl; // 6 Ez a tartalom
    szoveg1+=", es ez a folytatas";
    cout << szoveg1.getFontos() << " " << szoveg1.getTartalom() << endl; // 6 Ez a tartalom, es ez a folytatas

	// SzovegesFajl teszt: statikus valtozo
	cout << endl << endl << "SzovegesFajl teszt: statikus valtozo" << endl;
    SzovegesFajl szoveg2("masik.txt", 600, 8, "Tartalom");
    cout << "\"" << SzovegesFajl::getUtvonal() << "\"" << endl; // "
    szoveg2.adatok(); // Nev: masik.txt, meret: 600, tartalom: Tartalom
    SzovegesFajl::setUtvonal("eleres");
    cout << "\"" << SzovegesFajl::getUtvonal() << "\"" << endl; // "eleres"
    szoveg2.adatok(); // Nev: eleres/masik.txt, meret: 600, tartalom: Tartalom
    SzovegesFajl::setUtvonal("");

	// KepFajl teszt: konstruktor, getter
	cout << endl << endl << "KepFajl teszt: konstruktor, getter" << endl;
    KepFajl kep1("egykep.png", 54003, 4, 600, 400);
    cout << kep1.getNev() << " " << kep1.getMeret() << endl; // egykep.png 54003
    cout << kep1.getFontos() << " " << kep1.getSzelesseg() << " " << kep1.getMagassag() << endl; // 4 600 400

	// KepFajl teszt: adatok
	cout << endl << endl << "KepFajl teszt: adatok" << endl;
    kep1.adatok(); // Nev: egykep.png, fontossag: 4, meret: 54003, szelesseg: 600, magassag: 400
    KepFajl kep2("masik.jpg", 2433, 5, 200, 50);
    kep2.adatok(); // Nev: masik.jpg, fontossag: 5

	// KepFajl teszt: operator *
	cout << endl << endl << "KepFajl teszt: operator *" << endl;
    cout << (*kep1) << endl; // 240000

	// KepFajl teszt: konstruktor, getDarab
	cout << endl << endl << "KepFajl teszt: konstruktor, getDarab" << endl;
    Mappa mappa1;
    cout << mappa1.getDarab() << endl; // 0

	// KepFajl teszt: operator <<
	cout << endl << endl << "KepFajl teszt: operator <<" << endl;
    mappa1 << new SzovegesFajl("szoveg1.txt", 4243542, 6, "Elso sor");
    mappa1 << new SzovegesFajl("szoveg2.txt", 14, 8, "Ennyi az egesz");
    mappa1 << new KepFajl("kep1.bmp", 45000, 8, 100, 150);
    mappa1 << new KepFajl("kep2.jpeg", 4433, 2, 423, 442);
    mappa1 << new SzovegesFajl("szoveg3.txt", 4314, 2, "valami");
    mappa1 << new KepFajl("kep3.gif", 4500, 10, 32, 54);
    cout << mappa1.getDarab() << endl; // 6

	// KepFajl teszt: tartalom
	cout << endl << endl << "KepFajl teszt: tartalom" << endl;
    mappa1.tartalom();
    // Nev: szoveg1.txt, meret: 4243542, tartalom: Elso sor
    // Nev: szoveg2.txt, meret: 14, tartalom: Ennyi az egesz
    // Nev: kep1.bmp, fontossag: 8, meret: 45000, szelesseg: 100, magassag: 150
    // Nev: kep2.jpeg, fontossag: 2
    // Nev: szoveg3.txt
    // Nev: kep3.gif, fontossag: 10

	// KepFajl teszt: operator >
	cout << endl << endl << "KepFajl teszt: operator >" << endl;
    Mappa mappa2;
    mappa2 << new SzovegesFajl("nagy.txt", 123543, 6, "AAAAAAa");
    mappa2 << new KepFajl("nagyonnagy.bmp", 35354315, 5, 432, 4342);
    cout << (mappa1>mappa2) << endl; // 0
    cout << (mappa2>mappa1) << endl; // 1

	// KepFajl teszt: operator []
	cout << endl << endl << "KepFajl teszt: operator []" << endl;
    cout << mappa1["szoveg1.txt"] << endl; // 1
    cout << mappa1["nincs.txt"] << endl; // 0
    cout << mappa1["kep2.jpeg"] << endl; // 1
    cout << mappa1["kep2.bmp"] << endl; // 0





	cout << endl << endl << endl << "VEGE" << endl << endl;
	return 0;
}
