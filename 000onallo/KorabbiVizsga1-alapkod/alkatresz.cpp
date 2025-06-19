#include "alkatresz.h"

int Alkatresz::ertekHatar =450000;
Alkatresz::~Alkatresz()
{

}

string Alkatresz::getGyarto() const
{
    return gyarto;
}

string Alkatresz::getTipus() const
{
    return tipus;
}

void Alkatresz::kiir() const
{
       cout <<  gyarto << " "  << tipus << " "  << ar() << endl;
}

bool operator<(const Alkatresz& a, int i){
    return a.ar()<i;
}

ostream&  operator<<(ostream& os, const Alkatresz& a){
    os <<  a.gyarto << " "  << a.tipus << " "  << a.ar() << endl;
    return os;
}

string Alkatresz::operator!() const
{
    return this->getGyarto() + ' ' + this->getTipus();
}



int Alkatresz::teljesAr() const
{
    if (ar() <= getErtekHatar()) return ar();
    else if (getErtekHatar() < ar() &&  ar() <= 2* getErtekHatar()) return ar() + 14000;
    else return ar() + 32000;
}

int Alkatresz::ar() const{
return 0;
}

int Alkatresz::getErtekHatar()
{
    return ertekHatar;
}

void Alkatresz::setErtekHatar(int newErtekHatar)
{
    ertekHatar = newErtekHatar;
}

Alkatresz::Alkatresz(const string &gyarto, const string &tipus) : gyarto(gyarto),
    tipus(tipus)
{}

Alkatresz::Alkatresz() : gyarto(""),
    tipus("")
{}
