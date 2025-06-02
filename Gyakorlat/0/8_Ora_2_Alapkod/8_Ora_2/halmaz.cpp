#include "halmaz.h"
#include <ostream>

std::ostream& operator<<(std::ostream& os, const Halmaz& h) {
    os << "{";
    for (int i = 0; i < h.meret(); ++i) {
        if (i > 0) os << ", ";
        os << h[i];
    }
    os << "}";
    return os;
}

Halmaz::Halmaz() : db(0), tomb(nullptr) {

}

Halmaz::Halmaz(const Halmaz &masik) : db(masik.db)
{
    tomb = new double[db];
    for (int i=0; i< db; i++){
        tomb[i] = masik.tomb[i];
    }
}

Halmaz::~Halmaz()
{
    delete[] tomb;
}

Halmaz Halmaz::operator&(const Halmaz &masik) const
{
    Halmaz eredmeny;
    for (int i = 0; i< db; i++){
        if (masik.tartalmaz(tomb[i])){
            eredmeny << tomb[i];
        }
    }
    return eredmeny;
}

Halmaz Halmaz::operator|(const Halmaz &masik) const
{
    Halmaz eredmeny = *this;
    for (int i = 0; i< masik.db; i++){
        eredmeny << masik.tomb[i];
    }

    return eredmeny;
}

Halmaz Halmaz::operator-(const Halmaz &masik) const
{
    Halmaz eredmeny;
    for (int i=0; i< db; i++){
        if (!masik.tartalmaz(tomb[i])){
            eredmeny << tomb[i];
        }
    }
    return eredmeny;
}

Halmaz Halmaz::operator^(const Halmaz &masik) const
{
    Halmaz eredmeny;
    for (int i = 0; i < db; ++i) {
        if (!masik.tartalmaz(tomb[i])) {
            eredmeny << tomb[i];
        }
    }
    for (int i = 0; i < masik.db; ++i) {
        if (!this->tartalmaz(masik.tomb[i])) {
            eredmeny << masik.tomb[i];
        }
    }
    return eredmeny;
}

Halmaz &Halmaz::operator&=(const Halmaz &masik)
{
    *this = *this & masik;
    return *this;
}

Halmaz &Halmaz::operator|=(const Halmaz &masik)
{
    *this = *this | masik;
    return *this;
}

Halmaz &Halmaz::operator-=(const Halmaz &masik)
{
    *this = *this - masik;
    return *this;
}

Halmaz &Halmaz::operator^=(const Halmaz &masik)
{
    *this = *this ^ masik;
    return *this;
}

Halmaz Halmaz::operator+(double d) const {
    std::cout << "operator+: hozzaadando ertek = " << d << std::endl;
    Halmaz eredmeny;
    for (int i = 0; i < db; ++i) {
        eredmeny << (tomb[i] + d);
    }
    return eredmeny;
}

Halmaz Halmaz::operator-(double d) const {
    std::cout << "operator-: kivonando ertek = " << d << std::endl;
    Halmaz eredmeny;
    for (int i = 0; i < db; ++i) {
        eredmeny << (tomb[i] - d);
    }
    return eredmeny;
}


bool Halmaz::operator[](double d) const
{
    return tartalmaz(d);
}

bool Halmaz::operator==(const Halmaz& masik) const {
    if (db != masik.db) return false;
    for (int i = 0; i < db; ++i) {
        if (tomb[i] != masik.tomb[i]) return false;
    }
    return true;
}

bool Halmaz::operator!=(const Halmaz& masik) const {
    return !(*this == masik);
}

bool Halmaz::operator<=(const Halmaz& masik) const {
    for (int i = 0; i < db; ++i)
        if (!masik.tartalmaz(tomb[i])) return false;
    return true;
}

bool Halmaz::operator<(const Halmaz& masik) const {
    return *this <= masik && *this != masik;
}

bool Halmaz::operator>=(const Halmaz& masik) const {
    return masik <= *this;
}

bool Halmaz::operator>(const Halmaz& masik) const {
    return masik < *this;
}


double Halmaz::operator[](int index) const {
    return tomb[index];
}

int Halmaz::meret() const
{
    return db;
}

double Halmaz::legnagyobb() const
{
    if (db == 0) throw std::logic_error("A halmaz ures.");
    return tomb[db-1];
}

double Halmaz::legkisebb() const
{
    if (db == 0) throw std::logic_error("A halmaz ures.");
    return tomb[0];
}

void Halmaz::torol()
{
    delete[] tomb;
    tomb = nullptr;
    db =0;
}

Halmaz &Halmaz::operator<<(double d)
{
    if (!tartalmaz(d)){
        beszur(d);
    }
    return *this;
}

Halmaz &Halmaz::operator>>(double d)
{

        torol(d);
        return *this;

}



