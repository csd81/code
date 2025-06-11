#include "pont.h"

#include <cmath>
#include <fstream>
using namespace std;

// --- SPECIFIKÁCIÓ PDF 1. ---
// Pont(): paraméter nélküli konstruktor → origó (0,0)
Pont::Pont(): x(0), y(0) {}

// --- SPECIFIKÁCIÓ PDF 3. ---
// Pont(x,y): koordinátás konstruktor → M ellenőrzés
Pont::Pont(double x, double y): x(x), y(y) {
    checkM();
}

// --- SPECIFIKÁCIÓ PDF 4. ---
// Pont(const Pont&): másoló konstruktor → M ellenőrzés
Pont::Pont(const Pont& orig): x(orig.x), y(orig.y) {
    checkM();
}

// --- SPECIFIKÁCIÓ PDF 1. ---
// getX, getY: getterek
double Pont::getX() const { return x; }
double Pont::getY() const { return y; }

// --- SPECIFIKÁCIÓ PDF 1. ---
// kiir(): kiírás ostream-re
void Pont::kiir(ostream &os) const {
    os << "(" << x << "," << y << ")";
}

// --- SPECIFIKÁCIÓ PDF 1. ---
// tavolsag(): két Pont távolsága
double Pont::tavolsag(const Pont &p1, const Pont &p2) {
    double xdiff = p1.x-p2.x;
    double ydiff = p1.y-p2.y;
    return std::sqrt(xdiff*xdiff + ydiff*ydiff);
}

// --- SPECIFIKÁCIÓ PDF 2. ---
// setM(), getM(): statikus setter/getter M-hez
void Pont::setM(double M) { Pont::M = M; }
double Pont::getM() { return M; }

// --- SPECIFIKÁCIÓ PDF 3–5. ---
// checkM(): M korlát ellenőrzése + warnings.log-ba írás
void Pont::checkM() const {
    if (!(-M<=x && x<=M && -M<=y && y<=M)) {
        cout << "Figyelem: Pont limiten tul! ";
        kiir();
        cout << endl;

        ofstream warn("warnings.log", std::ios::app);
        warn << "Figyelem: Pont limiten tul! ";
        kiir(warn);
        warn << endl;
    }
}
