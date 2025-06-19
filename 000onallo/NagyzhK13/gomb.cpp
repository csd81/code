#include "gomb.h"



int Gomb::getMegnyomasok() const
{
    return megnyomasok;
}

void Gomb::kirajzol()
{
    Elem::kirajzol();
    cout << szoveg
    << megnyomasok << endl;
}

void Gomb::aktival(int egesz)
{
    megnyomasok += egesz;
}

bool Gomb::operator==(const Gomb & g)
{
    if (this->megnyomasok==g.megnyomasok && this->szoveg==g.szoveg) return true;
    else return false;
}

Elem *Gomb::clone() const
{
    return new Gomb(*this);
}

std::string Gomb::getSzoveg() const
{
    return szoveg;
}

Gomb::Gomb(int x, int y, int szelesseg, int magassag, const std::string &szoveg) : Elem(x, y, szelesseg, magassag),
    szoveg(szoveg),
    megnyomasok(0)
{}


Gomb::Gomb(int x, int y, int szelesseg, int magassag, const std::string &szoveg, int megnyomasok) : Elem(x, y, szelesseg, magassag),
    szoveg(szoveg),
    megnyomasok(megnyomasok)
{}
