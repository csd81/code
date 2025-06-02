#ifndef KARAKTER_H
#define KARAKTER_H
#include <iostream>
using namespace std;

class Karakter
{
    string nev;
    int szint;
public:
    Karakter(const string &nev, int szint);
    virtual ~Karakter();
    virtual int eletero() const = 0;
    virtual int sebzes() const = 0;
    virtual void kiir() const = 0;
    string getNev() const;
    int getSzint() const;
};

#endif // KARAKTER_H







