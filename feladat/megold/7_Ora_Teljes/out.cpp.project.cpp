=== 7_Ora_Teljes.pro ===
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    szin.cpp \
    rgbszin.cpp \
    feketefeher.cpp \
    szurke.cpp \
    szovegesszin.cpp

HEADERS += \
    szin.h \
    rgbszin.h \
    feketefeher.h \
    szurke.h \
    szovegesszin.h

=== feketefeher.cpp ===
#include "feketefeher.h"

FeketeFeher::FeketeFeher(bool fekete):
	fekete(fekete)
{
}

unsigned char FeketeFeher::R() const
{
	if (fekete) return 0;
	else return 255;
}

unsigned char FeketeFeher::G() const
{
	if (fekete) return 0;
	else return 255;
}

unsigned char FeketeFeher::B() const
{
	if (fekete) return 0;
	else return 255;
}

=== feketefeher.h ===
#ifndef FEKETEFEHER_H
#define FEKETEFEHER_H

#include "szin.h"

class FeketeFeher : public Szin
{
	bool fekete;
public:
	FeketeFeher(bool fekete);
	virtual unsigned char R() const;
	virtual unsigned char G() const;
	virtual unsigned char B() const;
};

#endif // FEKETEFEHER_H

=== main.cpp ===
#include <iostream>
#include "szin.h"
#include "rgbszin.h"
#include "feketefeher.h"
#include "szurke.h"
#include "szovegesszin.h"

using namespace std;

void szintKiir(const Szin * const sz)
{
	cout << "(" << int(sz->R()) << "," << int(sz->G()) << "," << int(sz->B()) << ")" << endl;
}

int main()
{

	// RGBSzin teszt: konstruktor, destruktor
	cout << endl;
	cout << "RGBSzin teszt: konstruktor, destruktor" << endl;
	Szin *szin1=new RGBSzin(123,54,65);
	delete szin1;

	// RGBSzin teszt: R, G, B függvények
	cout << endl;
	cout << "RGBSzin teszt: R, G, B" << endl;
	Szin *szin2=new RGBSzin(29,124,243);
	szintKiir(szin2); // (29,124,243)
	delete szin2;
	szin2=new RGBSzin();
	szintKiir(szin2); // (0,0,0)
	delete szin2;

	// FeketeFeher teszt: R, G, B függvények
	cout << endl;
	cout << "FeketeFeher teszt: R, G, B" << endl;
	Szin *szin3=new FeketeFeher(true);
	szintKiir(szin3); // (0,0,0)
	delete szin3;
	szin3=new FeketeFeher(false);
	szintKiir(szin3); // (255,255,255)
	delete szin3;

	// Szurke teszt: R, G, B függvények
	cout << endl;
	cout << "Szurke teszt: R, G, B" << endl;
	Szin *szin4=new Szurke(0);
	szintKiir(szin4); // (0,0,0)
	delete szin4;
	szin4=new Szurke(1);
	szintKiir(szin4); // (255,255,255)
	delete szin4;
	szin4=new Szurke(0.5);
	szintKiir(szin4); // (127,127,127)
	delete szin4;
	szin4=new Szurke(0.8);
	szintKiir(szin4); // (204,204,204)
	delete szin4;

	// Szin teszt: szamotHexava, hexatSzamma függvények
	cout << endl;
	cout << "Szin teszt: szamotHexava, hexatSzamma" << endl;
	cout << Szin::szamotHexava(0) << endl; // 0
	cout << Szin::szamotHexava(5) << endl; // 5
	cout << Szin::szamotHexava(9) << endl; // 9
	cout << Szin::szamotHexava(10) << endl; // A
	cout << Szin::szamotHexava(12) << endl; // C
	cout << Szin::szamotHexava(15) << endl; // F
	cout << Szin::hexatSzamma('0') << endl; // 0
	cout << Szin::hexatSzamma('3') << endl; // 3
	cout << Szin::hexatSzamma('9') << endl; // 9
	cout << Szin::hexatSzamma('A') << endl; // 10
	cout << Szin::hexatSzamma('E') << endl; // 14
	cout << Szin::hexatSzamma('F') << endl; // 15

	// Szin teszt: printCode függvény
	cout << endl;
	cout << "Szin teszt: printCode" << endl;
	Szin *szin5=new RGBSzin(120,65,234);
	cout << szin5->printCode() << endl; // #7841EA
	delete szin5;
	szin5=new RGBSzin(6,54,15);
	cout << szin5->printCode() << endl; // #06360F
	delete szin5;
	szin5=new RGBSzin(212,200,253);
	cout << szin5->printCode() << endl; // #D4C8FD
	delete szin5;
	szin5=new RGBSzin(128,96,177);
	cout << szin5->printCode() << endl; // #8060B1
	delete szin5;
	szin5=new FeketeFeher(false);
	cout << szin5->printCode() << endl; // #FFFFFF
	delete szin5;
	szin5=new Szurke(0.4);
	cout << szin5->printCode() << endl; // #666666
	delete szin5;

	// SzovegesSzin teszt: konstruktor, R, G, B függvények
	cout << endl;
	cout << "SzovegesSzin teszt: konstruktor, R, G, B" << endl;
	Szin *szin6=new SzovegesSzin("piros");
	szintKiir(szin6); // (255,0,0)
	delete szin6;
	szin6=new SzovegesSzin("sarga");
	szintKiir(szin6); // (255,255,0)
	delete szin6;
	szin6=new SzovegesSzin("kek");
	szintKiir(szin6); // (0,0,255)
	delete szin6;
	szin6=new SzovegesSzin("ilyenincs");
	szintKiir(szin6); // (0,0,0)
	delete szin6;

	// SzovegesSzin teszt: konstruktor hexa formában
	cout << endl;
	cout << "SzovegesSzin teszt: konstruktor hexa forma" << endl;
	Szin *szin7=new SzovegesSzin("#E4CB27");
	szintKiir(szin7); // (228,203,39)
	delete szin7;
	szin7=new SzovegesSzin("#D4C8FD");
	szintKiir(szin7); // (212,200,253)
	delete szin7;
	szin7=new SzovegesSzin("#FF00FF");
	szintKiir(szin7); // (255,0,255)
	delete szin7;

	// SzovegesSzin teszt: printCode függvény
	cout << endl;
	cout << "SzovegesSzin teszt: printCode" << endl;
	Szin *szin8=new SzovegesSzin("#666666");
	cout << szin8->printCode() << endl; // #666666
	delete szin8;
	szin8=new SzovegesSzin("magenta");
	cout << szin8->printCode() << endl; // magenta
	delete szin8;
	szin8=new SzovegesSzin("nincs ilyen ezert fekete lesz");
	cout << szin8->printCode() << endl; // fekete
	delete szin8;

	// Szin teszt: megegyezik függvény
	cout << endl;
	cout << "Szin teszt: megegyezik" << endl;
	Szin *szin9=new RGBSzin(212,200,253);
	Szin *szin10=new Szurke(1);
	Szin *szin11=new SzovegesSzin("#D4C8FD");
	Szin *szin12=new SzovegesSzin("feher");
	szintKiir(szin9); // (212,200,253)
	szintKiir(szin10); // (255,255,255)
	szintKiir(szin11); // (212,200,253)
	szintKiir(szin12); // (255,255,255)
	cout << szin9->megegyezik(*szin10) << endl; // 0
	cout << szin10->megegyezik(*szin12) << endl; // 1
	cout << szin12->megegyezik(*szin11) << endl; // 0
	cout << szin11->megegyezik(*szin9) << endl; // 1
	delete szin9;
	delete szin10;
	delete szin11;
	delete szin12;

	// RGBSzin teszt: konstruktor másolat
	cout << endl;
	cout << "RGBSzin teszt: konstruktor masolat" << endl;
	Szin *szin13=new SzovegesSzin("#E4CB27");
	szintKiir(szin13); // (228,203,39)
	Szin *szin14=new RGBSzin(*szin13);
	szintKiir(szin14); // (228,203,39)
	delete szin13;
	delete szin14;
	szin13=new Szurke(0.3);
	szintKiir(szin13); // (76,76,76)
	szin14=new RGBSzin(*szin13);
	szintKiir(szin14); // (76,76,76)
	delete szin13;
	delete szin14;

	return 0;
}

=== out.cpp.project ===
=== rgbszin.cpp ===
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

=== rgbszin.h ===
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

=== szin.cpp ===
#include "szin.h"

Szin::~Szin()
{
}

char Szin::szamotHexava(int i)
{
	if (i>=0 && i<=9) return i+'0'; // 0 és 9 között -> '0' - '9'
	else if (i>=10 && i<=15) return i-10+'A'; // 10 és 15 között -> 'A' - 'F'
	else return '0';
}

int Szin::hexatSzamma(char c)
{
	if (c>='0' && c<='9') return c-'0';
	else if (c>='A' && c<='F') return c-'A'+10;
	else return 0;
}

string Szin::printCode() const
{
	unsigned char r=R(), g=G(), b=B();
	string ertek="#";
	// először átalakítjuk r-t: az első karakter r/16-ból, a második karakter r%16-ból jön
	ertek+=szamotHexava(r/16);
	ertek+=szamotHexava(r%16);
	// majd ugyanez a többire
	ertek+=szamotHexava(g/16);
	ertek+=szamotHexava(g%16);
	ertek+=szamotHexava(b/16);
	ertek+=szamotHexava(b%16);

	return ertek;
}

bool Szin::megegyezik(const Szin &sz) const
{
	return (R()==sz.R() && G()==sz.G() && B()==sz.B());
}

=== szin.h ===
#ifndef SZIN_H
#define SZIN_H

#include <string>

using namespace std;

class Szin
{
public:
	virtual ~Szin();

	virtual unsigned char R() const = 0;
	virtual unsigned char G() const = 0;
	virtual unsigned char B() const = 0;

	static char szamotHexava(int i);
	static int hexatSzamma(char c);

	virtual string printCode() const;
	bool megegyezik(const Szin &sz) const;
};

#endif // SZIN_H

=== szovegesszin.cpp ===
#include "szovegesszin.h"

SzovegesSzin::SzovegesSzin(const string &sz):
	szoveg(sz)
{
	if (szoveg=="fekete")
	{
		r=0;
		g=0;
		b=0;
	}
	else if (szoveg=="feher")
	{
		r=255;
		g=255;
		b=255;
	}
	else if (szoveg=="kek")
	{
		r=0;
		g=0;
		b=255;
	}
	else if (szoveg=="zold")
	{
		r=0;
		g=255;
		b=0;
	}
	else if (szoveg=="piros")
	{
		r=255;
		g=0;
		b=0;
	}
	else if (szoveg=="cian")
	{
		r=0;
		g=255;
		b=255;
	}
	else if (szoveg=="magenta")
	{
		r=255;
		g=0;
		b=255;
	}
	else if (szoveg=="sarga")
	{
		r=255;
		g=255;
		b=0;
	}
	else if (szoveg[0]=='#' && szoveg.length()>=7)
	{
		r=hexatSzamma(szoveg[1])*16+hexatSzamma(szoveg[2]);
		g=hexatSzamma(szoveg[3])*16+hexatSzamma(szoveg[4]);
		b=hexatSzamma(szoveg[5])*16+hexatSzamma(szoveg[6]);
	}
	else // a default a fekete
	{
		szoveg="fekete";
		r=0;
		g=0;
		b=0;
	}
}

string SzovegesSzin::printCode() const
{
	return szoveg;
}

=== szovegesszin.h ===
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

=== szurke.cpp ===
#include "szurke.h"

Szurke::Szurke(double vilagos):
	vilagos(vilagos)
{
}

unsigned char Szurke::R() const
{
	return vilagos*255;
}

unsigned char Szurke::G() const
{
	return vilagos*255;
}

unsigned char Szurke::B() const
{
	return vilagos*255;
}

=== szurke.h ===
#ifndef SZURKE_H
#define SZURKE_H

#include "szin.h"

class Szurke : public Szin
{
	double vilagos;
public:
	Szurke(double vilagos);

	virtual unsigned char R() const;
	virtual unsigned char G() const;
	virtual unsigned char B() const;
};

#endif // SZURKE_H

