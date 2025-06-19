#include "hatarido.h"
#include <iostream>


Datum Hatarido::aktualisDatum = Datum(2025, 6, 6);

Datum Hatarido::getAktualisDatum()
{
    return aktualisDatum;
}

void Hatarido::setAktualisDatum(const Datum &n)
{

    aktualisDatum.setEv(n.getEv());
    aktualisDatum.setHonap(n.getHonap());
    aktualisDatum.setNap(n.getNap());
}

void Hatarido::lejart()
{
    if (this->alphaDatum && this->getAlphaDatum()->kisebbMint(aktualisDatum))
        this->getAlphaDatum()->kiir();
    if (this->betaDatum && this->getBetaDatum()->kisebbMint(aktualisDatum))
        this->getBetaDatum()->kiir();
    if (this->vegsoDatum && this->getVegsoDatum()->kisebbMint(aktualisDatum))
        this->getVegsoDatum()->kiir();
}

void Hatarido::hataridoTorol(const std::string h)
{
    if (h == "alpha"){
        delete alphaDatum;
        alphaDatum = nullptr;}
    else if (h == "beta"){
        delete betaDatum;
        betaDatum = nullptr;}
    else if (h == "vegso"){
        delete vegsoDatum;
        vegsoDatum = nullptr;}
    else std::cout << "nincs ilyen hataridő\n";
}

Hatarido::Hatarido(std::string n) : nev(n)
{
    alphaDatum = new Datum(1970, 1, 1);
    betaDatum = new Datum(1970, 1, 1);
    vegsoDatum = new Datum(1970, 1, 1);
}

Hatarido::Hatarido(const Hatarido &masik)
{
    this->nev = masik.nev;
    if (masik.alphaDatum!=nullptr)
        this->alphaDatum = new Datum(*masik.alphaDatum);
    else
        this->alphaDatum = nullptr;

    if (masik.betaDatum!=nullptr)
        this->betaDatum = new Datum(*masik.betaDatum);
    else
        this->betaDatum = nullptr;

    if (masik.vegsoDatum!=nullptr)
        this->vegsoDatum = new Datum(*masik.vegsoDatum);
    else
        this->vegsoDatum = nullptr;

}

Hatarido::~Hatarido()
{
    delete alphaDatum;
    delete betaDatum;
    delete vegsoDatum;
}


std::string Hatarido::getNev() const
{
    return nev;

}

void Hatarido::setNev(const std::string &newNev)
{
    nev = newNev;
}

Datum *Hatarido::getAlphaDatum() const
{
    return alphaDatum;
}

void Hatarido::setAlphaDatum(const Datum& n)
{
    if (!alphaDatum)
        alphaDatum = new Datum(n.getEv(), n.getHonap(), n.getNap());
    else{
    alphaDatum->setEv(n.getEv());
    alphaDatum->setHonap(n.getHonap());
    alphaDatum->setNap(n.getNap());
    }
}

Datum *Hatarido::getBetaDatum() const
{
    return betaDatum;
}

void Hatarido::setBetaDatum(const Datum& n)
{
    if (!betaDatum)
        betaDatum = new Datum(n.getEv(), n.getHonap(), n.getNap());
    else{
    betaDatum->setEv(n.getEv());
    betaDatum->setHonap(n.getHonap());
    betaDatum->setNap(n.getNap());
    }
}

Datum *Hatarido::getVegsoDatum() const
{
    return vegsoDatum;
}

void Hatarido::setVegsoDatum(const Datum& n)
{
    if (!vegsoDatum)
        vegsoDatum = new Datum(n.getEv(), n.getHonap(), n.getNap());
    else{
    vegsoDatum->setEv(n.getEv());
    vegsoDatum->setHonap(n.getHonap());
    vegsoDatum->setNap(n.getNap());
    }
}
