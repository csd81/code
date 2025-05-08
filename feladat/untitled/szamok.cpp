#include "szamok.h"

int Szamok::getX() const
{
    return x;
}

void Szamok::setX(int newX)
{
    x = newX;
}

int Szamok::getY() const
{
    return y;
}

void Szamok::setY(int newY)
{
    y = newY;
}

Szamok::Szamok(unsigned int darab, double alap):
    meret(darab)
{
    tomb = new double[meret];

    for (unsigned int i=0; i < meret; i++)
        {
        tomb[i] = alap;
        }
}

Szamok::~Szamok()
{
    delete[] tomb;
}

unsigned int Szamok::darabLeker() const
{
    return meret;
}

void Szamok::ertekBeallit(unsigned int i, double d)
{
    if (i >=0 && i < meret)
        tomb[i] = d;
}

double Szamok::ertekLeker(unsigned int i) const
{
    if (i >=0 && i < meret) {
        return tomb[i];
        } else {
        return -1e8;
        }
}
