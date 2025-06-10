#ifndef TOMB_H
#define TOMB_H

// 1. rész
// A feladat teszteléséhez a mellékelt projekt tartalmaz egy main függvényt.
//
// • Készíts egy sablonos Tomb osztályt, amely egy statikus tömböt valósít meg objektum-orientált formában.
//   o 2 sablon-paramétere van. Az első egy típus, hogy milyen típusú adatokat tároljon a tömb. 
//     A második egy egész szám, hogy hány eleme legyen a tömbnek.
//   o Az osztály tároljon egy megfelelő típusú és méretű tömböt (statikus tömbként, nem kell dinamikus memóriafoglalás).
//   o Feltételezhetjük, hogy a tárolt típusnak van paraméter nélkül hívható konstruktora.
//
// Készítsd el az osztályhoz az alábbi függvényeket:
// • meret: visszaadja a tömb méretét.
// • beallit: megkap egy indexet és egy értéket, és beállítja a tömb adott indexű elemét a kapott értékre (érvénytelen indexre ne csináljon semmit).
// • leker: megkap egy indexet, és visszaadja a tömb adott indexű elemét (pontosabban egy másolatot), az index helyességét nem kell ellenőrizni.
// • elem: megkap egy indexet, és visszaadja a tömb adott indexű elemét referenciaként (ezáltal a függvényen keresztül akár módosítható is lesz), az index helyességét nem kell ellenőrizni.
//   o Az elem függvényhez készíts egy konstans verziót is, ami konstans referenciát ad vissza.
//   o Ha már mennek az operátorok, akkor elkészíthető a [] operátor is két verzióban, ugyanezzel a funkcionalitással.

template <class Tipus, int Meret>
class Tomb
{
    Tipus tomb[Meret]; // statikus tömb (nem dinamikus), méretét a sablon paraméter adja
public:
    int meret() const; // visszaadja a tömb méretét
    void beallit(int index, const Tipus &adat); // beállítja az adott indexű elemet (érvénytelen index esetén nem csinál semmit)
    Tipus leker(int index) const; // másolatot ad vissza az adott indexű elemből (index helyességét nem ellenőrizzük)
    Tipus &elem(int index); // referenciát ad vissza az adott indexű elemre (index helyességét nem ellenőrizzük)
    const Tipus &elem(int index) const; // konstans referenciát ad vissza (index helyességét nem ellenőrizzük)
    Tipus &operator [](int index); // [] operátor, nem konstans verzió
    const Tipus &operator [](int index) const; // [] operátor, konstans verzió
};

template<class Tipus, int Meret>
int Tomb<Tipus,Meret>::meret() const
{
    return Meret; // visszaadja a tömb méretét
}

template<class Tipus, int Meret>
void Tomb<Tipus,Meret>::beallit(int index, const Tipus &adat)
{
    // beállítja az adott indexű elemet (érvénytelen index esetén nem csinál semmit)
    if (index>=0 && index<Meret)
        tomb[index]=adat;
}

template<class Tipus, int Meret>
Tipus Tomb<Tipus,Meret>::leker(int index) const
{
    return tomb[index]; // másolatot ad vissza az adott indexű elemből (index helyességét nem ellenőrizzük)
}

template<class Tipus, int Meret>
Tipus &Tomb<Tipus,Meret>::elem(int index)
{
    return tomb[index]; // referenciát ad vissza az adott indexű elemre (index helyességét nem ellenőrizzük)
}

template<class Tipus, int Meret>
const Tipus &Tomb<Tipus,Meret>::elem(int index) const
{
    return tomb[index]; // konstans referenciát ad vissza (index helyességét nem ellenőrizzük)
}

template<class Tipus, int Meret>
Tipus &Tomb<Tipus,Meret>::operator [](int index)
{
    return tomb[index]; // [] operátor, nem konstans verzió
}

template<class Tipus, int Meret>
const Tipus &Tomb<Tipus,Meret>::operator [](int index) const
{
    return tomb[index]; // [] operátor, konstans verzió
}

#endif // TOMB_H
