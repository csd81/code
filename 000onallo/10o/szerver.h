#ifndef SZERVER_H
#define SZERVER_H
#include "karakter.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Szerver
{
    vector<Karakter*> karakterek;
public:
    ~Szerver();
    void betolt();
    void listaz() const;
    Karakter* legtobbElet() const;
    string csata(const string& nev1, const string& nev2) const;
    void tornaSzimulacio() const;
};

#endif // SZERVER_H
