#include <iostream>
#include <utility>
#include "Tarolo.h"


namespace EpicToolbox{


Tarolo::Tarolo(){
    std::cout << "Tarolo mérete? " << std::endl;
    std::cin >> db;
    szamok = new int[db];
    for(int i = 0; i < db; i++){
        std::cout << "Tarolo " << i+1 << ". eleme: ";
        std::cin >> szamok[i];

    }
}

Tarolo::Tarolo(int db) : db(db){
    szamok = new int[db];
    for(int i = 0; i < db; i++){
        szamok[i] = i + 1;
    }
}

    Tarolo::Tarolo(const Tarolo &masik) :db(masik.db){
    szamok = new int[db];
    for(int i = 0; i < db; i++) {
        szamok[i] = masik.szamok[i];
    }
}

    Tarolo& Tarolo::operator=(const Tarolo &masik){
        if (this != &masik) {
            delete [] szamok;
            db=masik.db;
            szamok = new int[db];
            for(int i = 0; i < db; i++) {
                szamok[i] = masik.szamok[i];
            }

        }

        return *this;
    }


Tarolo::~Tarolo(){
    delete[] szamok;
}

void Tarolo::kiir() const{
    if (db != 0){
    for(int i = 0; i < db; i++) {
        std::cout << szamok[i] << " ";
    }
    std::cout << std::endl;
    }
}

void Tarolo::hozzaad(int a){
    int * temp = new int[db+1];
    for(int i = 0; i < db; i++) {
        temp[i] = szamok[i];
    }
    temp[db] = a;
    delete[] szamok;
    szamok = temp;
    ++db;
}


double Tarolo::atlag() const{
    if (db == 0) return 0.0;
    double atlag = 0.0;
    for (int i = 0; i < db; i++) {
        atlag += szamok[i];
    }
    return static_cast<double>(atlag)/static_cast<double>(db);

}
int Tarolo::tartomany() const{
    if (db == 0) return 0;
    int tartomany, min, max;
    min=szamok[0];
    for (int i = 0; i < db; i++) {
        if (szamok[i] < min) {
            min = szamok[i];
        }
    }
    max=szamok[0];
    for (int i = 0; i < db; i++) {
        if (szamok[i] > max) {
            max = szamok[i];
        }
    }
    tartomany =max-min;
    return tartomany;
}
void Tarolo::rendez(bool incr){
    if(incr) {
        for(int i = 0; i < db; i++) {
            for(int j = i+1; j < db; j++) {
                if(szamok[i] > szamok[j]) {
                    std::swap(szamok[i], szamok[j]);
                }
            }
        }
    } else {
        for(int i = 0; i < db; i++) {
            for(int j = i+1; j < db; j++) {
                if(szamok[i] < szamok[j]) {
                    std::swap(szamok[i], szamok[j]);
                }
            }
        }
    }
}

Tarolo& Tarolo::hozzafuz(const Tarolo & t){
    if (this == &t) {
        Tarolo temp(t);  // másolat készítése
        return hozzafuz(temp);
    }
    int * temp = new int[db+t.darabLeker()];
    for(int i = 0; i < db; i++) {
        temp[i] = szamok[i];
    }
    for(int i = 0; i < t.darabLeker(); i++) {
        temp[i+db] = t.szamok[i];
    }
    delete[] szamok;
    szamok = temp;
    db=db+t.darabLeker();
    return *this;
}

int Tarolo::darabLeker() const{
    return db;
}


} // namespace