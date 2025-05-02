#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"
#include <string>

using namespace std;

class Hallgato : public Szemely
{
    string neptunKod;
    unsigned int felev;
public:
    // Konstruktor: félév értéke opcionális (default = 1)
    Hallgato(const string &v, const string &k, unsigned int kor, const string &neptun, unsigned int f = 1);

    const string &getNeptunKod() const;
    unsigned int getFelev() const;
    void setFelev(unsigned int f);
        void kiir() const;
    bool furcsa() const;



};

#endif // HALLGATO_H
