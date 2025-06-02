#include "szerver.h"
#include "magus.h"
#include "ijasz.h"
#include "harcos.h"
#include <fstream>
#include "json.hpp"

using namespace  nlohmann;

Szerver::Szerver()
{

}

Szerver::~Szerver()
{
    karakterek.clear();
}

void Szerver::betolt()
{
    ifstream infile("karakterek.json");

    json data;
    infile>> data;

    for (size_t i =0; i < data.size(); i++){
        string nev =  data[i]["nev"];
        int szint = data[i]["szint"];
        if (data[i]["kaszt"]=="magus")
            {
                int mana = data[i]["mana"];
                Magus* m = new Magus(nev,szint, mana);
                karakterek.push_back(m);
        } else if (data[i]["kaszt"]=="harcos")
            {
            string fegyver = data[i]["fegyver"];
            Harcos* h = new Harcos(nev,szint,fegyver);
            karakterek.push_back(h);
        } else if (data[i]["kaszt"]=="ijasz")
            {
            int pontossag = data[i]["pontossag"];
            Ijasz* i = new Ijasz(nev,szint, pontossag);
            karakterek.push_back(i);

        }
}
}

void Szerver::listaz()
{
    for (auto it: karakterek){
        it->kiir();
    }
}

Karakter *Szerver::legtobbElet()
{
    int maxindex = 0;
    for (size_t i=1; i < karakterek.size(); i++){
        if (karakterek[i]->eletero() > karakterek[maxindex]->eletero())
            maxindex=i;
    }
    return karakterek[maxindex];
}

string Szerver::csata(string n1, string n2)
{
    Karakter* k1 = nullptr;
    Karakter* k2 = nullptr;

    for (Karakter* k : karakterek) {
        if (k->getNev() == n1) k1 = k;
        else if (k->getNev() == n2) k2 = k;
    }

    int e1 = k1->eletero();
    int e2 = k2->eletero();
    int s1 = k1->sebzes();
    int s2 = k2->sebzes();

    while (true) {
        e1-=s2;
        e2-=s1;
        if (e1 <= 0 && e2 <= 0) return "X";
        if (e1 <= 0) return k2->getNev();
        if (e2 <= 0) return k1->getNev();

    }
}

void Szerver::tornaSzimulacio()
{
    ifstream infile("merkozesek.json");
    json meccsek;
    infile >> meccsek;

    json eredmenyek = json::array();

    for(const auto& meccs : meccsek){
        string j1 = meccs["jatekos1"];
        string j2 = meccs["jatekos2"];
        string nyertes = csata(j1, j2);

        int nyertesKod = 0;
        if (nyertes == j1) nyertesKod = 1;
        else if (nyertes == j2) nyertesKod = 2;

        json eredmeny = {
            {"jatekos1", j1},
            {"jatekos2", j2},
            {"nyertes", nyertesKod},
        };

        eredmenyek.push_back(eredmeny);

    }

    ofstream outfile("eredmenyek.json");
    outfile<<eredmenyek.dump(4);

}  /// tornaSzimulacio



































