#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>

using namespace std;

// Spec: A megadott osztály a Szemely osztály,
// mely tárolja egy személy vezeték és keresztnevét, valamint életkorát,
// pár alapvető függvénnyel.
class Szemely
{
protected:
    string vnev, knev;          // Spec: vezetéknév és keresztnév
    unsigned int eletkor;       // Spec: életkor
public:
    Szemely(const string &v, const string &k, unsigned int kor);

    const string &getVezetekNev() const;  // Spec: Getter függvény minden adathoz legyen
    const string &getKeresztNev() const;
    string teljesNev() const;             // Spec: teljes név visszaadása
    unsigned int getEletkor() const;

    void kiir() const;                    // Spec: kiir függvény, amely kiírja az adatokat

    // Spec: Készíts a Szemely osztályba egy fiatalabb függvényt,
    // ami paraméterben egy másik személyt vár.
    // A függvény térjen vissza igaz értékkel, ha az adott személy fiatalabb,
    // mint a paraméterben átadott.
    bool fiatalabb(const Szemely &sz);
};

#endif // SZEMELY_H
