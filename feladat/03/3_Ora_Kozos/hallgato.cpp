#include <iostream>
#include "hallgato.h"

Hallgato::Hallgato(const string &v, const string &k, unsigned int kor, const string &neptun, unsigned int f)
    : Szemely(v, k, kor), neptunKod(neptun), felev(f) {}

// Getter – Neptun kód
const string &Hallgato::getNeptunKod() const {
    return neptunKod;
}

// Getter – félév
unsigned int Hallgato::getFelev() const {
    return felev;
}

// Setter – csak a félévhez
void Hallgato::setFelev(unsigned int f) {
    felev = f;
}


void Hallgato::kiir() const
{
    std::cout << getVezetekNev() << " " << getKeresztNev()
              << ": " << getEletkor() << endl;
    std::cout << "\nneptunKod: " << neptunKod;
    std::cout << "\nfelev: " << felev;
}

bool Hallgato::furcsa() const {
    // Várható minimális életkor adott félévszám alapján
    double elvartKor = 18.0 + (static_cast<double>(felev) - 1) / 2.0;
    return getEletkor() < elvartKor;
}
