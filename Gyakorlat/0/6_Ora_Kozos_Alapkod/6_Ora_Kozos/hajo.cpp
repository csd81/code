#include "hajo.h"
#include <iostream>

using namespace std;


Hajo::Hajo(int teherbiras, unsigned int t, unsigned int s) : Jarmu(t, s),
    teherbiras(teherbiras)
{}

void Hajo::kiir() const
{
    Jarmu::kiir();
    cout << ", teherbiras: "<< teherbiras << endl;
}

Jarmu *Hajo::clone() const
{
    return new Hajo(*this);
}
