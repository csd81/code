#ifndef SZAMSOR_H
#define SZAMSOR_H

// Spec: A megadott osztály a Szamsor osztály,
// amely egy dinamikusan foglalt tömböt tárol egész számokból,
// pár alapvető függvénnyel.
// A tömb méretét a konstruktora adja meg.

class Szamsor
{
protected:
    unsigned int darab;   // Spec: tömb mérete
    int *tomb;            // Spec: dinamikusan foglalt tömb
public:
    Szamsor(unsigned int db);         // Spec: konstruktor méret megadásával
    Szamsor(const Szamsor &sz);       // Spec: másoló konstruktor
    ~Szamsor();                       // Spec: Ügyelj arra, hogy minden lefoglalt memória kerüljön megfelelően felszabadításra.

    unsigned int getDarab() const;    // getter
    int getErtek(unsigned int index) const;
    void setErtek(unsigned int index, int ertek);
};

#endif // SZAMSOR_H
