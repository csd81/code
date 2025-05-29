// A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat.
// A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a main függvényben a nem használt kódokat ki lehet kommentezni.
// A megadott osztály a Szamsor osztály, amely egy dinamikusan foglalt tömböt tárol egész számokból, pár alapvető függvénnyel.
// A tömb méretét a konstruktora adja meg.
// Szintén adott a közös feladatban is használt Szemely osztály.
// Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.

// Származtass egy Rendezveny osztályt a Szamsor osztályból, ami egy egy hetes rendezvény adatait tárolja.
// Ebben az ősosztály által létrehozott dinamikus tömb mindenképpen 7 méretű lesz (egy-egy szám a hét minden napjához, ami az adott napi létszám).
// Ezen felül tároljon egy Szemely mutatót, ami a rendezvény kiemelt vendégének nevét tárolja (feltéve ha van, ezért mutató).
// A kiemelt vendéget lehessen beállítani és lekérdezni.
// Készíts a Rendezveny osztályba egy kiir függvényt, amely kiírja az összes adatot.
// Készíts másoló konstruktort a Rendezveny osztályhoz.
// Készíts a Rendezveny-be egy legjobbNap függvényt, amely kiírja, hogy a rendezvény hanyadik napján volt a legnagyobb a létszám.

// Készíts a main.cpp-be egy kisebbAtlag függvényt, amely paraméterben megkap két Szamsor-t.
// A függvény írja ki, hogy az első vagy a második paraméterben eltárolt számoknak nagyobb-e az átlaga, vagy esetleg azonos.


#include <iostream>
#include "szemely.h"
#include "szamsor.h"
#include "rendezveny.h"

using namespace std;

void szamsorKiir(const Szamsor &s)
{
	for (unsigned int i=0; i<s.getDarab(); i++)
	{
		if (i>0) cout << ", ";
		cout << s.getErtek(i);
	}
	cout << endl;
}

void kisebbAtlag(const Szamsor& a, const Szamsor& b)
{
    double atlagA = 0, atlagB = 0;

    for (unsigned int i = 0; i < a.getDarab(); ++i)
        {
        atlagA += a.getErtek(i);
        }
    atlagA /= a.getDarab();

    for (unsigned int i = 0; i < b.getDarab(); ++i)
    {
        atlagB += b.getErtek(i);
    }
    atlagB /= b.getDarab();

    if (atlagA < atlagB)
        cout << "elso kisebb" << endl;
    else if (atlagB < atlagA)
        cout << "masodik kisebb" << endl;
    else
        cout << "egyenlo" << endl;
}


int main()
{
	// Szamsor teszt: meglévő kódok
	Szamsor s1(3);
	s1.setErtek(0,5);
	s1.setErtek(1,6);
	s1.setErtek(2,7);
	Szamsor s2(8);
	s2.setErtek(0,3);
	s2.setErtek(1,1);
	s2.setErtek(2,-9);
	s2.setErtek(3,-1);
	s2.setErtek(4,-4);
	s2.setErtek(5,1);
	s2.setErtek(6,10);
	s2.setErtek(7,-5);

	szamsorKiir(s1);
	szamsorKiir(s2);

    // Rendezveny teszt: kiírás
    cout << endl;
    Rendezveny r1, r2;
    r1.setErtek(0,5);
    r1.setErtek(1,6);
    r1.setErtek(2,3);
    r1.setErtek(3,7);
    r1.setErtek(4,8);
    r1.setErtek(5,4);
    r1.setErtek(6,9);

    r2.setErtek(0,1);
    r2.setErtek(1,10);
    r2.setErtek(2,2);
    r2.setErtek(3,4);
    r2.setErtek(4,5);
    r2.setErtek(5,2);
    r2.setErtek(6,6);
    r2.setKiemeltVendeg(Szemely("Vendeg", "Piroska", 30));

    r1.kiir();
    r2.kiir();

    // Rendezveny teszt: másoló konstruktor
    cout << endl;
    Rendezveny masolat(r2);
    masolat.kiir();
    masolat.setErtek(4,123);
    masolat.setErtek(1,222);
    masolat.kiir();

    // Rendezveny teszt: legjobb nap
    cout << endl;
    r1.legjobbNap();
    r2.legjobbNap();

    // Szamsor teszt: kisebb átlag
    cout << endl;
    cout << "Atlag osszehasonlitas: s1 vs s2: ";
    kisebbAtlag(s1,s2);
    cout << "Atlag osszehasonlitas: s2 vs r1: ";
    kisebbAtlag(s2,r1);
    cout << "Atlag osszehasonlitas: r1 vs r2: ";
    kisebbAtlag(r1,r2);
    cout << "Atlag osszehasonlitas: r2 vs s1: ";
    kisebbAtlag(r2,s1);
    cout << "Atlag osszehasonlitas: s1 vs r1: ";
    kisebbAtlag(s1,r1);
    cout << "Atlag osszehasonlitas: s2 vs r2: ";
    kisebbAtlag(s2,r2);

	return 0;
}
