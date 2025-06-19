#ifndef TOMB_H
#define TOMB_H
#include "tombalap.h"

template <typename T, int db>
class Tomb :  public TombAlap<T>
{
    T tomb[db];
public:
    Tomb();
    int meret() const override;
    void beallit(int index, T ertek) override;
    T leker(int index) const override;
    T& elem(int index) override;
    const T& elem(int index) const override;

    T& operator[](int index);
    const T& operator[](int index) const;


};

template<typename T, int db>
Tomb<T, db>::Tomb() {}

template<typename T, int db>
int Tomb<T, db>::meret() const
{
    return db;
}

template<typename T, int db>
void Tomb<T, db>::beallit(int index, T ertek)
{
    if(index >=0 && index<db){
        tomb[index] =ertek;
    }
}

template<typename T, int db>
T Tomb<T, db>::leker(int index) const
{
    return tomb[index];
}

template<typename T, int db>
T &Tomb<T, db>::elem(int index)
{
    return tomb[index];
}

template<typename T, int db>
const T &Tomb<T, db>::elem(int index) const
{
    return tomb[index];
}

template<typename T, int db>
T& Tomb<T, db>::operator[](int index){
    return tomb[index];
}

template<typename T, int db>
const T& Tomb<T, db>::operator[](int index) const{
    return tomb[index];
}


#endif // TOMB_H



