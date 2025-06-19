#include <iostream>
#include "adatmegjelenito.h"
#include "szoveg.h"
#include "szamlista.h"
#include "adathalmaz.h"

using namespace std;

int main()
{

	// Szoveg teszt: konstruktor, getter, setter
	cout << endl << endl << "Szoveg teszt: konstruktor, getter, setter" << endl;
    Szoveg szoveg1("feher", true, "tartalom", 34);
    cout << szoveg1.getSzin() << " " << szoveg1.getLathato() << endl; // feher 1
    cout << "\"" << szoveg1.getSzoveg() << "\" " << szoveg1.getBetumeret() << endl; // "tartalom" 34
    szoveg1.setLathato(false);
    cout << szoveg1.getSzin() << " " << szoveg1.getLathato() << endl; // feher 0
    cout << "\"" << szoveg1.getSzoveg() << "\" " << szoveg1.getBetumeret() << endl; // "tartalom" 34

	// Szoveg teszt: megjelenit
	cout << endl << endl << "Szoveg teszt: megjelenit" << endl;
    szoveg1.setLathato(true);
    szoveg1.megjelenit(); // Szoveg: tartalom, szin: feher, betumeret: 34
    szoveg1.setLathato(false);
    szoveg1.megjelenit(); // ----------------------

	// Szoveg teszt: operator =
	cout << endl << endl << "Szoveg teszt: operator =" << endl;
    szoveg1.setLathato(true);
    szoveg1="masik szoveg";
    cout << szoveg1.getSzin() << " " << szoveg1.getLathato() << endl; // feher 1
    cout << "\"" << szoveg1.getSzoveg() << "\" " << szoveg1.getBetumeret() << endl; // "masik szoveg" 34

	// SzamLista teszt: konstruktor, getter, setter
	cout << endl << endl << "SzamLista teszt: konstruktor, getter, setter" << endl;
    SzamLista szam1("kek", false, 15, 25);
    cout << szam1.getSzin() << " " << szam1.getLathato() << endl; // kek 0
    cout << szam1.getAlso() << " " << szam1.getFelso() << endl; // 15 25
    szam1.setLathato(true);
    cout << szam1.getSzin() << " " << szam1.getLathato() << endl; // kek 1
    cout << szam1.getAlso() << " " << szam1.getFelso() << endl; // 15 25

	// SzamLista teszt: megjelenit
	cout << endl << endl << "SzamLista teszt: megjelenit" << endl;
    szam1.setLathato(false);
    szam1.megjelenit(); // 15 , 25
    szam1.setLathato(true);
    szam1.megjelenit(); // 15 16 17 18 19 20 21 22 23 24 25

	// SzamLista teszt: operator *
	cout << endl << endl << "SzamLista teszt: operator *" << endl;
    cout << (*szam1) << endl; // 10

	// SzamLista teszt: statikus lepeskoz
	cout << endl << endl << "SzamLista teszt: statikus lepeskoz" << endl;
    szam1.setLathato(true);
    cout << SzamLista::getLepeskoz() << endl; // 1
    szam1.megjelenit(); // 15 16 17 18 19 20 21 22 23 24 25
    SzamLista::setLepeskoz(3);
    cout << SzamLista::getLepeskoz() << endl; // 3
    szam1.megjelenit(); // 15 18 21 24
    SzamLista::setLepeskoz(1);

	// AdatHalmaz teszt: konstruktor, getMeret
	cout << endl << endl << "AdatHalmaz teszt: konstruktor, getMeret" << endl;
    AdatHalmaz halmaz;
    cout << halmaz.getMeret() << endl; // 0

	// AdatHalmaz teszt: operator <<
	cout << endl << endl << "AdatHalmaz teszt: operator <<" << endl;
    halmaz << new Szoveg("fekete", true, "szoooooooooooooveg", 15);
    halmaz << new Szoveg("zold", false, "alma", 17);
    halmaz << new SzamLista("sarga", true, 7, 20);
    halmaz << new SzamLista("lila", false, 17, 19);
    halmaz << new Szoveg("piros", true, "korte", 98);
    halmaz << new SzamLista("turkiz", false, 21, 30);
    cout << halmaz.getMeret() << endl; // 6

	// AdatHalmaz teszt: kiir
	cout << endl << endl << "AdatHalmaz teszt: kiir" << endl;
    halmaz.kiir();
	// Szoveg: szoooooooooooooveg, szin: fekete, betumeret: 15
	// ----------------------
	// 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	// 17 , 19
	// Szoveg: korte, szin: piros, betumeret: 98
	// 21 , 30

	// AdatHalmaz teszt: operator <
	cout << endl << endl << "AdatHalmaz teszt: operator <" << endl;
    AdatHalmaz masikhalmaz;
    masikhalmaz << new SzamLista("sarga", true, 7, 20);
    masikhalmaz << new SzamLista("lila", true, 17, 210);
    masikhalmaz << new Szoveg("piros", true, "korte", 98);
    masikhalmaz << new SzamLista("turkiz", true, 21, 49);
    cout << (halmaz<masikhalmaz) << endl; // 1
    cout << (masikhalmaz<halmaz) << endl; // 0

	// AdatHalmaz teszt: operator ~
	cout << endl << endl << "AdatHalmaz teszt: operator ~" << endl;
    ~halmaz;
    halmaz.kiir();
	// ----------------------
	// Szoveg: alma, szin: zold, betumeret: 17
	// 7 , 20
	// 17 18 19
	// ----------------------
	// 21 22 23 24 25 26 27 28 29 30








	cout << endl << endl << endl << "Vege" << endl << endl;
	return 0;
}
