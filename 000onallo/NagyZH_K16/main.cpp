#include <iostream>
#include <string>

#include "szamlaseged.h"
#include "szamla.h"
#include "hitelszamla.h"
#include "folyoszamla.h"
#include "ugyfel.h"
#include "tranzakcio.h"

using namespace std;

int main()
{
    // Tranzakcio teszt (konstruktor, << operator)
    cout << "Tranzakcio teszt (konstruktor, << operator)" << endl;
    Tranzakcio t1("11773487-00372491", 25000, true);
    cout << t1; // Szamlaszam: 11773487-00372491, osszeg: 25000, jovairas: 1
    Tranzakcio t2("10201006-50195039", 7825000, false);
    cout << t2; // Szamlaszam: 10201006-50195039, osszeg: 7825000, jovairas: 0

    // Tranzakcio teszt (* operator)
    cout << endl << "Tranzakcio teszt (* operator)" << endl;
    cout << *t1 << endl; // 1
    cout << *t2 << endl; // 1
    Tranzakcio t3("11773487-00372491", -25000, true);
    cout << *t3 << endl; // 0
    Tranzakcio t4("73200213-16257317", 15000, false);
    cout << *t4 << endl; // 0

    // FolyoSzamla/HitelSzamla teszt (konstruktor, kiir)
    cout << endl << "FolyoSzamla teszt (konstruktor, kiir)" << endl;
    Szamla* fsz1 = new FolyoSzamla("11773487-00372491", 350000, "Elsodleges szamla");
    fsz1->kiir();
        // Szamlaszam: 11773487-00372491, egyenleg: 350000
        //   nev: Elsodleges szamla

    Szamla* hsz1 = new HitelSzamla("73200213-02639152", 0, 50000);
    hsz1->kiir();
        // Szamlaszam: 73200213-02639152, egyenleg: 0
        //   hitelkeret: 50000

    // FolyoSzamla/HitelSzamla teszt (vegrehajt)
    cout << endl << "FolyoSzamla/HitelSzamla teszt (vegrehajt)" << endl;
    fsz1->vegrehajt(t1); // vegrehajtodik
    fsz1->kiir();
        // Szamlaszam: 11773487-00372491, egyenleg: 375000
        //   nev: Elsodleges szamla
    fsz1->vegrehajt(t2); // nem hajtodik vegre
        // Szamlaszam: 11773487-00372491, egyenleg: 375000
        //   nev: Elsodleges szamla
    fsz1->kiir();

    hsz1->vegrehajt(t3); // nem hajtodik vegre
    hsz1->kiir();
        // Szamlaszam: 73200213-02639152, egyenleg: 0
        //   hitelkeret: 50000
    Tranzakcio t5("11773360-00429878", 70000, false);
    hsz1->vegrehajt(t5); // nem hajtodik vegre
    hsz1->kiir();
        // Szamlaszam: 73200213-02639152, egyenleg: 0
        //   hitelkeret: 50000
    hsz1->vegrehajt(t1); //  vegrehajtodik
    hsz1->kiir();
        // Szamlaszam: 73200213-02639152, egyenleg: 25000
        //   hitelkeret: 50000
    hsz1->vegrehajt(t5); // vegrehajtodik
    hsz1->kiir();
        // Szamlaszam: 73200213-02639152, egyenleg: -45000
        //   hitelkeret: 50000

    delete fsz1;
    delete hsz1;

    // Ugyfel teszt (konstruktor, += operator, [] operator)
    cout << endl << "Ugyfel teszt (konstruktor, += operator, [] operator)" << endl;
    Szamla* fsz2 = new FolyoSzamla("11773487-00372491", 350000, "Elsodleges szamla");
    Szamla* fsz3 = new FolyoSzamla("11773487-50195039", 500000, "Takarek szamla");
    Szamla* hsz2 = new HitelSzamla("73200213-02639152", 0, 50000);
    Szamla* hsz3 = new HitelSzamla("73200213-02639152", 0, 100000);
    Ugyfel ugyfel("Pekardy Milan");
    ugyfel += fsz2;
    ugyfel += fsz3;
    ugyfel += hsz2;
    ugyfel += hsz3;

    Szamla* sz = ugyfel[0];
    if(sz) sz->kiir();
        // Szamlaszam: 11773487-00372491, egyenleg: 350000
        //   nev: Elsodleges szamla
    else cout << "Nincs ilyen szamla!" << endl;
    sz = ugyfel[1];
    if(sz) sz->kiir();
        // Szamlaszam: 11773487-50195039, egyenleg: 500000
        //   nev: Takarek szamla
    else cout << "Nincs ilyen szamla!" << endl;
    sz = ugyfel[2];
    if(sz) sz->kiir();
        // Szamlaszam: 73200213-02639152, egyenleg: 0
        //   hitelkeret: 50000
    else cout << "Nincs ilyen szamla!" << endl;
    sz = ugyfel[3];
    if(sz) sz->kiir();
    else cout << "Nincs ilyen szamla!" << endl;
        // Nincs ilyen szamla!

    delete hsz3;

    // Ugyfel teszt (kiir)
    cout << endl << "Ugyfel teszt (kiir)" << endl;
    ugyfel.kiir();
        // Ugyfel: Pekardy Milan
        // Szamlaszam: 11773487-00372491, egyenleg: 350000
        //   nev: Elsodleges szamla
        // Szamlaszam: 11773487-50195039, egyenleg: 500000
        //   nev: Takarek szamla
        // Szamlaszam: 73200213-02639152, egyenleg: 0
        //   hitelkeret: 50000

    // Ugyfel teszt (alkalmaz)
    cout << "Ugyfel teszt (alkalmaz)" << endl;
    sz = ugyfel.alkalmaz(t3); // nem hajtodik vegre
    if(sz) sz->kiir();
    else cout << "Tranzakcio nem hajtodott vegre!" << endl;
        // Tranzakcio nem hajtodott vegre!
    sz = ugyfel.alkalmaz(t1); // vegrehajtva az 1. szamlan
    if(sz) sz->kiir();
        // Szamlaszam: 11773487-00372491, egyenleg: 375000
        //   nev: Elsodleges szamla
    else cout << "Tranzakcio nem hajtodott vegre!" << endl;

    return 0;
}
