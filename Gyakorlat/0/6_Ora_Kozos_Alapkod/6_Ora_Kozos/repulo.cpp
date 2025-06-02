#include "repulo.h"
#include <iostream>

using namespace std;


Repulo::Repulo(int utasok, unsigned int t, unsigned int s) : Jarmu(t, s),
    utasok(utasok)
{}

void Repulo::kiir() const
{
    Jarmu::kiir();
    cout << ", utasok: "<< utasok << endl;
}

Jarmu *Repulo::clone() const
{
    return new Repulo(*this);
}
