#include "hatarido.h"
#include <iostream>


Datum Hatarido::aktualisDatum = Datum(2025, 1, 1);

Hatarido::Hatarido(std::string n){
    nev = n;
    alpha  = nullptr;
    beta  = nullptr;
    vegso = nullptr;



};

Hatarido::~Hatarido() {
    delete alpha;
    delete beta;
    delete vegso;
}

Hatarido::Hatarido(const Hatarido& other)
    : nev(other.nev)
{
    alpha = other.alpha ? new Datum(*other.alpha) : nullptr;
    beta  = other.beta  ? new Datum(*other.beta)  : nullptr;
    vegso = other.vegso ? new Datum(*other.vegso) : nullptr;
}


std::string Hatarido::getNev() const {         return nev;     }
void Hatarido::setNev(std::string n){         nev = n;     }


Datum* Hatarido::getAlphaDatum() const {        return alpha;         }
void Hatarido::setAlphaDatum(Datum* al) {  alpha = al;      }

Datum* Hatarido::getBetaDatum() const {         return beta;     }
void Hatarido::setBetaDatum(Datum* b){ beta = b;}

Datum* Hatarido::getVegsoDatum() const {         return vegso;     }
void Hatarido::setVegsoDatum(Datum* v) {vegso = v;}

void Hatarido::setAktualisDatum(const Datum& aktualis){            aktualisDatum = aktualis;        }
Datum Hatarido::getAktualisDatum(){ return aktualisDatum;}


void Hatarido::lejart() const {
    std::cout << "Lejárt határidők a(z) \"" << nev << "\" szoftverhez:\n";
    if (alpha && alpha->kisebbMint(aktualisDatum))
    std::cout << "Alpha: ";
    alpha->kiir();
    std::cout << "\n";


    if (beta && beta->kisebbMint(aktualisDatum))
    std::cout << "Beta: ";
    beta->kiir();
    std::cout     << "\n";

    if (vegso && vegso->kisebbMint(aktualisDatum))
    std::cout << "Végső: ";
    vegso->kiir();
    std::cout     << "\n";
}

void Hatarido::hataridoTorol(std::string tipus){
    if (tipus == "alpha" ){
        delete alpha;
        alpha = nullptr;
    }
    else         if (tipus == "beta" ){
        delete beta;
        beta = nullptr;
    }
    else         if (tipus == "vegso" ){
        delete vegso;
        vegso = nullptr;
    }
}
