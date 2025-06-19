#include "adatbekero.h"
#include <sstream>

int AdatBekero::getDarab() const
{
    return darab;
}

void AdatBekero::operator+=(BeviteliMezo* bm)
{
    BeviteliMezo* * uj = new BeviteliMezo*[darab+1];

    for(int i=0; i<darab; i++){
        uj[i] = mezok[i];
    }
    uj[darab] = bm;

    delete[] mezok;
    mezok = uj;
    darab++;
}

ostream & operator<<(ostream& os, AdatBekero& a)
{

    for (int i=0; i< a.darab; i++){
        os << "Megnevezés: " << a.mezok[i]->getMegnevezes();
        os << " Megfelelő: ";
        os << (a.mezok[i]->megfelelo() ? "igen" : "nem megfelelo");
        os << "Érték: ";
        a.mezok[i]->kiir(os);
        os << std::endl;
    }
    return os;

}

bool AdatBekero::operator[](int index)
{
    if (index < 0 || index >= darab) return false;
    return mezok[index]->megfelelo();
}

AdatBekero::AdatBekero() : darab(0)
{
    mezok = nullptr;
}

AdatBekero::AdatBekero(int darab) : darab(darab)
{
    mezok = new BeviteliMezo*[darab];
}

AdatBekero::~AdatBekero()
{
    for(int i=0; i<darab; i++){
        delete mezok[i];
        mezok[i] = nullptr;
    }
    delete [] mezok;
    mezok = nullptr;
}
