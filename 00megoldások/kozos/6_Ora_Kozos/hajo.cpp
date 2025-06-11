#include "hajo.h"

#include <iostream>

using namespace std;

// Konstruktor, ami meghívja az ősosztály konstruktorát, és inicializálja az új adattagot.
Hajo::Hajo(unsigned int t, unsigned int s, unsigned int teher):
    Jarmu(t,s),
    teherbiras(teher)
{
}

// A Jarmu osztály kiir függvényének implementációja a gyerekosztályban.
void Hajo::kiir() const
{
    cout << "tomeg: " << tomeg << ", sebesseg: " << sebesseg << ", teherbiras: " << teherbiras << endl;
}
