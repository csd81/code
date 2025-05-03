#ifndef RGBSZIN_H
#define RGBSZIN_H

#include "szin.h"

class RGBSzin : public Szin
{
protected:
	unsigned char r, g, b;
public:
	RGBSzin(unsigned char r, unsigned char g, unsigned char b);
	RGBSzin();
	RGBSzin(const Szin &sz);

	virtual unsigned char R() const;
	virtual unsigned char G() const;
	virtual unsigned char B() const;
};

#endif // RGBSZIN_H
