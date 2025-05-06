#include <iostream>
#include "Tarolo.h"

bool kisebbTarolo(const EpicToolbox::Tarolo& t1, const EpicToolbox::Tarolo& t2) 
{
    int m1 = t1.getMeret();
    int m2 = t2.getMeret();

    if (m1 > m2) 
        return 1;
    else if (m1 < m2)
        return -1;
    else 
        return 0;
    
}

using namespace EpicToolbox;
int main() {
    Tarolo t1(5);
    t1.kiir();
    t1.hozzaad(6);
    t1.kiir();
    std::cout << "Atlag: " << t1.atlag() << std::endl;
    
    Tarolo t2;
    t2.kiir();
    t2.hozzaad(7);
    t2.kiir();
    std::cout << "Atlag: " << t2.atlag() << std::endl;

    kisebbTarolo(t1, t2) ? std::cout << "t1 nagyobb" : std::cout << "t2 nagyobb";
    t1.tartomany();
    t2.tartomany();
    t1.rendez(true);
    t1.kiir();
    t2.rendez(false);
    t2.kiir();
    t1.hozzafuz(t2);
    t1.kiir();
    return 0;
}