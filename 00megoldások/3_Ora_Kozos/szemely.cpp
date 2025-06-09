#include "szemely.h"

#include <iostream>

Szemely::Szemely(const string &v, const string &k, unsigned int kor) :
    vnev(v),
    knev(k),
    eletkor(kor)
{
}

const string &Szemely::getVezetekNev() const
{
    return vnev;
}

const string &Szemely::getKeresztNev() const
{
    return knev;
}

string Szemely::teljesNev() const
{
    return vnev + " " + knev;
}

unsigned int Szemely::getEletkor() const
{
    return eletkor;
}

// Spec: kiir függvény, amely kiírja az adatokat
void Szemely::kiir() const
{
    cout << vnev << " " << knev << ": " << eletkor << endl;
}

// Spec: fiatalabb függvény, paraméter egy másik személy
bool Szemely::fiatalabb(const Szemely &sz)
{
    return eletkor < sz.eletkor;
}
