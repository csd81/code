#ifndef TOMB_H
#define TOMB_H

// Tomb osztály:
// - Sablonos osztály, amely egy statikus tömböt valósít meg objektum-orientált módon.
// - 2 sablonparaméterrel rendelkezik:
//    - Tipus: a tárolt elemek típusa
//    - Meret: a tömb mérete (egész szám)
//
// Az osztály a TombAlap interfészt implementálja (öröklődik belőle)

#include "tombalap.h"

template <class Tipus, int Meret>
class Tomb : public TombAlap<Tipus> // az interfész implementálása
{
    // statikus tömb, ahol az elemek tárolódnak
    Tipus tomb[Meret];
public:
    // A specifikáció szerinti metódusok implementációi:

    // meret: visszaadja a tömb méretét
    int meret() const;

    // beallit: beállítja az adott indexű elem értékét (érvénytelen indexre nem csinál semmit)
    void beallit(int index, const Tipus &adat);

    // leker: visszaadja az adott indexű elem értékének másolatát
    Tipus leker(int index) const;

    // elem: az adott indexű elem referenciáját adja vissza (nem const verzió)
    Tipus &elem(int index);

    // elem: az adott indexű elem const referenciáját adja vissza (const verzió)
    const Tipus &elem(int index) const;

    // operator []: az elem metódust használja (nem const verzió)
    Tipus &operator [](int index);

    // operator []: az elem metódust használja (const verzió)
    const Tipus &operator [](int index) const;
};

// metódusok implementációi (osztályon kívül):

template<class Tipus, int Meret>
int Tomb<Tipus,Meret>::meret() const
{
    return Meret;
}

template<class Tipus, int Meret>
void Tomb<Tipus,Meret>::beallit(int index, const Tipus &adat)
{
    // csak érvényes index esetén állítja be az értéket
    if (index >= 0 && index < Meret)
        tomb[index] = adat;
}

template<class Tipus, int Meret>
Tipus Tomb<Tipus,Meret>::leker(int index) const
{
    return tomb[index];
}

template<class Tipus, int Meret>
Tipus &Tomb<Tipus,Meret>::elem(int index)
{
    return tomb[index];
}

template<class Tipus, int Meret>
const Tipus &Tomb<Tipus,Meret>::elem(int index) const
{
    return tomb[index];
}

template<class Tipus, int Meret>
Tipus &Tomb<Tipus,Meret>::operator [](int index)
{
    return tomb[index];
}

template<class Tipus, int Meret>
const Tipus &Tomb<Tipus,Meret>::operator [](int index) const
{
    return tomb[index];
}

#endif // TOMB_H
