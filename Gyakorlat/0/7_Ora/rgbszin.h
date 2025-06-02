#ifndef RGBSZIN_H
#define RGBSZIN_H

#include "szin.h"

class RGBSzin : public Szin
{
protected:
    unsigned char r, g, b;
public:
    RGBSzin(unsigned char r, unsigned char g, unsigned char b);
    RGBSzin(const Szin &s);
    RGBSzin();

    unsigned char R() const override;
    unsigned char G() const override;
    unsigned char B() const override;
};

#endif // RGBSZIN_H
