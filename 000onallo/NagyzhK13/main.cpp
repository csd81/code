#include <iostream>
#include "elem.h"
#include "gomb.h"
#include "szambevitel.h"
#include "felulet.h"

using namespace std;

int main()
{

	// Gomb teszt: konstruktor, getter
	cout << endl << endl << "Gomb teszt: konstruktor, getter" << endl;
Gomb g1(50, 60, 300, 200, "tartalom", 15);
cout << g1.getX() << " " << g1.getY() << " " << g1.getSzelesseg() << " " << g1.getMagassag() << endl; // 50 60 300 200
cout << g1.getSzoveg() << " " << g1.getMegnyomasok() << endl; // tartalom 15

	// Gomb teszt: kirajzol
	cout << endl << endl << "Gomb teszt: kirajzol" << endl;
g1.kirajzol();
	// X: 50, Y: 60, szelesseg: 300, magassag: 200
	//   Szoveg: tartalom, megnyomasok: 15

	// Gomb teszt: aktival
	cout << endl << endl << "Gomb teszt: aktival" << endl;
g1.aktival();
cout << g1.getSzoveg() << " " << g1.getMegnyomasok() << endl; // tartalom 20
g1.aktival(30);
cout << g1.getSzoveg() << " " << g1.getMegnyomasok() << endl; // tartalom 50

	// Gomb teszt: operator ==
	cout << endl << endl << "Gomb teszt: operator ==" << endl;
Gomb g2(54, 54, 64, 432, "alma", 35);
Gomb g3(54, 54, 54, 332, "alma", 65);
Gomb g4(54, 54, 44, 32, "alma", 35);
Gomb g5(54, 54, 34, 232, "korte", 35);
cout << (g1==g2) << endl; // 0
cout << (g1==g3) << endl; // 0
cout << (g1==g4) << endl; // 0
cout << (g1==g5) << endl; // 0
cout << (g2==g3) << endl; // 0
cout << (g2==g4) << endl; // 1
cout << (g2==g5) << endl; // 0

	// SzamBevitel teszt: konstruktor, getter
	cout << endl << endl << "SzamBevitel teszt: konstruktor, getter" << endl;
SzamBevitel sz1(20, 65, 250, 100, 60);
cout << sz1.getX() << " " << sz1.getY() << " " << sz1.getSzelesseg() << " " << sz1.getMagassag() << endl; // 20 65 250 100
cout << sz1.getErtek() << endl; // 60

	// SzamBevitel teszt: kirajzol
	cout << endl << endl << "SzamBevitel teszt: kirajzol" << endl;
sz1.kirajzol();
	// X: 20, Y: 65, szelesseg: 250, magassag: 100
	//   Ertek: 60

	// SzamBevitel teszt: aktival
	cout << endl << endl << "SzamBevitel teszt: aktival" << endl;
sz1.aktival();
cout << sz1.getErtek() << endl; // 65
sz1.aktival(-30);
cout << sz1.getErtek() << endl; // 35
sz1.aktival(240);
cout << sz1.getErtek() << endl; // 100
sz1.aktival(-423);
cout << sz1.getErtek() << endl; // -100
sz1.aktival(150);
cout << sz1.getErtek() << endl; // 50

	// Felulet teszt: konstruktor, getMeret
	cout << endl << endl << "Felulet teszt: konstruktor, getMeret" << endl;
Felulet f;
cout << f.getMeret() << endl; // 0

	// Felulet teszt: konstruktor, hozzaad
	cout << endl << endl << "Felulet teszt: hozzaad" << endl;
f.hozzaad(new SzamBevitel(8,6,7,3,21));
f.hozzaad(new Gomb(76,75,324,32,"valami",23));
f.hozzaad(new SzamBevitel(75,54,432,7,-12));
f.hozzaad(new SzamBevitel(987,87,21,3,-21));
f.hozzaad(new Gomb(2,4,5,2,"gomb",69));
f.hozzaad(new Gomb(3,543,654,1,"szoveg",98));
cout << f.getMeret() << endl; // 6

	// Felulet teszt: konstruktor, kiir
	cout << endl << endl << "Felulet teszt: kiir" << endl;
f.kiir();
	// X: 8, Y: 6, szelesseg: 7, magassag: 3
	//   Ertek: 21
	// X: 76, Y: 75, szelesseg: 324, magassag: 32
	//   Szoveg: valami, megnyomasok: 23
	// X: 75, Y: 54, szelesseg: 432, magassag: 7
	//   Ertek: -12
	// X: 987, Y: 87, szelesseg: 21, magassag: 3
	//   Ertek: -21
	// X: 2, Y: 4, szelesseg: 5, magassag: 2
	//   Szoveg: gomb, megnyomasok: 69
	// X: 3, Y: 543, szelesseg: 654, magassag: 1
	//   Szoveg: szoveg, megnyomasok: 98

	// Felulet teszt: konstruktor, masolo konstruktor
	cout << endl << endl << "Felulet teszt: masolo konstruktor" << endl;
Felulet f2(f);
f2.hozzaad(new SzamBevitel(10,20,30,40,50));
f2.kiir();
	// X: 8, Y: 6, szelesseg: 7, magassag: 3
	//   Ertek: 21
	// X: 76, Y: 75, szelesseg: 324, magassag: 32
	//   Szoveg: valami, megnyomasok: 23
	// X: 75, Y: 54, szelesseg: 432, magassag: 7
	//   Ertek: -12
	// X: 987, Y: 87, szelesseg: 21, magassag: 3
	//   Ertek: -21
	// X: 2, Y: 4, szelesseg: 5, magassag: 2
	//   Szoveg: gomb, megnyomasok: 69
	// X: 3, Y: 543, szelesseg: 654, magassag: 1
	//   Szoveg: szoveg, megnyomasok: 98
	// X: 10, Y: 20, szelesseg: 30, magassag: 40
	//   Ertek: 50

	// Felulet teszt: konstruktor, operator ++
	cout << endl << endl << "Felulet teszt: operator ++" << endl;
++f;
f.kiir();
	// X: 8, Y: 6, szelesseg: 7, magassag: 3
	//   Ertek: 26
	// X: 76, Y: 75, szelesseg: 324, magassag: 32
	//   Szoveg: valami, megnyomasok: 28
	// X: 75, Y: 54, szelesseg: 432, magassag: 7
	//   Ertek: -7
	// X: 987, Y: 87, szelesseg: 21, magassag: 3
	//   Ertek: -16
	// X: 2, Y: 4, szelesseg: 5, magassag: 2
	//   Szoveg: gomb, megnyomasok: 74
	// X: 3, Y: 543, szelesseg: 654, magassag: 1
	//   Szoveg: szoveg, megnyomasok: 103






	cout << endl << endl << endl << "VEGE" << endl << endl;
	return 0;
}
