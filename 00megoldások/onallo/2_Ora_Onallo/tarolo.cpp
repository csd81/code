#include "tarolo.h"
#include <iostream>

using namespace std;

namespace EpicToolbox {

// Spec: 1. konstruktor - paraméterként méretet vár, feltöltés 1,2,3,... értékekkel.
Tarolo::Tarolo(unsigned int db) : darab(db)
{
    tomb = new int[db];
    for (unsigned int i = 0; i < db; i++)
        tomb[i] = i;
}

// Spec: 2. konstruktor - bekéri a méretet és az elemeket.
Tarolo::Tarolo()
{
    cout << "Kerem a tomb meretet: ";
    cin >> darab;
    tomb = new int[darab];
    for (unsigned int i = 0; i < darab; i++)
    {
        cout << "Kerem a(z) " << i + 1 << ". elemet: ";
        cin >> tomb[i];
    }
}

// Spec: Az osztály destruktora szabadítsa fel a tömböt.
Tarolo::~Tarolo()
{
    delete[] tomb;
}

// Spec: kiir függvény
void Tarolo::kiir() const
{
    for (unsigned int i = 0; i < darab; i++)
    {
        if (i > 0)
            cout << ", ";
        cout << tomb[i];
    }
    cout << endl;
}

// Spec: hozzaad függvény
void Tarolo::hozzaad(int ertek)
{
    int *uj = new int[darab + 1];
    for (unsigned int i = 0; i < darab; i++)
        uj[i] = tomb[i];
    uj[darab] = ertek;
    darab++;
    delete[] tomb;
    tomb = uj;
}

// Spec: atlag függvény
double Tarolo::atlag() const
{
    double sum = 0.0;
    for (unsigned int i = 0; i < darab; i++)
        sum += tomb[i];
    return sum / darab;
}

// Spec: szükséges a kisebbTarolo függvényhez
unsigned int Tarolo::darabLeker() const
{
    return darab;
}

// Spec: tartomany metódus
int Tarolo::tartomany() const
{
    int max_idx = 0, min_idx = 0;
    for (unsigned int i = 0; i < darab; i++)
    {
        if (tomb[i] > tomb[max_idx])
            max_idx = i;
        if (tomb[i] < tomb[min_idx])
            min_idx = i;
    }
    return tomb[max_idx] - tomb[min_idx];
}

// Spec: rendez metódus
void Tarolo::rendez(bool novekvo)
{
    for (unsigned int i = 0; i < darab - 1; i++)
    {
        unsigned int idx = i;
        if (novekvo)
        {
            for (unsigned int k = i + 1; k < darab; k++)
            {
                if (tomb[k] < tomb[idx])
                    idx = k;
            }
        }
        else
        {
            for (unsigned int k = i + 1; k < darab; k++)
            {
                if (tomb[k] > tomb[idx])
                    idx = k;
            }
        }

        if (idx != i)
        {
            int csere = tomb[i];
            tomb[i] = tomb[idx];
            tomb[idx] = csere;
        }
    }
}

// Spec: hozzafuz metódus
void Tarolo::hozzafuz(const Tarolo &masik)
{
    // Spec: paraméterben kapott tároló elemeit hozzáfűzi az aktuálishoz
    int *uj = new int[this->darab + masik.darab];
    for (unsigned int i = 0; i < this->darab; i++)
        uj[i] = this->tomb[i];
    for (unsigned int i = 0; i < masik.darab; i++)
        uj[this->darab + i] = masik.tomb[i];
    this->darab += masik.darab;
    delete[] this->tomb;
    this->tomb = uj;
}

} // namespace EpicToolbox
