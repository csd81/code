#ifndef JATEKOSOK_H
#define JATEKOSOK_H
#include "karakter.h"

class Jatekosok
{
protected:
    int max;
    int darab;
    Karakter** karakterek;
public:


    Jatekosok(int max);
    ~Jatekosok();

    int getDarab() const;

    int getMax() const;
    Jatekosok& operator<<(Karakter*);
    Karakter* operator[](int i);

    friend int operator+=( Jatekosok& j,  Akcio& a);

    friend  ostream& operator<<(ostream& os, Jatekosok& j);
};

#endif // JATEKOSOK_H
