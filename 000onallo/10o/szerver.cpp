#include "szerver.h"
#include "karakter.h"
#include "harcos.h"
#include "ijasz.h"
#include "magus.h"



Szerver::~Szerver()
{
    for (Karakter* k : karakterek)
        delete k;
}

void Szerver::betolt()
{
    ifstream ifs("karakterek.txt");
    if (!ifs.is_open()){
        cerr << "Hiba: A karakterek.txt fájlt nem sikerült megnyitni!";
        return;
    }
    while (true){
    string nev;
    string kaszt;
    string fegyver;
    int szint;
    int pontossag;
    int mana;
    ifs >> nev;
    if (nev == "*") break;
    ifs >> kaszt;
    ifs >> szint;
    if (kaszt=="harcos"){
        ifs >> fegyver;
        karakterek.push_back(new Harcos(nev, szint, fegyver));
        }
    else if (kaszt=="ijasz"){
        ifs >> pontossag;
        karakterek.push_back(new Ijasz(nev, szint, pontossag));
        }
    else if (kaszt=="magus"){
        ifs >> mana;
        karakterek.push_back(new Magus(nev, szint, mana));
        }
    }
}


string Szerver::csata(const string &nev1, const string &nev2) const
{
    int ero1=0;
    int ero2=0;
    int seb1=0;
    int seb2=0;
        for (Karakter* k : karakterek){
            if(k->getNev()==nev1) {
                ero1 = k->eletero();
                seb1 = k->sebzes();
            }
            if(k->getNev()==nev2) {
                ero2 = k->eletero();
                seb2 = k->sebzes();
            }
        }
    while (ero1 > 0 && ero2 > 0){
        ero1-=seb2;
        ero2-=seb1;
        }

        if (ero1 <= 0 && ero2 > 0) return nev2;
        else if (ero2<=0 && ero1 >0) return nev1;
        else  return "X";
}

void Szerver::tornaSzimulacio() const
{
    ifstream ifs("merkozesek.txt");
        if (!ifs.is_open()){
        cerr << "Hiba: A merkozesek.txt fájlt nem sikerült megnyitni!";
        return;
    }

    stringstream ss;
    string nev1;
    string nev2;
    while (ifs >> nev1 >> nev2){
        string nyertes = csata(nev1, nev2);
        int adat;
        if (nyertes==nev1) adat=1;
        else if (nyertes==nev2) adat=2;
        else adat=0;
        ss << nev1 << " " << nev2 << " " << adat << std::endl;
    }

    ofstream ofs("eredmenyek.txt");
    if (!ifs.is_open()){
        cerr << "Hiba: Az eredmenyek.txt fájlt nem sikerült megnyitni!";
    }
    ofs << ss.str();
    ofs.close();

}




void Szerver::listaz() const
{
    for (Karakter* k : karakterek){
        k->kiir();
    }
}

Karakter *Szerver::legtobbElet() const
{
    Karakter* max = karakterek[0];
    for (Karakter* k : karakterek){
        if (k->eletero()>max->eletero()){
            max =k;
        }
    }
    return max;
}


