#ifndef JARMU_H
#define JARMU_H

// A megadott osztály a Jarmu osztály, mely tárolja egy jármű sebességét és tömegét.
// A konstruktor mindkét értéket várja.
// A Jarmu osztály kiir függvényét tedd virtuálissá. Tedd a Jarmu osztály destruktorát virtuálissá.
// A Jarmu osztályt tedd absztrakt osztállyá azáltal, hogy a kiir függvényt tisztán virtuálissá teszed.

class Jarmu
{
protected:
    unsigned int tomeg, sebesseg; // Tárolja a tömeget és a sebességet
public:
    Jarmu(unsigned int t, unsigned int s); // Konstruktor mindkét értéket várja
    virtual void kiir() const = 0; // Tisztán virtuális függvény => Jarmu absztrakt osztály
    virtual ~Jarmu(); // Virtuális destruktor
};

#endif // JARMU_H
