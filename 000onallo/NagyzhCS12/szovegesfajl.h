#ifndef SZOVEGESFAJL_H
#define SZOVEGESFAJL_H

#include "fajl.h"
#include <iostream>
using namespace std;

class SzovegesFajl : public Fajl
{
    std::string tartalom;
    static std::string utvonal;
public:
    SzovegesFajl(const std::string &nev, int meret, int fontossag, const std::string &tartalom);
    std::string getTartalom() const;
    void adatok() const;

    void operator+=(const string& szoveg);
    static std::string getUtvonal();
    static void setUtvonal(const std::string &newUtvonal);
};

#endif // SZOVEGESFAJL_H
