#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"

class Hallgato : public Szemely
{
    string neptunKod;
    unsigned felevekSzama;
public:
    Hallgato(const string &vnev, const string &knev, unsigned kor,
             const string &neptun, unsigned felevek = 1);
    void kiir() const;
    bool furcsa() const;
};

#endif // HALLGATO_H
