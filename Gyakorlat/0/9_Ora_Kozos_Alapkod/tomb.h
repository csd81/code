#ifndef TOMB_H
#define TOMB_H

#include "tombalap.h"

template<typename T, int i>
class Tomb : public TombAlap<T>{
    T tomb[i];

public:
    Tomb() = default;

    int meret() const override{
        return i;
    }

    void beallit(int index, const T& ertek) override{
        if (index >= 0 && index <i)
            tomb[index] = ertek;
    }

    T leker(int index) const override{
        return tomb[index];
    }

    T& elem(int index) override{
        return tomb[index];
    }
    const  T& elem(int index) const override{
        return tomb[index];
    }
};

#endif // TOMB_H

