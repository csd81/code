#ifndef RGBSZIN_H
#define RGBSZIN_H

#include "szin.h"

class RGBSzin : public Szin
{ protected:
    unsigned char r, g, b;
public:
    RGBSzin();
    RGBSzin(unsigned char r, unsigned char g, unsigned char b);
    RGBSzin(const Szin &sz);

    unsigned char R() const;
    unsigned char G() const;
    unsigned char B() const;





};

#endif // RGBSZIN_H
