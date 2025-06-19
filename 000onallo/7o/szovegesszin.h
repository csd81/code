#ifndef SZOVEGESSZIN_H
#define SZOVEGESSZIN_H

#include "rgbszin.h"

class SzovegesSzin : public RGBSzin
{
    string szoveg;
public:
    SzovegesSzin(const string& szoveg);
    ~SzovegesSzin() {}

    SzovegesSzin& operator=(const SzovegesSzin& masik);

    string printCode() const;
};

#endif // SZOVEGESSZIN_H
