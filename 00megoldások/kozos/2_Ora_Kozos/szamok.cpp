#include "szamok.h"

namespace Tarolo {

// Konstruktor: lefoglalja a memóriát, és minden elemet a def értékkel inicializál
Szamok::Szamok(unsigned int db, double def):
    darab(db)
{
    tomb = new double[db];  // memóriafoglalás
    for (unsigned int i = 0; i < db; i++) tomb[i] = def; // inicializálás
}

// Destruktor: felszabadítja a tömböt
Szamok::~Szamok()
{
    delete[] tomb;
}

// A tömb méretének lekérdezése
unsigned int Szamok::darabLeker() const
{
    return darab;
}

// Beállítja a megadott indexű elem értékét, ha érvényes az index
void Szamok::ertekBeallit(unsigned int index, double ertek)
{
    if (index < darab)
        tomb[index] = ertek;
}

// Visszaadja a megadott indexű elem értékét, vagy -1e8-et, ha érvénytelen
double Szamok::ertekLeker(unsigned int index) const
{
    if (index < darab)
        return tomb[index];
    else
        return -1e8;
}

} // namespace Tarolo
