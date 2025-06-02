#include "rgbszin.h"



RGBSzin::RGBSzin(unsigned char r, unsigned char g, unsigned char b) : r(r),
    g(g),
    b(b)
{}

RGBSzin::RGBSzin(const Szin &s) : r(s.R()), g(s.G()), b(s.B()) {}

RGBSzin::RGBSzin() : r(0), g(0), b(0) {}


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
