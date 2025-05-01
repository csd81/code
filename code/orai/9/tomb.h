#ifndef TOMB_H
#define TOMB_H

#include "tombalap.h"

template <class Tipus, int Meret>
class Tomb : public TombAlap<Tipus>
{
    Tipus tomb[Meret];
public:
    int meret() const
    {
        return Meret;
    }
    void beallit(int index, const Tipus &ertek);
    Tipus leker(int index) const
    {
        return tomb[index];
    }
    Tipus &operator[](int index)
    {
        return tomb[index];
    }
    const Tipus &operator[](int index) const
    {
        return tomb[index];
    }
    Tipus &elem(int index)
    {
        return tomb[index];
    }
    const Tipus &elem(int index) const
    {
        return tomb[index];
    }
};

template<class Tipus, int Meret>
void Tomb<Tipus, Meret>::beallit(int index, const Tipus &ertek)
{
    if (0<=index && index<Meret)
    {
        tomb[index] = ertek;
    }
}

#endif // TOMB_H
