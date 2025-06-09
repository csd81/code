#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"

// Spec: Származtass egy Hallgato osztályt a Szemely-ből.
class Hallgato : public Szemely
{
    // Spec: Az osztály tárolja még a hallgató Neptun-kódját és befejezett féléveinek számát.
    string neptun;
    unsigned int felevek;
public:
    // Spec: Ezeket is kapja meg a konstruktor,
    // de a félévek száma legyen elhagyható, ekkor az értéke legyen 1.
    Hallgato(const string &v, const string &k, unsigned int kor, const string &neptun, unsigned int felevek = 1);

    // Spec: Getter függvény minden adathoz legyen.
    const string &getNeptun() const;
    unsigned int getFelevek() const;

    // Spec: Setter csak a félévek számához.
    void setFelevek(unsigned int value);

    // Spec: Készíts a Hallgato osztályba egy furcsa függvényt.
    // A függvény igazzal térjen vissza, ha a hallgató fiatalabb,
    // mint ahogy a féléveinek száma sugallja (általában 18 éves az első félévkor).
    bool furcsa() const;

    // Spec: A Szemely osztályban van egy kiir függvény, amely kiírja az adatait.
    // Írd felül ezt a függvényt a Hallgato-ba,
    // amely kiír minden adatot az ősosztály kiir függvényét felhasználva.
    void kiir() const;
};

#endif // HALLGATO_H
