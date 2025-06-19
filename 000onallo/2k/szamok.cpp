#include "szamok.h"

namespace Tarolo{

Szamok::Szamok(int m, float val) : meret(m) {
    szamok = new float[meret];

    for (int i=0; i<meret; i++)    {
        szamok[i] = val;    
    }
}

Szamok::Szamok(const Szamok& masik){
    this->meret = masik.meret;
    this->szamok = new float[meret];
    for (unsigned int i=0; i<meret; i++)    {
        this->szamok[i] = masik.szamok[i];
    }    
}    



Szamok::~Szamok(){         
    delete[]  szamok;    
}    

unsigned int Szamok::darabLeker(){
    return meret;
}


void Szamok::ertekBeallit(unsigned int index, float ertek){
        if(index<meret && index >=0){
        szamok[index] = ertek;
    }
}

float Szamok::ertekLeker(unsigned int index){
            if(index<meret && index >=0){
        return szamok[index];
    } else
    return -10e8;
}
   
}