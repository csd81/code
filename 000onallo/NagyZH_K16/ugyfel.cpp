#include "ugyfel.h"



Ugyfel::Ugyfel(const string &nev) : nev(nev),
    meret(0),
    szamlak(nullptr)
{}

Ugyfel::~Ugyfel()
{
    for (int i = 0; i < meret; i++){
        delete szamlak[i];
    }
    delete [] szamlak;
}


void Ugyfel::kiir() const
{
    cout << nev << "\n";
    for (int i = 0; i < meret; i++)
    {
        szamlak[i]->kiir();
    }

}

Ugyfel &Ugyfel::operator+=(Szamla *sz)
{
    bool vanhitel=false;
    for (int i = 0; i < meret; i++){
        if (szamlak[i]->getTipus()=="h")
            vanhitel=true;
    }
    if (!vanhitel){
    Szamla ** uj = new Szamla *[meret+1];
    for (int i = 0; i < meret; i++){
        uj[i] = szamlak[i];
    }
    uj[meret] = sz;
    delete[] szamlak;
    szamlak=uj;
    meret++;
    }
    return *this;
}

Szamla * Ugyfel::alkalmaz(Tranzakcio & t)
{

    for (int i = 0; i < meret; i++){
        if (szamlak[i]->vegrehajt(t)){
            return szamlak[i];
        }
    }
    return nullptr;
}

Szamla * Ugyfel::operator[](int i)
{
    if (i>=0&&i<meret)
        return szamlak[i];
    else
        return nullptr;
}
