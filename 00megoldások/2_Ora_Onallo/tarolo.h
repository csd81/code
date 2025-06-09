#ifndef TAROLO_H
#define TAROLO_H

// Spec: Az osztály legyen egy EpicToolbox névtérben.
namespace EpicToolbox {

// Spec: Készíts egy Tarolo osztályt, amely egész számokat tárol, előre meg nem határozott mennyiségben.
class Tarolo
{
    unsigned int darab;  // Spec: tárolt elemek száma
    int *tomb;           // Spec: belső tömb egész számok tárolására

public:
    // Spec: Az osztálynak két konstruktora legyen:
    // 1. konstruktor - paraméterként méretet vár
    Tarolo(unsigned int db);

    // 2. konstruktor - paraméter nélküli, bekéri a méretet és az elemeket
    Tarolo();

    // Spec: Az osztály destruktora szabadítsa fel a tömböt.
    ~Tarolo();

    // Spec: Legyen az osztálynak egy kiir függvénye, amely megjeleníti az eltárolt számokat.
    void kiir() const;

    // Spec: Készíts egy hozzaad függvény is, amely megkap egy számot, és hozzáfűzi.
    void hozzaad(int ertek);

    // Spec: Készíts egy atlag függvényt az osztályba, amely visszaadja a tárolt számok átlagát.
    double atlag() const;

    // Spec: szükség lesz a Tarolo osztály megfelelő kiegészítésére (kisebbTarolo függvényhez).
    unsigned int darabLeker() const;

    // Spec: A Tarolo osztálynak legyen egy tartomany metódusa,
    // amely visszaadja a legnagyobb és legkisebb tárolt érték különbségét.
    int tartomany() const;

    // Spec: A Tarolo osztálynak legyen egy rendez metódusa,
    // paraméter: ha igaz -> növekvő, ha hamis -> csökkenő.
    void rendez(bool novekvo);

    // Spec: A Tarolo osztálynak legyen egy hozzafuz metódusa,
    // amely paraméterben egy másik Tarolo objektumot kap,
    // és a paraméterben kapott tároló elemeit hozzáfűzi az aktuálishoz.
    void hozzafuz(const Tarolo &masik);
};

} // namespace EpicToolbox

#endif // TAROLO_H
