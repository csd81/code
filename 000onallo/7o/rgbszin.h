#ifndef RGBSZIN_H
#define RGBSZIN_H

#include "szin.h"

class RGBSzin : public Szin
{
protected:
    unsigned char r;
    unsigned char g;
    unsigned char b;
    void setRGB(unsigned char rr, unsigned char gg, unsigned char bb);
public:
    RGBSzin();
    RGBSzin(const Szin& szin);
    RGBSzin(const RGBSzin& masik);
    RGBSzin& operator=(const RGBSzin& masik);
    RGBSzin( unsigned char r, unsigned char g, unsigned char b );
    virtual ~RGBSzin() {}
    unsigned char R() const override;
    unsigned char G() const override;
    unsigned char B() const override;


};

#endif // RGBSZIN_H
