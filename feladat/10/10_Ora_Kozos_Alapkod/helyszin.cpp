#include "helyszin.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;





void Helyszin::betolt(const string& fajlnev){
    ifstream fajl(fajlnev);
    if (!fajl.is_open()) {
        cerr << "Nem sikerült megnyitni a fájlt: " << fajlnev << endl;
        return;
    }

    json j;
    fajl >> j;

    nev = j["nev"].get<string>();
    cim = j["cim"].get<string>();
    esemenyek.clear();

    for (const auto& e : j["esemenyek"]){
        string enev = e["nev"].get<string>();
        string datum = e["datum"].get<string>();
        int kezdes = e["kezdete"].get<int>();
        int befejezes = e["vege"].get<int>();
        int letszam = e["resztvevok"].get<int>();

        Esemeny uj(enev, datum, kezdes, befejezes, letszam);
        esemenyek.push_back(uj);
    }

    fajl.close();
}

void Helyszin::kiir() const{
    cout << "Helyszín neve: " << nev << endl;
    cout << "Cím: " << cim << endl;
    cout << "Események:" << endl;
    for (const auto& e : esemenyek){
cout << " - " << e.getNev() << " ("  << e.getDatum()
     << ") " << e.getKezdete() << ":00-" << e.getVege()
     << ":00, " << e.getResztvevokSzama()  << " fő" << endl;
    }

}



void Helyszin::esemenyHosszKiir(const std::string& fajlnev) const{
    json tomb = json::array();

    for (const auto& e : esemenyek) {
        int hossz = e.getVege() - e.getKezdete();
        json elem;
        elem["nev"] = e.getNev();
        elem["hossz"] = hossz;
        tomb.push_back(elem);
    }


    ofstream kimenet(fajlnev);
    if (!kimenet.is_open()) {
        cerr << "nem jo!!\n";
        return;
    }

    kimenet << tomb.dump(4);
    kimenet.close();

}

