#ifndef ADATBEKERO_H
#define ADATBEKERO_H
#include "bevitelimezo.h"

class AdatBekero
{
    BeviteliMezo* * mezok;
    int darab;
public:
    AdatBekero();
    AdatBekero(int darab);

    ~AdatBekero();
    int getDarab() const;
    void operator+=(BeviteliMezo* bm);

    bool operator[](int index);

    friend ostream& operator<<(ostream& os, AdatBekero& a);
};

#endif // ADATBEKERO_H
