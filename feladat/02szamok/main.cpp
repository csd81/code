#include <iostream>
#include "szamok.h"


void kiir(const Tarolo::Szamok& sz) {
    int n = sz.darabLeker();
    for (int i = 0; i < n; ++i) {
        std::cout << sz.ertekLeker(i);
        if (i != n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}




int main()
{
    Tarolo::Szamok sz1(5,1.5);
    Tarolo::Szamok sz2(3);
    sz2.ertekBeallit(0, 3.14);
    sz2.ertekBeallit(1, 2.71);
    sz2.ertekBeallit(2, 1.41);
    std::cout << "sz1: ";
    kiir(sz1);

    std::cout << "sz2: ";
    kiir(sz2);

    return 0;
}
