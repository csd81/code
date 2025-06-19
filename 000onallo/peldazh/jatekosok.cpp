#include "jatekosok.h"


int Jatekosok::getDarab() const
{
    return darab;
}

int Jatekosok::getMax() const
{
    return max;
}



Karakter *Jatekosok::operator[](int i)
{
    if(i<darab&&i>=0)
        return karakterek[i];
    else return nullptr;
}

Jatekosok& Jatekosok::operator<<(Karakter* k) {
    if (darab < max) {
        karakterek[darab++] = k;
    } else {
        delete k; // memória-szemét elkerülése
    }
    return *this;
}

ostream &operator<<(ostream &os, Jatekosok& j)
{
    os << j.getMax() << " ";
    os << j.getDarab() << " ";
    for (int i=0; i<j.darab; i++){
        os << j.karakterek[i]->getNev() <<" ";
        os << j.karakterek[i]->getPont() <<" ";
        os << j.karakterek[i]->getTipus() <<" ";
    }
    return os;
}



Jatekosok::Jatekosok(int max) : max(max), darab(0) {
    karakterek = new Karakter*[max];
    for (int i = 0; i < max; ++i)
        karakterek[i] = nullptr;  // NULL pointerek a biztonság kedvéért
}

Jatekosok::~Jatekosok()
{
    for (int i=0; i<darab; i++){
        delete karakterek[i];
    }
    delete [] karakterek;
}

int operator+=( Jatekosok& j,  Akcio& a ){
    int counter=0;
    for (int i=0; i<  j.getDarab() ; i++){
        if(j[i]->vegrehajt(a)==true)
            counter++;

    }

    return counter;

}

