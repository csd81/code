#include "egyebalkatresz.h"

string EgyebAlkatresz::getLeiras() const
{
    return leiras;
}

int EgyebAlkatresz::ar() const
{
    return aar;
}

void EgyebAlkatresz::kiir() const
{
       cout <<  this->getGyarto() << " "  << this->getTipus()<< " "  << this->getLeiras() <<" "<< ar() << endl;
}


EgyebAlkatresz::EgyebAlkatresz(const string &gyarto, const string &tipus, const string &leiras, int ar) : Alkatresz(gyarto, tipus),
    leiras(leiras),
    aar(ar)
{}
