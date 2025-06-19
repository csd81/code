#ifndef MAPPA_H
#define MAPPA_H
#include "fajl.h"
#include <iostream>
using namespace std;

class Mappa
{
    int darab;
    Fajl** fajlok;
public:
    Mappa();
    ~Mappa();


    int getDarab() const;
    friend void operator<<(Mappa& m, const Fajl* f);
    void tartalom();
    friend bool operator>(const Mappa& m1, const Mappa& m2);
    bool operator[](string fajlnev);

};

#endif // MAPPA_H
