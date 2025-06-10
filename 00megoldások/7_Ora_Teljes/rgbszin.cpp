#include "rgbszin.h"

RGBSzin::RGBSzin(unsigned char r, unsigned char g, unsigned char b):
	r(r),
	g(g),
	b(b)
{
}

RGBSzin::RGBSzin():
	r(0),
	g(0),
	b(0)
{
}

RGBSzin::RGBSzin(const Szin &sz):
	r(sz.R()),
	g(sz.G()),
	b(sz.B())
{
}

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
