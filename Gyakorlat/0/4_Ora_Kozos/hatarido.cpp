#include "hatarido.h"

Datum Hatarido::aktualisDatum(2025, 05, 28);

Hatarido::Hatarido(std::string n) : nev(n) {

    alphaDatum = nullptr;
    betaDatum = nullptr;
    vegsoDatum = nullptr;
}

Hatarido::Hatarido(Hatarido &h) : nev(h.nev)
{
    if (h.alphaDatum){
        alphaDatum    = new Datum(h.alphaDatum->getEv(), h.alphaDatum->getHonap(), h.alphaDatum->getNap());
    } else  alphaDatum    = nullptr;

    if (h.betaDatum){
        betaDatum    = new Datum(h.betaDatum->getEv(), h.betaDatum->getHonap(), h.betaDatum->getNap());

    } else  betaDatum    = nullptr;
    if (h.vegsoDatum){
        vegsoDatum    = new Datum(h.vegsoDatum->getEv(), h.vegsoDatum->getHonap(), h.vegsoDatum->getNap());

    } else  vegsoDatum    = nullptr;
}

Hatarido::~Hatarido()
{
    delete alphaDatum;
    delete betaDatum;
    delete vegsoDatum;

}

Datum Hatarido::getAktualisDatum()
{
    return aktualisDatum;
}

void Hatarido::setAktualisDatum(Datum akt)
{
    aktualisDatum.setEv(akt.getEv());
    aktualisDatum.setHonap(akt.getHonap());
    aktualisDatum.setNap(akt.getHonap());
}

void Hatarido::lejart()
{
    if (alphaDatum && alphaDatum->regebbiMint(aktualisDatum)){
        std::cout << alphaDatum->getEv() <<  alphaDatum->getHonap() << alphaDatum->getNap();
    }

    if (betaDatum && betaDatum->regebbiMint(aktualisDatum)){
        std::cout << betaDatum->getEv() <<  betaDatum->getHonap() << betaDatum->getNap();
    }

    if (vegsoDatum && vegsoDatum->regebbiMint(aktualisDatum)){
        std::cout << vegsoDatum->getEv() <<  vegsoDatum->getHonap() << vegsoDatum->getNap();
    }
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

void Hatarido::setAlphaDatum(const Datum& newAlpha)
{
    if (alphaDatum){
        delete alphaDatum;
    }
    alphaDatum = new Datum(newAlpha);
}

Datum *Hatarido::getBetaDatum() const
{
    return betaDatum;
}

void Hatarido::setBetaDatum(const Datum& newBeta)
{

    if (betaDatum){
        delete betaDatum;
    }
    betaDatum  = new Datum(newBeta);

}

Datum *Hatarido::getVegsoDatum() const
{
    return vegsoDatum;
}

void Hatarido::setVegsoDatum(const Datum& newVegso)
{
    if (vegsoDatum){
        delete vegsoDatum;
    }
    vegsoDatum = new Datum(newVegso);
}



void Hatarido::hataridoTorol(Datum* d)
{
    if (d == alphaDatum) {
        delete alphaDatum;
        alphaDatum = nullptr;
    } else     if (d == betaDatum) {
        delete betaDatum;
        betaDatum = nullptr;
    } else     if (d == vegsoDatum) {
        delete vegsoDatum;
        vegsoDatum = nullptr;
    }
}

void Hatarido::hataridoTorol(const std::string &tipus)
{
    if (tipus == "alpha" && alphaDatum) {
        delete alphaDatum;
        alphaDatum = nullptr;
    } else if (tipus == "beta" && betaDatum) {
        delete betaDatum;
        betaDatum = nullptr;
    } else if (tipus == "vegso" && vegsoDatum) {
        delete vegsoDatum;
        vegsoDatum = nullptr;
    } else {
        std::cout << "Ismeretlen vagy nem letrehozott hatarido: " << tipus << std::endl;
    }
}
