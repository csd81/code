#include "hajo.h"
#include <iostream>
using namespace std;

Hajo::Hajo(unsigned int t, unsigned int s, unsigned int teher):
    Jarmu(t,s),
    teherbiras(teher)
{}

void Hajo::kiir() const
{
    Jarmu::kiir();
    cout << "  teherbiras: " << teherbiras << endl;
}

Hajo *Hajo::clone() const
{
    return new Hajo(*this);
}
