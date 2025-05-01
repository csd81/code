#include "szamok.h"

namespace Tarolo
{

// Szamok::Szamok(unsigned meret, double ertek)
// {
//     tomb = new double[meret];
//     this->meret = meret;

//     for (unsigned i=0; i<meret; i++)
//         tomb[i] = ertek;
// }

Szamok::Szamok(unsigned meret, double ertek):
    tomb(new double[meret]), // ??
    meret(meret)
{
    for (unsigned i=0; i<meret; i++)
        tomb[i] = ertek;
}

Szamok::~Szamok()
{
    delete [] tomb;
}

unsigned int Szamok::darabLeker() const
{
    return meret;
}

void Szamok::ertekBeallit(unsigned int index, double ertek)
{
    if (index < meret)
        tomb[index] = ertek;
}

double Szamok::ertekLeker(unsigned int index) const
{
    if (index < meret)
        return tomb[index];
    else
        return -1e8; //-100000000;
}

}




