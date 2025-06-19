#ifndef SZAMOK_H
#define SZAMOK_H

namespace Tarolo{

class Szamok{
    float * szamok;
    unsigned int meret;
public:
    Szamok(int m, float val = 0);
    
    Szamok(const Szamok& masik);
    ~Szamok();

    unsigned int  darabLeker();

    void ertekBeallit(unsigned int index, float ertek);

    float ertekLeker(unsigned int index);

}; //class


}

#endif