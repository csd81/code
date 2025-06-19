#ifndef SZOVEGESSZIN_H
#define SZOVEGESSZIN_H

#include "rgbszin.h"

class SzovegesSzin : public RGBSzin
{   std::string szoveg;
public:
    SzovegesSzin(const std::string &szoveg);
    std::string printCode() const;

};

#endif // SZOVEGESSZIN_H
