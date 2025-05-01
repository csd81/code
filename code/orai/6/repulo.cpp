#include "repulo.h"
#include <iostream>
using namespace std;

Repulo::Repulo(unsigned int t, unsigned int s, unsigned int letszam) :
    Jarmu(t, s),
    utasletszam(letszam)
{}

void Repulo::kiir() const
{
    Jarmu::kiir();
    cout << "  utasletszam: " << utasletszam << endl;
}

Repulo *Repulo::clone() const
{
    return new Repulo(*this);
}
