#include "szamok.hpp"

Szamok::Szamok(unsigned m, double ertek) {
    tomb = new double[m];
    this->meret  = m;    

    for (unsigned i = 0; i < m; i++) {
        tomb[i] = ertek;
    }
}