#ifndef HALLGATO_H
#define HALLGATO_H

#include "szemely.h"

class Hallgato : public Szemely
{
    std::string neptun;
    unsigned int felevek;


public:
    Hallgato(const std::string& vnev, const std::string& knev, unsigned int kor,
             const std::string& neptunKod, unsigned int felev = 1);





    void kiir() const override;

    bool furcsa() const;


    unsigned int getFelevek() const;
    void setFelevek(unsigned int newFelevek);
    std::string getNeptun() const;
};

#endif // HALLGATO_H
