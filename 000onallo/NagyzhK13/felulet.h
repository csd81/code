#ifndef FELULET_H
#define FELULET_H

#include "elem.h"
class Felulet
{
    int meret;
    Elem** elemek;


public:
    Felulet();
    Felulet(const Felulet&);
    ~Felulet();

    int getMeret();
    void hozzaad(Elem* e);
    void kiir();
    Felulet& operator++();
};

#endif // FELULET_H
