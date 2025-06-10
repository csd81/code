#include "utvonal.h"

// --- SPECIFIKÁCIÓ PDF 13. ---
// konstruktor: "PATH", pontok üresek, irany=true
Utvonal::Utvonal(): Halmaz("PATH") {}

// --- SPECIFIKÁCIÓ PDF 14. ---
// megfordit(): irany váltás
void Utvonal::megfordit() {
    irany = !irany;
}

// --- SPECIFIKÁCIÓ PDF 15. ---
// kiir(): ha irany == false → pontok fordított sorrendben
void Utvonal::kiir() {
    if (irany)
        Halmaz::kiir();
    else {
        cout << megnevezes << " [" << pontok.size() << "]:";
        for (int i=pontok.size()-1; i>=0; i--)
            pontok[i].kiir();
        cout << endl;
    }
}

// --- SPECIFIKÁCIÓ PDF 16. ---
// hossz(): szomszédos pontok távolságainak összege
double Utvonal::hossz() const {
    if (pontok.size() < 2)
        return 0;

    double sum = 0;
    for (size_t i=1;i<pontok.size();i++)
        sum += Pont::tavolsag(pontok[i-1], pontok[i]);
    return sum;
}
