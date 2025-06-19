#ifndef KARAKTER_H
#define KARAKTER_H
#include <iostream>
#include <fstream>
#include <fstream>
using namespace std;

class Karakter
{

    std::string nev;
    int szint;
public:
    Karakter(std::string nev, int szint);
    virtual ~Karakter();
    std::string getNev() const;
    int getSzint() const;

    virtual int eletero() const = 0;
    virtual int sebzes() const  = 0;
    virtual void kiir() const  = 0;
};

#endif // KARAKTER_H
