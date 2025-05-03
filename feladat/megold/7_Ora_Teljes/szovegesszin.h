#ifndef SZOVEGESSZIN_H
#define SZOVEGESSZIN_H

#include "rgbszin.h"

class SzovegesSzin : public RGBSzin
{
	string szoveg;
public:
	SzovegesSzin(const string &sz);

	virtual string printCode() const;
};

#endif // SZOVEGESSZIN_H
