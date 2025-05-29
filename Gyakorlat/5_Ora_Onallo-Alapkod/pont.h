







#ifndef PONT_H
#define PONT_H

#include <cmath>
#include <iostream>
using namespace std;

class Pont
{
    double x, y;
    static double M;

    void figyelmeztetes(const std::string& uzenet) const;
    void ellenoriz() const;
public:
    Pont(double x, double y);
    Pont();
    Pont(const Pont& masik);
    double getX () const;
    double getY () const;
    void kiir (ostream& os=std::cout) const;
    static double tavolsag (const Pont& p1, const Pont& p2);
    static double getM();
    static void setM(double newM);
};

#endif // PONT_H


// Pont osztály
// Adott a Pont osztály két adattaggal: x, y (double), ezek konstruktorban megadandók, getterekkel lekérdezhetők, van továbbá saját kiir függvénye is, amely tetszőleges kimeneti folyamra használható.
// 1. Legyen a Pont osztályban paraméter nélküli konstruktor, ami az origót (0,0) állítja be.
// 2. *Legyen a Pont osztályban egy statikus M adattag (double), aminek értéke kezdetben 106 , és a setM statikus setter függvénnyel legyen beállítható, a getM statikus getter függvénnyel lekérdezhető.
// 3. *Az M egy felső korlátot határoz meg a Pont-ok koordinátáinak az abszolút értékére. Valahányszor olyan Pont objektum konstruálódik, aminek van M-nél nagyobb abszolút értékű koordinátája (vagyis nem teljesül rá, hogy −𝑀 ≤ 𝑥, 𝑦 ≤ 𝑀), akkor a konstruktor írjon ki egy egysoros figyelmeztetést, ami
// ezt közli, és szerepeljen az üzenetben a pont két koordinátája is valamilyen módon.
// 4. *Írj másoló konstruktort is a Pont osztályhoz, ami szintén figyeli az M korlátját.
// 5. *Az említett figyelmeztetések legyenek kiírva egy warnings.log nevű fájba is. A fájl végéhez illesztve kell írni, tehát ne törlődjön a fájl addigi tartalma (tipp: std::ios::app).

