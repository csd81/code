#include "utvonal.h"

Utvonal::Utvonal(): Halmaz("PATH"), irany(true) {}

void Utvonal::megfordit()
{
    irany = !irany;
}

void Utvonal::kiir() const
{
    std::cout << megnevezes << " " << tarolo.size() << " ";

    if (!irany){
    for (int i = tarolo.size() - 1; i >= 0; i--){
         tarolo[i].kiir();
         cout << " ";
    }
    std::cout << std::endl;
    } else
    Halmaz::kiir();
}

double Utvonal::hossz() const
{
    double sum = 0.0;
    if (tarolo.size()<1) return 0.0;
    else for (size_t i = 0; i < tarolo.size() - 1; ++i) {
    sum += Pont::tavolsag(tarolo[i], tarolo[i + 1]);
}
    return sum;
}
