#pragma once
#include <iostream>

namespace EpicToolbox{

    class Tarolo{
    private:
        int* szamok;
        int meret;
    public:
        Tarolo();
        Tarolo(int n);    
        ~Tarolo();
        int getMeret() const;
        void kiir();
        void hozzaad(int szam);
        double atlag();
        int tartomany();
        void rendez(bool sorrend);
        void hozzafuz(Tarolo t);
    };
    }