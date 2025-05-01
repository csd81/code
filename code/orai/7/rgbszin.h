#ifndef RGBSZIN_H
#define RGBSZIN_H

#include "szin.h"

class RGBSzin : public Szin
{
    unsigned char r, g, b;
public:
    RGBSzin(unsigned char r, unsigned char g, unsigned char b);
    RGBSzin();
    unsigned char R() const override;
    unsigned char G() const override;
    unsigned char B() const override;
protected:
    void setR(unsigned char r);
    void setG(unsigned char g);
    void setB(unsigned char b);
};

#endif // RGBSZIN_H
//