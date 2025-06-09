#include <iostream>
#include "tarolo.h"

using namespace std;
using namespace EpicToolbox;

// Spec: A main.cpp-ben legyen egy kisebbTarolo függvény,
// ami megkap két Tarolo típusú objektumot, és visszatér 1, -1, vagy 0-val.
int kisebbTarolo(const Tarolo &t1, const Tarolo &t2)
{
    if (t1.darabLeker() > t2.darabLeker()) return 1;
    else if (t1.darabLeker() < t2.darabLeker()) return -1;
    else return 0;
}

int main()
{
    // Spec: A main függvényben hozz létre egy-egy Tarolo típusú objektumot mindkét konstruktort használva.
    Tarolo t1(5);
    t1.kiir();

    Tarolo t2;
    t2.kiir();

    cout << endl;

    // Spec: Mindkettőt töltsd fel értékekkel.
    t1.hozzaad(111);
    t1.hozzaad(112);
    t1.hozzaad(113);
    t1.hozzaad(114);

    t2.hozzaad(222);
    t2.hozzaad(223);

    t1.kiir();
    t2.kiir();

    cout << endl;

    // Spec: A main függvényben hívd meg ezt a függvényt a kettő létrehozott tárolóra, és jelenítsd meg az eredményt.
    cout << kisebbTarolo(t1, t2) << endl;

    cout << endl;

    // Spec: A függvényt hívd is meg a main-ben. (tartomany)
    cout << t1.tartomany() << endl;
    cout << t2.tartomany() << endl;

    cout << endl;

    // Spec: A függvényt hívd is meg a main-ben. (rendez)
    t1.rendez(false);
    t2.rendez(true);

    t1.kiir();
    t2.kiir();

    cout << endl;

    // Spec: A függvényt hívd is meg a main-ben. (hozzafuz)
    t1.hozzafuz(t2);
    t1.kiir();

    return 0;
}
