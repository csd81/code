//A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat.
//A megoldás bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni, és a teszteléshez a main függvényben a nem használt kódokat ki lehet kommentezni.
//A megadott osztály a Szemely osztály, mely tárolja egy személy vezeték és keresztnevét, valamint életkorát, pár alapvető függvénnyel.
//Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
//Származtass egy Hallgato osztályt a Szemely-ből.
//Az osztály tárolja még a hallgató Neptunkódját és befejezett féléveinek számát.
//Ezeket is kapja meg a konstruktor, de a félévek száma legyen elhagyható, ekkor az értéke legyen 1.
//Getter függvény minden adathoz legyen, setter csak a félévek számához.                                                                                                                                                                                                                         //A Szemely osztályban van egy kiir függvény, amely kiírja az adatait.                                                                                                                                                                                                                                                                                                        //Írd felül ezt a függvényt a Hallgato-ba, amely kiír minden adatot az ősosztály kiir függvényét felhasználva.
//Készíts a Hallgato osztályba egy furcsa függvényt.                                                                                                                                                                                                                                                                                                                                                                      //A függvény igazzal térjen vissza, ha a hallgató fiatalabb, mint ahogy a féléveinek száma sugallja, egyébként hamissal.
//(Egy hallgató általában legalább 18 éves, amikor az első félévét elkezdi.)
//Készíts a Szemely osztályba egy fiatalabb függvényt, ami paraméterben egy másik személyt vár.
//A függvény térjen vissza igaz értékkel, ha az adott személy fiatalabb, mint a paraméterben átadott.
//Egyébként térjen vissza hamissal.


#include <iostream>
#include "szemely.h"
#include "hallgato.h"

using namespace std;

int main()
{
	// Szemely teszt: már meglévő kódok
	Szemely sz1("Kiss", "Jozsef", 32);
	Szemely sz2("Nagy", "Maria", 20);
	sz1.kiir();
	sz2.kiir();

    // Hallgato teszt: létrehozás és kiir függvény
    cout << endl;
    Hallgato h1("Teszt", "Anna", 21, "ABCDEF");
    Hallgato h2("Hegeszt", "Elek", 19, "XYZXYZ", 5);
    h1.kiir();
    h2.kiir();

    // Hallgato teszt: furcsa függvény
    cout << endl;
    cout << h1.teljesNev() << ": " << h1.furcsa() << endl;
    cout << h2.teljesNev() << ": " << h2.furcsa() << endl;

    // Szemely teszt: fiatalabb függvény
    cout << endl;
    if (sz1.fiatalabb(sz2)) cout << sz1.teljesNev() << " fiatalabb nala: " << sz2.teljesNev() << endl;
    else cout << sz1.teljesNev() << " idosebb nala: " << sz2.teljesNev() << endl;
    if (sz2.fiatalabb(h1)) cout << sz2.teljesNev() << " fiatalabb nala: " << h1.teljesNev() << endl;
    else cout << sz2.teljesNev() << " idosebb nala: " << h1.teljesNev() << endl;
    if (h1.fiatalabb(h2)) cout << h1.teljesNev() << " fiatalabb nala: " << h2.teljesNev() << endl;
    else cout << h1.teljesNev() << " idosebb nala: " << h2.teljesNev() << endl;
    if (h2.fiatalabb(sz1)) cout << h2.teljesNev() << " fiatalabb nala: " << sz1.teljesNev() << endl;
    else cout << h2.teljesNev() << " idosebb nala: " << sz1.teljesNev() << endl;

	return 0;
}
