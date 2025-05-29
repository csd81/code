#include "verseny.h"
#include "probalkozas.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

Verseny::Verseny(const string& filenev)
{
    ifstream file(filenev);
    if (!file.is_open()) {
        cerr << "Hiba! A fájl nem nyitható meg: " << filenev << endl;
        return;
    }
    getline (file, megnevezes);
    string sor;
    while (getline(file, sor)) {
        istringstream iss(sor);
        string nev;
        double ido;
        int ervenyes;

        if (iss >> nev >> ido >> ervenyes) {
            probalkozasok.push_back(Probalkozas(nev, ido, ervenyes));
        }
    }
    file.close();
}

void Verseny::kiir() const
{
    cout << megnevezes << endl;
    for (const auto& p : probalkozasok){
        cout << p.getNev() << " "             
             << p.getTavolsag()
             << (p.getErvenyes() ? 1 : 0) << endl;
    }

}

void Verseny::kiir(ostream& os) const
{
    os << megnevezes << endl;
    for (const auto& p : probalkozasok){
        os << p.getNev() << " "             
             << p.getTavolsag()
             << (p.getErvenyes() ? 1 : 0) << endl;
    }
}

void Verseny::kiir(const string& filenev) const
{
    ofstream ofs(filenev);
    if (!ofs.is_open()) {
        cerr << "Nem sikerült megnyitni a fájlt írásra: " << filenev << endl;
        return;
    }
    Verseny::kiir(ofs);

    ofs.close();
}

void Verseny::uj(const string& n, double t, bool e)
{
    probalkozasok.push_back(Probalkozas(n, t, e));

}

vector<double> Verseny::ervenyesDobasok() const
{
    vector<double> eredmenyek;
    for (const auto& p : probalkozasok){
        if (p.getErvenyes()) {
            eredmenyek.push_back(p.getTavolsag());
        }
    }
    return eredmenyek;
}

void Verseny::nevSzerint(const string& nev, vector<Probalkozas>& cel) const
{
    cel.clear();
    for (const auto& p : probalkozasok) {
        if (p.getNev() == nev) {
            cel.push_back(p);
        }
    }
}




string Verseny::getMegnevezes() const
{
    return megnevezes;
}

void Verseny::setMegnevezes(const string &newMegnevezes)
{
    megnevezes = newMegnevezes;
}

vector<Probalkozas> Verseny::getProbak() const
{
    return probalkozasok;
}

void Verseny::setProbak(const vector<Probalkozas> &newProbak)
{
    probalkozasok = newProbak;
}
