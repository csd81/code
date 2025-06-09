#ifndef RENDEZVENY_H
#define RENDEZVENY_H

#include "szamsor.h"
#include "szemely.h"

// Spec: Származtass egy Rendezveny osztályt a Szamsor osztályból,
// ami egy egy hetes rendezvény adatait tárolja.
// Ebben az ősosztály által létrehozott dinamikus tömb mindenképpen 7 méretű lesz.

class Rendezveny : public Szamsor
{
    // Spec: Ezen felül tároljon egy Szemely mutatót,
    // ami a rendezvény kiemelt vendégének nevét tárolja (feltéve ha van, ezért mutató).
    Szemely *vendeg;
public:
    Rendezveny();                           // Spec: konstruktor
    Rendezveny(const Rendezveny &r);        // Spec: másoló konstruktor
    ~Rendezveny();                         // Spec: memória felszabadítása

    const Szemely *getKiemeltVendeg() const;  // Spec: kiemelt vendég lekérdezése
    void setKiemeltVendeg(const Szemely &v);  // Spec: kiemelt vendég beállítása

    void kiir() const;                      // Spec: kiir függvény, kiírja az összes adatot
    void legjobbNap() const;                // Spec: legjobbNap függvény, kiírja a legnagyobb létszámú napot
};

#endif // RENDEZVENY_H
