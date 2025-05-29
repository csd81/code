
// Készíts egy Hatarido osztályt, ami tárolja egy szoftver nevét (egy szöveg, ami akár szóközöket is tartalmazhat), és a különböző verzióihoz tartozó kitűzött határidőket.

// Három verzióhoz tárolunk határidőt (Datum típus): alpha, beta, és végső, de nem biztos hogy mindegyik határidőt meghatároztuk (tipp: dinamikusan foglalva kezeljük az időpontokat, három mutatót tárolva).

// A konstruktor csak a szoftver nevét várja.

// Legyen a névhez és az időpontokhoz lekérdező és beállító függvény (getNev, setNev, getAlphaDatum, setAlphaDatum, getBetaDatum, setBetaDatum, getVegsoDatum, setVegsoDatum).

// Legyen a Hatarido osztályban egy statikus adattag is, ami az aktuális dátumot tárolja (ez mindig létezik, nem kell mutató). Az értéke kezdetben legyen a mai nap.

// Legyen hozzá beállító és lekérő függvény (setAktualisDatum, getAktualisDatum).

// A Hatarido osztályban legyen egy lejart metódus, amely a kimenetre kiírja az összes olyan határidőt, ami lejárt (a határidő előbb van, mint az aktuális dátum).

// Célszerű a Datum osztályt kiegészíteni egy metódussal, ami összehasonlít kettő dátumot.

// A bejegyzett határidőket lehessen törölni is egy hataridoTorol metódus segítségével, amely megkapja paraméterben hogy melyik határidőt törölje.

// Készíts másoló konstruktort a Hatarido osztályhoz.

#include <iostream>
#include <fstream>
#include "datum.h"
#include "hatarido.h"

using namespace std;

void datumKiir(const Datum *d)
{
	if (d==0) cout << "Nem letezo datum" << endl;
	else cout << d->getEv() << "." << d->getHonap() << "." << d->getNap() << endl;
}

void hataridotKiir(const Hatarido &h)
{
    cout << h.getNev() << ": " << endl;
    cout << "  alpha: ";
    datumKiir(h.getAlphaDatum());
    cout << "  beta: ";
    datumKiir(h.getBetaDatum());
    cout << "  vegso: ";
    datumKiir(h.getVegsoDatum());
}

int main()
{

    // Létrehozás és név beállítás
    Hatarido h1("Elso tarolo osztaly");
    cout << "Kerek egy masik nevet: ";
    string nev;
    getline(cin, nev); // Teljes sor bekérése
    Hatarido h2(nev);
    cout << h1.getNev() << endl;
    cout << h2.getNev() << endl;
    h1.setNev("Atallitott nev");
    cout << h1.getNev() << endl;
    cout << h2.getNev() << endl;

    // Dátum beállítása
    cout << endl;
    h1.setAlphaDatum(Datum(2017, 3, 6));
    cout << "Kerek egy datumot (ev, honap, nap): ";
    unsigned int e, h, n;
    cin >> e >> h >> n;
    h1.setVegsoDatum(Datum(e,h,n));
    cout << "Kerek meg egy datumot (ev, honap, nap): ";
    cin >> e >> h >> n;
    Datum d(e,h,n);
    h2.setBetaDatum(d);
    hataridotKiir(h1);
    hataridotKiir(h2);

    // Aktuális dátum kezelése
    Datum aktualis = Hatarido::getAktualisDatum();
    cout << "Aktualis datum: " << aktualis.getEv() << "." << aktualis.getHonap() << "." << aktualis.getNap() << endl;
    cout << h1.getNev() << " lejart?" << endl;
    h1.lejart();
    cout << h2.getNev() << " lejart?" << endl;
    h2.lejart();
    cout << "Kerem az uj aktualis datumot (ev, honap, nap): ";
    cin >> e >> h >> n;
    Hatarido::setAktualisDatum(Datum(e,h,n));
    aktualis = Hatarido::getAktualisDatum();
    cout << "Aktualis datum: " << aktualis.getEv() << "." << aktualis.getHonap() << "." << aktualis.getNap() << endl;
    cout << h1.getNev() << " lejart?" << endl;
    h1.lejart();
    cout << h2.getNev() << " lejart?" << endl;
    h2.lejart();

    // Dátum átállítása és törlése
    cout << endl;
    h1.setVegsoDatum(Datum(2000,1,1));
    h1.hataridoTorol("alpha"); // Ezt kitörli
    h1.hataridoTorol("beta"); // Itt nincs dátum tárolva
    h1.hataridoTorol("gamma"); // Ilyen meg nincs is
    hataridotKiir(h1);

    // Másolat készítése
    cout << endl;
    Hatarido uj(h1);
    hataridotKiir(h1);
    hataridotKiir(uj);
    uj.setNev("UJ");
    uj.setBetaDatum(Datum(1996,8,9));
    hataridotKiir(h1);
    hataridotKiir(uj);

	return 0;
}

// A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat (main függvény és Datum osztály).
// A megoldás során ezekhez a kódokhoz nem kell nyúlni (kivéve ha a feladat kéri), de a teszteléshez a main függvényben a nem használt kódokat ki lehet kommentezni.
// Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.
// Készíts egy Hatarido osztályt, ami tárolja egy szoftver nevét (egy szöveg, ami akár szóközöket is tartalmazhat), és a különböző verzióihoz tartozó kitűzött határidőket.
// Három verzióhoz tárolunk határidőt (Datum típus): alpha, beta, és végső, de nem biztos hogy mindegyik határidőt meghatároztuk (tipp: dinamikusan foglalva kezeljük az időpontokat, három mutatót tárolva).
// A konstruktor csak a szoftver nevét várja.
// Legyen a névhez és az időpontokhoz lekérdező és beállító függvény (getNev, setNev, getAlphaDatum, setAlphaDatum, getBetaDatum, setBetaDatum, getVegsoDatum, setVegsoDatum).
// Legyen a Hatarido osztályban egy statikus adattag is, ami az aktuális dátumot tárolja (ez mindig létezik, nem kell mutató).
// Az értéke kezdetben legyen a mai nap.
// Legyen hozzá beállító és lekérő függvény (setAktualisDatum, getAktualisDatum).
// A Hatarido osztályban legyen egy lejart metódus, amely a kimenetre kiírja az összes olyan határidőt, ami lejárt (a határidő előbb van, mint az aktuális dátum).
// Célszerű a Datum osztályt kiegészíteni egy metódussal, ami összehasonlít kettő dátumot.
// A bejegyzett határidőket lehessen törölni is egy hataridoTorol metódus segítségével, amely megkapja paraméterben hogy melyik határidőt törölje.
// Készíts másoló konstruktort a Hatarido osztályhoz.
