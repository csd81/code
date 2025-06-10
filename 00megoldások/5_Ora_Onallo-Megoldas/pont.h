#ifndef PONT_H
#define PONT_H

#include <iostream>
using namespace std;

// --- SPECIFIKÁCIÓ: PONT OSZTÁLY ---
// 1. paraméter nélküli konstruktor: origó (0,0)
// 2. statikus M adattag (double), kezdetben 106, setM(), getM()
// 3. M korlát figyelése konstruktorban → kiírás ha túllépi
// 4. másoló konstruktor → M korlát figyelése
// 5. warnings.log fájlba is kiírás (std::ios::app)
// Egyéb: getterek, kiir(), tavolsag()

class Pont
{
    static double M;
    double x, y;
public:
    Pont(); // origó
    Pont(double x, double y); // koordinátás konstruktor
    Pont(const Pont& orig); // másoló konstruktor

    double getX () const;
    double getY () const;
    void kiir (ostream& os=std::cout) const;

    static double tavolsag (const Pont& p1, const Pont& p2);

    static void setM (double M);
    static double getM ();

    void checkM () const; // M korlát ellenőrzése
};

#endif // PONT_H
