#ifndef SZAMOK_H
#define SZAMOK_H

// A feladatban meghatározott névtér
namespace Tarolo {

// A Szamok osztály lebegőpontos számok tömbjét tárolja
class Szamok
{
    unsigned int darab;   // A tömb mérete, amit konstruktorban kapunk
    double *tomb;         // A dinamikusan lefoglalt tömb
public:
    // Konstruktor: tömb méretét és egy alapértelmezett értéket kap
    Szamok(unsigned int db, double def=0);
    
    // Destruktor: a dinamikusan foglalt tömb felszabadítása
    ~Szamok();

    // A tömb méretének lekérdezésére szolgáló függvény
    unsigned int darabLeker() const;

    // Érték beállítása a tömb adott indexére (érvénytelen index esetén nem csinál semmit)
    void ertekBeallit(unsigned int index, double ertek);

    // Érték lekérdezése a tömb adott indexéről (érvénytelen index esetén -1e8 értékkel tér vissza)
    double ertekLeker(unsigned int index) const;
};

} // namespace Tarolo

#endif // SZAMOK_H
