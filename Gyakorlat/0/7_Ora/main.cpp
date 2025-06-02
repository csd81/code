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
