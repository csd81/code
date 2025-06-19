#ifndef AKCIO_H
#define AKCIO_H

#include <iostream>
using namespace std;

class Akcio
{
string tipus;
int ertek;
int nehezseg;
public:

    Akcio(const string &tipus, int ertek, int nehezseg);
    string getTipus() const;
    int getErtek() const;
    int getNehezseg() const;
    double operator*();
};

#endif // AKCIO_H
