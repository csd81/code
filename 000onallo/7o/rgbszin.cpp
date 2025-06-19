#include "rgbszin.h"

void RGBSzin::setRGB(unsigned char rr, unsigned char gg, unsigned char bb)
{
    r = rr; g = gg; b = bb;
}

RGBSzin::RGBSzin() : r(0), g(0), b(0) {}

RGBSzin::RGBSzin(const RGBSzin& masik){
    this->r=masik.r;
    this->g=masik.g;
    this->b=masik.b;
}

RGBSzin &RGBSzin::operator=(const RGBSzin &masik)
{
    if (this!=&masik)
    {
    this->r=masik.r;
    this->g=masik.g;
    this->b=masik.b;
    }
    return *this;

}

RGBSzin::RGBSzin(const Szin& szin){
    r=szin.R();
    g=szin.G();
    b=szin.B();
}

RGBSzin::RGBSzin(unsigned char r, unsigned char g, unsigned char b)
    : r(r), g(g), b(b)
{}

unsigned char RGBSzin::R() const
{
    return r;
}

unsigned char RGBSzin::G() const
{
    return g;
}

unsigned char RGBSzin::B() const
{
    return b;
}
