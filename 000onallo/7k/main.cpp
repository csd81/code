#include <iostream>
#include "szin.h"
#include "rgbszin.h"
#include "feketefeher.h"
#include "szurke.h"
#include "szovegesszin.h"

void szintKiir(const Szin* const psz)
{
    std::cout << "(" << int(psz->R()) << "," << int(psz->G()) << "," << int(psz->B()) << ")" << std::endl;
}

int main()
{

    // RGBSzin teszt: konstruktor, destruktor
    std::cout << std::endl;
    std::cout << "RGBSzin teszt: konstruktor, destruktor" << std::endl;
    Szin *pszin1 = new RGBSzin(123,54,65);
    szintKiir(pszin1);
    delete pszin1;

    // RGBSzin teszt: R, G, B függvények
    std::cout << std::endl;
    std::cout << "RGBSzin teszt: R, G, B" << std::endl;
    Szin *pszin2 = new RGBSzin(29,124,243);
    szintKiir(pszin2); // (29,124,243)
    delete pszin2;
    pszin2=new RGBSzin();
    szintKiir(pszin2); // (0,0,0)
    delete pszin2;

    // // FeketeFeher teszt: R, G, B függvények
    std::cout << std::endl;
    std::cout << "FeketeFeher teszt: R, G, B" << std::endl;
    std::cout << "tru\n";
    Szin *pszin3 = new FeketeFeher(true);
    szintKiir(pszin3); // (0,0,0)
    delete pszin3;

    std::cout << "fals\n";
    pszin3=new FeketeFeher(false);
    szintKiir(pszin3); // (255,255,255)
    delete pszin3;

    // Szurke teszt: R, G, B függvények
    std::cout << std::endl;
    std::cout << "Szurke teszt: R, G, B" << std::endl;
    // Szin* pszin5 = new FeketeFeher(false);
    // szintKiir(pszin5);
    // delete pszin5;
    // pszin5 = new FeketeFeher(true);
    // szintKiir(pszin5);
    // delete pszin5;

    Szin *pszin4 = new Szurke(0);
    szintKiir(pszin4); // (0,0,0)
    delete pszin4;

    pszin4=new Szurke(1);
    szintKiir(pszin4); // (255,255,255)
    delete pszin4;

    pszin4=new Szurke(0.5);
    szintKiir(pszin4); // (127,127,127)
    delete pszin4;

    pszin4=new Szurke(0.8);
    szintKiir(pszin4); // (204,204,204)
    delete pszin4;

    // Szin teszt: szamotHexava, hexatSzamma függvények
    std::cout << std::endl;
    std::cout << "Szin teszt: szamotHexava, hexatSzamma" <<
    Szin::szamotHexava(0) <<   // 0
    Szin::szamotHexava(5) <<   // 5
    Szin::szamotHexava(9) <<  // 9
    Szin::szamotHexava(10) <<  // A
    Szin::szamotHexava(12) <<   // C
    Szin::szamotHexava(15) << std::endl << std::endl <<    // F

    Szin::hexatSzamma('0') <<  // 0
    Szin::hexatSzamma('3') <<  // 3
    Szin::hexatSzamma('9') <<  // 9
    Szin::hexatSzamma('A') <<  // 10
    Szin::hexatSzamma('E') <<  // 14
    Szin::hexatSzamma('F') << std::endl << std::endl;  // 15

    // // Szin teszt: printCode függvény
    std::cout << std::endl;
    std::cout << "Szin teszt: printCode" << std::endl;
    Szin *pszin5=new RGBSzin(120,65,234);
    std::cout << pszin5->printCode() << std::endl; // #7841EA
    delete pszin5;

    pszin5=new RGBSzin(6,54,15);
    std::cout << pszin5->printCode() << std::endl; // #06360F
    delete pszin5;

    pszin5=new RGBSzin(212,200,253);
    std::cout << pszin5->printCode() << std::endl; // #D4C8FD
    delete pszin5;

    Szin* szin5=new RGBSzin(128,96,177);
    std::cout << szin5->printCode() << std::endl; // #8060B1
    delete szin5;

    szin5=new FeketeFeher(false);
    std::cout << szin5->printCode() << std::endl; // #FFFFFF
    delete szin5;


    // SzovegesSzin teszt: konstruktor, R, G, B függvények
    std::cout << std::endl;
    std::cout << "SzovegesSzin teszt: konstruktor, R, G, B" << std::endl;
    Szin *pszin6=new SzovegesSzin("piros");
    szintKiir(pszin6); // (255,0,0)
    delete pszin6;

    pszin6 = new SzovegesSzin("sarga");
    szintKiir(pszin6); // (255,255,0)
    delete pszin6;

    pszin6 = new SzovegesSzin("kek");
    szintKiir(pszin6); // (0,0,255)
    delete pszin6;

    pszin6=new SzovegesSzin("ilyenincs");
    szintKiir(pszin6); // (0,0,0)
    delete pszin6;

    // SzovegesSzin teszt: konstruktor hexa formában
    std::cout << std::endl;
    std::cout << "SzovegesSzin teszt: konstruktor hexa forma" << std::endl;
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
    std::cout << std::endl;
    std::cout << "SzovegesSzin teszt: printCode" << std::endl;

    Szin * pszin8=new SzovegesSzin("magenta");
    std::cout << pszin8->printCode() << std::endl; // magenta
    delete pszin8;

     pszin8=new SzovegesSzin("nincs ilyen ezert fekete lesz");
     std::cout << pszin8->printCode() << std::endl; // fekete
     delete pszin8;

     pszin8 = new SzovegesSzin("zold");
     std::cout << pszin8->printCode() << std::endl;
     delete pszin8;

    // Szin teszt: megegyezik függvény
     std::cout << std::endl;
     std::cout << "Szin teszt: megegyezik" << std::endl;

    Szin *pszin9 = new RGBSzin(212,200,253);
    Szin *pszin10=new Szurke(1);
    Szin *pszin11=new SzovegesSzin("#D4C8FD");
    Szin *pszin12=new SzovegesSzin("feher");

    szintKiir(pszin9); // (212,200,253)
    szintKiir(pszin10); // (255,255,255)
    szintKiir(pszin11); // (212,200,253)
    szintKiir(pszin12); // (255,255,255)
    std::cout << (pszin9->megegyezik(*pszin10) ? "igen" : "nem") << std::endl; // 0
    std::cout << (pszin10->megegyezik(*pszin12) ? "i":"n") << std::endl; // 1
    std::cout << pszin12->megegyezik(*pszin11) << std::endl; // 0
    std::cout << (pszin11->megegyezik(*pszin9) ? "megegyezik" : "")  << std::endl; // 1
    delete pszin9;
    delete pszin10;
    delete pszin11;
    delete pszin12;

    // RGBSzin teszt: konstruktor másolat
    std::cout << std::endl;
    std::cout << "RGBSzin teszt: konstruktor masolat" << std::endl;
    Szin *pszin13=new SzovegesSzin("#E4CB27");
    szintKiir(pszin13); // (228,203,39)
    Szin *pszin14=new RGBSzin(*pszin13);
    szintKiir(pszin14); // (228,203,39)
    delete pszin13;
    delete pszin14;
    pszin13=new Szurke(0.3);
    szintKiir(pszin13); // (76,76,76)
    pszin14=new RGBSzin(*pszin13);
    szintKiir(pszin14); // (76,76,76)
    delete pszin13;
    delete pszin14;

	return 0;
}
