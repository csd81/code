#ifndef SZOVEGESSZIN_H
#define SZOVEGESSZIN_H

#include "rgbszin.h"

class SzovegesSzin : public RGBSzin
{
    string nev;
public:
    SzovegesSzin(string input);
    string printCode() const override;

};

#endif // SZOVEGESSZIN_H
