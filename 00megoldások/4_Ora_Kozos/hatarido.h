#ifndef HATARIDO_H
#define HATARIDO_H

#include "datum.h"
#include <string>

using namespace std;

// Spec: Készíts egy Hatarido osztályt,
// ami tárolja egy szoftver nevét (egy szöveg, ami akár szóközöket is tartalmazhat),
// és a különböző verzióihoz tartozó kitűzött határidőket.
// Három verzióhoz tárolunk határidőt (Datum típus): alpha, beta, és végső,
// de nem biztos hogy mindegyik határidőt meghatároztuk
// (tipp: dinamikusan foglalva kezeljük az időpontokat, három mutatót tárolva).

class Hatarido
{
    string nev;
    Datum *alphaDatum = nullptr; // Spec: dinamikus tárolás
    Datum *betaDatum = nullptr;
    Datum *vegsoDatum = nullptr;

    // Spec: Legyen a Hatarido osztályban egy statikus adattag is, ami az aktuális dátumot tárolja.
    static Datum aktualisDatum;

public:
    // Spec: A konstruktor csak a szoftver nevét várja.
    Hatarido(const string &n);
    ~Hatarido(); // Spec: Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.

    // Spec: Készíts másoló konstruktort a Hatarido osztályhoz.
    Hatarido(const Hatarido &h);

    // Spec: Legyen a névhez és az időpontokhoz lekérdező és beállító függvény.
    string getNev() const;
    void setNev(const string &_nev);

    const Datum *getAlphaDatum() const;
    void setAlphaDatum(const Datum &_alpha);
    const Datum *getBetaDatum() const;
    void setBetaDatum(const Datum &_beta);
    const Datum *getVegsoDatum() const;
    void setVegsoDatum(const Datum &_vegso);

    // Spec: A bejegyzett határidőket lehessen törölni is egy hataridoTorol metódus segítségével.
    void hataridoTorol(const string &melyik);

    // Spec: Legyen a Hatarido osztályban beállító és lekérdező függvény az aktuális dátumhoz.
    static const Datum &getAktualisDatum();
    static void setAktualisDatum(const Datum &newAktualisDatum);

    // Spec: A Hatarido osztályban legyen egy lejart metódus,
    // amely a kimenetre kiírja az összes olyan határidőt, ami lejárt.
    void lejart() const;
};

#endif // HATARIDO_H
