#ifndef DATUMLISTA_H
#define DATUMLISTA_H

#include "datum.h"
#include <string>
#include <fstream>

using namespace std;

namespace Naptar {

// Spec: Készíts egy DatumLista osztályt, amely dátumokat (Datum típus) tárol.
// A tárolt dátumok mennyiségét a konstruktorban kapja meg az osztály.
// Tároljon még egy megjegyzést (egy szöveg, ami akár szóközöket is tartalmazhat).

class DatumLista
{
    unsigned int darab;
    Datum *datumok;
    string megjegyzes;

    // Spec: statikus adattag, ami a tömb maximális méretét tárolja.
    static unsigned int maxDarab;

public:
    DatumLista(unsigned int darab, const string &megj); // Spec: konstruktor
    ~DatumLista(); // Spec: memória felszabadítása
    DatumLista(const DatumLista &dl); // Spec: másoló konstruktor

    // Spec: beállító és lekérő függvények a megjegyzéshez
    string getMegjegyzes() const;
    void setMegjegyzes(const string &megj);

    // Spec: beállító és lekérő függvények az egyes dátumokhoz
    const Datum &getDatum(unsigned int index) const;
    void setDatum(unsigned int index, const Datum &d);

    // Spec: lekérő függvény a dátumok darabszámához
    unsigned int getDarab() const;

    // Spec: hozzaad függvény — megkap egy dátumot, hozzáadja a listához (maxDarab-ot figyelembe véve!)
    void hozzaad(const Datum &d);

    // Spec: legkorabbi függvény — visszaadja a dátumok közül a legkorábbit
    const Datum &legkorabbi() const;

    // Spec: getMaxDarab(), setMaxDarab()
    static unsigned int getMaxDarab();
    static void setMaxDarab(unsigned int newMaxDarab);
};

} // namespace Naptar

#endif // DATUMLISTA_H
