#ifndef TRANZAKCIO_H
#define TRANZAKCIO_H
#include <string>
#include <iostream>
using namespace std;

class Tranzakcio
{   string szamlaszam;
    int osszeg;
    bool jovairas;
public:
    Tranzakcio(const string &szamlaszam, int osszeg, bool jovairas);

    string getSzamlaszam() const;
    int getOsszeg() const;
    bool getJovairas() const;

    bool operator*();
    bool CDV();

    friend ostream& operator<<(ostream&, Tranzakcio t);
};

#endif // TRANZAKCIO_H


