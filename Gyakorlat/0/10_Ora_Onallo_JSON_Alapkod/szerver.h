#ifndef SZERVER_H
#define SZERVER_H
#include <vector>
#include <iostream>
#include <fstream>
#include "karakter.h"
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Szerver
{
    vector<Karakter*> karakterek;
public:
    Szerver();
    ~Szerver();
    void betolt();
    void listaz();
    Karakter* legtobbElet();
    string csata(string  n1, string n2);
    void tornaSzimulacio();

};

#endif // SZERVER_H








