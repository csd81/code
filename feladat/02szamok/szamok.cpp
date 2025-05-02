#include "szamok.h"


namespace Tarolo{

Szamok::Szamok(int m, double kezdo) : meret(m) {
        tomb = new double[meret];
        for (int i = 0 ; i<meret;i++){
            tomb[i] = kezdo;
        }
    };

Szamok::~Szamok(){
        delete[] tomb;
    };

int Szamok::darabLeker() const{
        return meret;
    };

void Szamok::ertekBeallit(
        int index,
        double ertek
        ){
        if (index >=0 && index < meret){
            tomb[index] = ertek;
            // else
            }
    };

double Szamok::ertekLeker(int index) const {
        if (index >=0 && index < meret){
            return tomb[index];}
        else
            return  -1e8;
    };
};

