#include "halmaz.h"
#include<iostream>
Halmaz::Halmaz() {
    darab = 0;
    tomb = nullptr;
}

Halmaz::Halmaz(int db) {
    darab = db;
    tomb = new double[darab];
    for (int i = 0; i < darab; i++) {
        tomb[i] = 0;
    }
}

Halmaz::Halmaz(const Halmaz& masik){
    darab = masik.darab;
    tomb = new double[masik.darab];
    for(int i = 0; i<masik.darab; i++){
        tomb[i] = masik.tomb[i];
    }
}


Halmaz& Halmaz::operator=(const Halmaz& masik){
    if (this == &masik) return *this;
    delete[] tomb;


    darab = masik.darab;
    tomb = new double[masik.darab];
    for(int i = 0; i<masik.darab; i++){
        tomb[i] = masik.tomb[i];
    }
    return *this;
}

Halmaz::~Halmaz()
{
    delete [] tomb;
}

int Halmaz::meret()
{
    return darab;
}



Halmaz& operator<<(Halmaz& h, double elem){
    for(int i = 0; i<h.darab; i++){
        if (h.tomb[i] == elem){
        std::cout <<  elem << " skipped\n";
            return h;
    }

    }
    double* uj = new double[h.darab+1];

        int pos =0;
        while (pos<h.darab && h.tomb[pos] < elem){
            uj[pos] = h.tomb[pos];
            pos++;
        }

        uj[pos] = elem;
        for(int i = pos; i<h.darab; i++){
            uj[i+1] = h.tomb[i];
        }

       delete[] h.tomb;

       h.tomb = uj;
       h.darab++;

        std::cout << "+"<< elem << "\n";
     return h;
}


Halmaz& operator>>(Halmaz& h, double elem){
    int index =-1;
    for (int i =0; i< h.darab; i++){
        if (h.tomb[i] == elem){
            index =i;
            break;
        }
    }

    if (index == -1) {
        std::cout <<  elem << " skipped\n";
        return h;
    }

    double * uj =nullptr;
    if (h.darab > 1){
        uj = new double[h.darab - 1];
    }

    int ujIndex = 0;
    for (int i=0; i<h.darab; i++){
        if (i != index){
            uj[ujIndex++] = h.tomb[i];
        }
    }

    delete[] h.tomb;
    h.tomb = uj;
    h.darab--;
    std::cout << "-"<< elem << "\n";
    return h;
}

std::ostream& operator<<(std::ostream& os, const Halmaz& h){
os << "{";
    if (h.darab > 0) {
        os << h.tomb[0];
        for (int i = 1; i < h.darab; i++) {
            os << ", " << h.tomb[i];
        }
    }
os << "}";
    return os;
}

bool Halmaz::operator[](double elem) const{
    for (int i =0; i<darab; i++){
        if (tomb[i]== elem){
        return true;
        }
    }
    return false;
}
 //metszt
Halmaz operator&(const Halmaz& h1, const Halmaz& h2){
    Halmaz h3;
    for (int i=0; i<h1.darab; i++){
        for (int j=0; j<h2.darab; j++){
            if  (h1.tomb[i]== h2.tomb[j]){
                h3 <<h1.tomb[i];
                break;
            }
        }
    }
    return h3;
}

 //unió
Halmaz operator|(const Halmaz& h1, const Halmaz& h2){
    Halmaz h3;
        for (int i=0; i<h1.darab; i++){
           h3<< h1.tomb[i];
        }
        for (int j=0; j<h2.darab; j++){
            h3<< h2.tomb[j];
        }
    return h3;
}
    //-
Halmaz operator-(const Halmaz& h1, const Halmaz& h2){
    Halmaz h3;
    for (int i=0; i<h1.darab; i++){
        bool benneVan = false;
        for (int j=0; j<h2.darab; j++){
            if (h1.tomb[i] == h2.tomb[j]){
                benneVan = true;
                break;
            }
        }
        if (!benneVan){
            h3 << h1.tomb[i];
        }
    }
    return h3;
}

    //xor
Halmaz operator^(const Halmaz& h1, const Halmaz& h2){
    Halmaz h3;

    // H1 elemei, amik nincsenek H2-ben
    for (int i=0; i<h1.darab; i++){
        bool benneVan = false;
        for (int j=0; j<h2.darab; j++){
            if (h1.tomb[i] == h2.tomb[j]){
                benneVan = true;
                break;
            }
        }
        if (!benneVan){
            h3 << h1.tomb[i];
        }
    }

    // H2 elemei, amik nincsenek H1-ben
    for (int i=0; i<h2.darab; i++){
        bool benneVan = false;
        for (int j=0; j<h1.darab; j++){
            if (h2.tomb[i] == h1.tomb[j]){
                benneVan = true;
                break;
            }
        }
        if (!benneVan){
            h3 << h2.tomb[i];
        }
    }

    return h3;
}

Halmaz& Halmaz::operator&=(const Halmaz& masik) {
    *this = *this & masik;  // a meglévő & operátort használjuk
    return *this;
}

Halmaz& Halmaz::operator|=(const Halmaz& masik) {
    *this = *this | masik;
    return *this;
}

Halmaz& Halmaz::operator-=(const Halmaz& masik) {
    *this = *this - masik;
    return *this;
}

Halmaz& Halmaz::operator^=(const Halmaz& masik) {
    *this = *this ^ masik;
    return *this;
}


Halmaz operator+(const Halmaz& h, double d){
    Halmaz eredmeny(h.darab);
    eredmeny.darab = h.darab;

    for (int i=0; i<h.darab; i++){
        eredmeny.tomb[i] = h.tomb[i]+d;
    }
    return eredmeny;
}


Halmaz operator-(const Halmaz& h, double d){
    Halmaz eredmeny(h.darab);
    eredmeny.darab = h.darab;

    for (int i=0; i<h.darab; i++){
        eredmeny.tomb[i] = h.tomb[i]-d;
    }
    return eredmeny;
}

bool operator<(const Halmaz& h1, const Halmaz& h2) {
    if (h1.darab >= h2.darab) return false;
    for (int i = 0; i < h1.darab; i++) {
        bool found = false;
        for (int j = 0; j < h2.darab; j++) {
            if (h1.tomb[i] == h2.tomb[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}



bool operator<=(const Halmaz& h1, const Halmaz& h2) {
    // Minden bal oldali elemnek benne kell lennie a jobb oldaliban
    for (int i = 0; i < h1.darab; i++) {
        bool found = false;
        for (int j = 0; j < h2.darab; j++) {
            if (h1.tomb[i] == h2.tomb[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;  // találtunk olyan elemet, ami nincs a jobb oldalon
    }

    // Ha eddig minden ok, akkor részhalmaz (megengedett az egyenlőség is)
    return true;
}

bool operator>(const Halmaz& h1, const Halmaz& h2) {
    return h2 < h1;
}

bool operator>=(const Halmaz& h1, const Halmaz& h2) {
    return h2 <= h1;
}

bool operator==(const Halmaz& h1, const Halmaz& h2) {
    // Ha az elemszám nem egyezik, akkor nem lehet egyenlő
    if (h1.darab != h2.darab) return false;

    // Minden h1-beli elemnek benne kell lennie h2-ben
    for (int i = 0; i < h1.darab; i++) {
        bool found = false;
        for (int j = 0; j < h2.darab; j++) {
            if (h1.tomb[i] == h2.tomb[j]) {
                found = true;
                break;
            }
        }
        if (!found) return false;  // találtunk olyan elemet, ami nincs benne
    }

    // Ha eddig minden ok → egyenlő
    return true;
}


bool operator!=(const Halmaz& h1, const Halmaz& h2) {
    return !(h1 == h2);
}


 double Halmaz::legnagyobb() const {
    if (darab == 0) {
        throw std::runtime_error("A halmaz ures, nincs legnagyobb elem!");
    }

    double maxElem = tomb[0];
    for (int i = 1; i < darab; i++) {
        if (tomb[i] > maxElem) {
            maxElem = tomb[i];
        }
    }
    return maxElem;
}




double Halmaz::legkisebb() const {
    if (darab == 0) {
        throw std::runtime_error("A halmaz ures, nincs legkisebb elem!");
    }

    double minElem = tomb[0];
    for (int i = 1; i < darab; i++) {
        if (tomb[i] < minElem) {
            minElem = tomb[i];
        }
    }
    return minElem;
}

void Halmaz::torol() {
    delete[] tomb;
    tomb = nullptr;
    darab = 0;
}

