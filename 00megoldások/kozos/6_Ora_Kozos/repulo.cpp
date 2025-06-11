#include "repulo.h"

#include <iostream>

using namespace std;

// Konstruktor, ami meghívja az ősosztály konstruktorát, és inicializálja az új adattagot.
Repulo::Repulo(unsigned int t, unsigned int s, unsigned int u):
    Jarmu(t,s),
    utasok(u)
{
}

// A Jarmu osztály kiir függvényének implementációja a gyerekosztályban.
void Repulo::kiir() const
{
    cout << "tomeg: " << tomeg << ", sebesseg: " << sebesseg << ", utasok: " << utasok << endl;
}
