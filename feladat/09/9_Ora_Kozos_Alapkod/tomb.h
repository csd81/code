#include "tombalap.h"

#pragma once

template<typename T, int N>
class Tomb : public TombAlap<T> {
private:
    T tomb[N];

public:
    Tomb() {}

    int meret() const {
        return N;
    }

    void beallit(int index, const T& ertek) {
        if (index >= 0 && index < N) {
            tomb[index] = ertek;
        }
    }

    T leker(int index) const {
        return tomb[index];
    }

    T& elem(int index) {
        return tomb[index];
    }

    const T& elem(int index) const {
        return tomb[index];
    }

    T& operator[](int index) {
        return tomb[index];
    }

    const T& operator[](int index) const {
        return tomb[index];
    }
};
