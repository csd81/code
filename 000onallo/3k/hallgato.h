#ifndef HALLGATO_H
#define HALLGATO_H
#include <iostream>
#include "szemely.h"

class Hallgato : public Szemely
{

    unsigned int felevek;
    std::string neptunKod;
public:
    Hallgato(const std::string &v, const std::string &k, unsigned int kor, const std::string &neptunKod, unsigned int felevek = 1);

    unsigned int getFelevek() const;
    void setFelevek(unsigned int newFelevek);

    std::string getNeptunKod() const;
    void kiir() const;

    void furcsa();
};

#endif // HALLGATO_H
