#include "felulet.h"

Felulet::Felulet(): meret(0), elemek(nullptr) {}

Felulet::Felulet(const Felulet & masik)
{

    meret= masik.meret;
    elemek = new Elem*[meret];
    for (int i = 0; i<meret; i++){
        elemek[i] = masik.elemek[i]->clone();
    }
}

Felulet::~Felulet()
{
    for (int i=0; i<meret; i++){
        delete elemek[i];
    }
    delete[] elemek;
}

int Felulet::getMeret()
{
    return meret;
}

void Felulet::hozzaad(Elem *e)
{
    Elem** nagyobb = new Elem*[meret+1];
    for (int i=0; i<meret; i++){
        nagyobb[i] = elemek[i];
    }
    nagyobb[meret]= e;
    delete [] elemek;
    elemek = nagyobb;
    meret++;
}

void Felulet::kiir()
{
    for (int i=0; i<meret; i++){
        elemek[i]->kirajzol();
    }
}

Felulet &Felulet::operator++()
{
    for (int i=0; i<meret; i++){
        elemek[i]->aktival();
    }
    return *this;
}
