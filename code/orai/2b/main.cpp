#include <iostream>
#include "szamok.h"

using namespace std;

// class Szamok
// {
//     double *tomb;
//     unsigned meret;
// public:
//     unsigned getMeret(){
//         return meret;
//     }
//     void init(unsigned m)
//     {
//         this->tomb = new double[m];
//         this->meret = m;
//     }
// };

// struct SzamokS
// {
//     double *tomb;
//     unsigned meret;
// };

// unsigned getMeret(SzamokS &sz)
// {
//     return sz.meret;
// }

// void init(SzamokS &s, unsigned meret)
// {
//     s.tomb = new double[meret];
//     s.meret = meret;
// }

void kiir(const Tarolo::Szamok &sz)
{
    for (unsigned i=0; i<sz.darabLeker(); i++)
    {
        cout << sz.ertekLeker(i) << ", ";
    }
    cout << endl;
}

int main()
{
    // Szamok sz;
    // sz.init(6);
    // cout << sz.getMeret() << endl;

    // Szamok sz2;
    // sz2.init(10);
    // cout << sz2.getMeret() << endl;

    // SzamokS s;
    // init(s, 6);
    // cout << getMeret(s) << endl;

    Tarolo::Szamok sz1(4);
    Tarolo::Szamok sz2(7, -1.2);

    // Szamok *sz = new Szamok(8);
    // delete sz;

    cout << sz1.darabLeker() << endl;
    cout << sz2.darabLeker() << endl;

    cout << sz1.ertekLeker(1) << endl;
    cout << sz1.ertekLeker(5) << endl;

    sz1.ertekBeallit(2, 2.5);
    sz1.ertekBeallit(3, -12.65);
    sz2.ertekBeallit(0, 2212.5);
    sz2.ertekBeallit(3, 2.635);
    sz2.ertekBeallit(5, 512.55);
    sz2.ertekBeallit(78, 512.55);


    kiir(sz1);
    kiir(sz2);

    {
        Tarolo::Szamok masolat = sz1;
        Tarolo::Szamok masolat2 = sz1;
        masolat.ertekBeallit(3,2131233213.32);
        cout << masolat2.ertekLeker(3) << endl;
    }
    cout << "DSADASDASDSADSSD" << endl;


    return 0;
}
