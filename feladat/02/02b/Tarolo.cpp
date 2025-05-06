#include <iostream>
#include "Tarolo.h"

using namespace EpicToolbox;

Tarolo::Tarolo(int n) : meret(n) {
    szamok = new int[meret];
    for (int i = 0; i < meret; ++i)
        szamok[i] = i + 1;
}    

Tarolo::Tarolo()    {   
    std::cout << "Kerek egy szamot: ";
    std::cin >> meret;
    szamok = new int[meret];
    std::cout << "Kerek " << meret << " szamot  a tömbhöz: ";
    for (int i = 0; i < meret; ++i){
    std::cin >> szamok[i];
    }            
}

Tarolo::~Tarolo(){
    delete[] szamok;
    szamok = nullptr;
}

int Tarolo::getMeret() const {
    return meret;
}

void Tarolo::kiir(){
    std::cout << "A tomb elemei: ";
    for (int i = 0; i < meret; ++i){
        std::cout << szamok[i] << " ";
    }
    std::cout << std::endl;
}

void Tarolo::hozzaad(int szam){
    int* ujTomb = new int[meret + 1];
    for (int i = 0; i < meret; ++i){
        ujTomb[i] = szamok[i];
    }
    ujTomb[meret] = szam;
    delete[] szamok;
    szamok = ujTomb;
    meret++;    
}

double Tarolo::atlag(){
    double osszeg = 0;
    for (int i = 0; i < meret; ++i){
        osszeg += szamok[i];
    }
    return osszeg / meret;
}

int Tarolo::tartomany() {
    int min = szamok[0];
    int max = szamok[0];
    for (int i = 1; i < meret; ++i) {
        if (szamok[i] < min) {
            min = szamok[i];
        }
        if (szamok[i] > max) {
            max = szamok[i];
        }
    }
    return max - min;
}

void Tarolo::rendez(bool sorrend){
    for (int i = 0; i < meret - 1; ++i) { // Outer loop for passes
        for (int j = 0; j < meret - i - 1; ++j) {  // Inner loop for comparisons
            if ((sorrend && szamok[j] > szamok[j + 1])  // if sorting in ascending order
            || (!sorrend && szamok[j] < szamok[j + 1]))  // if sorting in descending order
            { 
                int temp = szamok[j]; // Swap
                szamok[j] = szamok[j + 1];
                szamok[j + 1] = temp;
            }
        }
    }
}


void Tarolo::hozzafuz(Tarolo t){
    int* ujTomb = new int[meret + t.getMeret()];
    for (int i = 0; i < meret; ++i){
        ujTomb[i] = szamok[i];
    }
    for (int i = 0; i < t.getMeret(); ++i){
        ujTomb[meret + i] = t.szamok[i];
    }
    delete[] szamok;
    szamok = ujTomb;
    meret += t.getMeret();
}


    