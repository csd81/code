#include "verseny.h"

// Spec 4. konstruktor fájlbeolvasással
Verseny::Verseny(const string& inputfajl)
{
    ifstream in(inputfajl);
    if (!in.is_open())
    {
        cout << "Hiba! Nem sikerult megnyitni a fajlt: " << inputfajl << endl;
        return;
    }

    in >> megnevezes;

    // Spec 4. fájlból beolvasás: név, távolság, érvényesség
    string nev;
    double tav;
    bool erv;
    while (in >> nev >> tav >> erv)
        probalkozasok.push_back(Probalkozas(nev, tav, erv));
}

// Spec 5. kiir() függvény (ostream-re)
void Verseny::kiir(ostream& os) const
{
    os << megnevezes << endl;
    for (unsigned i = 0; i < probalkozasok.size(); i++)
    {
        os << probalkozasok[i].getNev() << " ";
        os << probalkozasok[i].getTavolsag() << " ";
        os << probalkozasok[i].getErvenyes() << endl;
    }
}

// Spec 7. kiir() fájlba
void Verseny::kiir(const string& outputfajl) const
{
    ofstream out(outputfajl);
    kiir(out); // Spec 6. kiir() átalakítás — újrafelhasználás
}

// Spec 8. uj() függvény
void Verseny::uj(const string& nev, double tav, bool erv)
{
    probalkozasok.push_back(Probalkozas(nev, tav, erv));
}

// Spec 9. ervenyesDobasok() függvény
vector<double> Verseny::ervenyesDobasok() const
{
    vector<double> eredmeny;
    for (size_t i = 0; i < probalkozasok.size(); i++)
        if (probalkozasok[i].getErvenyes())
            eredmeny.push_back(probalkozasok[i].getTavolsag());
    return eredmeny;
}

// Spec 11. nevSzerint() függvény
void Verseny::nevSzerint(const string& nev, vector<Probalkozas>& cel) const
{
    cel.clear();
    for (size_t i = 0; i < probalkozasok.size(); i++)
        if (probalkozasok[i].getNev() == nev)
            cel.push_back(probalkozasok[i]);
}
