#include "halmaz.h"

Halmaz::Halmaz() : darab(0)  {
    tomb = nullptr;
}

Halmaz::Halmaz(const Halmaz &masik): darab(masik.darab)
{
    this->tomb = new double[masik.darab];
    for (int i=0; i<masik.darab; i++){
    tomb[i] = masik.tomb[i];
    }
}

Halmaz &Halmaz::operator=(const Halmaz &masik)
{
    if (&masik!=this){
        delete[] tomb;
        darab=masik.darab;
        this->tomb = new double[masik.darab];

        for (int i=0; i<masik.darab; i++){
            tomb[i] = masik.tomb[i];
            }
        }
    return *this;
}

Halmaz::~Halmaz()
{
    delete [] tomb;
}

int Halmaz::meret() const
{
    return darab;
}

bool Halmaz::operator[](double elem)
{
    bool eleme = false;
    for (int i=0; i<darab; i++){
        if (elem == tomb[i])
            eleme = true;
    }
    return eleme;
}

Halmaz &Halmaz::operator&=(const Halmaz &h2)
{

    Halmaz temp =  *this & h2;
     *this = temp;
    return *this;
}

Halmaz &Halmaz::operator|=(const Halmaz &h2)
{
    Halmaz temp =  *this | h2;
     *this = temp;

    return *this;
}

Halmaz &Halmaz::operator-=(const Halmaz &h2)
{
    Halmaz temp =  *this - h2;
     *this = temp;
    return *this;
}

Halmaz &Halmaz::operator^=(const Halmaz &h2)
{
    Halmaz temp =  *this ^ h2;
     *this = temp;
    return *this;
}

double Halmaz::legnagyobb()
{
    double max = tomb[0];
        for (int i=0; i<darab; i++){
            if (tomb[i]> max) max =  tomb[i];

        }
    return max;
}

double Halmaz::legkisebb()
{
        double min = tomb[0];
        for (int i=0; i<darab; i++){
            if (tomb[i]< min) min=  tomb[i];

        }
    return min;
}

void Halmaz::torol()
{
     delete[] tomb;
    tomb = nullptr;
    darab = 0;
}

Halmaz &operator<<(Halmaz& h, double elem)
{
    for (int i=0; i<h.meret(); i++){
        if(h.tomb[i] == elem)
             return h;
    }
    double * temp = new double[h.meret()+1];
    int index  =0;

    while (index < h.meret() && h.tomb[index] < elem) {
        temp[index] = h.tomb[index];
        index++;
    }

    temp[index]=elem;

    for (int i=index; i<h.meret(); i++){
        temp[i+1]= h.tomb[i];
    }
    delete [] h.tomb;
    h.tomb=temp;
    h.darab++;
    return h;

}

Halmaz &operator>>(Halmaz& h, double elem)
{
    int index = -1;

    for (int i = 0; i < h.darab; ++i) {
        if (h.tomb[i] == elem) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        double * temp = new double[h.meret() - 1];

        for (int i = 0, j = 0; i<h.darab; i++){
            if (i != index)
                temp[j++] = h.tomb[i];

        }
        delete [] h.tomb;
        h.tomb = temp;
        h.darab--;
    }
    return h;
}

std::ostream& operator<<(std::ostream& os, const Halmaz& h){
    os << "{";
    for (int i = 0; i < h.darab; ++i){
        os << h.tomb[i];
        if (i < h.darab - 1)
            os << ", ";
    }

    os << "}";
    return os;
}



Halmaz operator&(const Halmaz& h1, const Halmaz& h2){
    Halmaz metszet;
    for (int i = 0; i < h1.darab; ++i){
        for (int j = 0; j < h2.darab; ++j){
            if (h1.tomb[i]==h2.tomb[j]){
                metszet << h1.tomb[i];
            }
        }
    }
    return metszet;
}


Halmaz operator|(const Halmaz& h1, const Halmaz& h2){
    Halmaz unio;
        for (int i = 0; i < h1.darab; ++i){

                unio << h1.tomb[i];

        }
        for (int j = 0; j < h2.darab; ++j){

                unio << h2.tomb[j];

        }


    return unio;
}


Halmaz operator-(const Halmaz& h1, const Halmaz& h2){
    Halmaz diff =h1;
    for (int i = 0; i < h1.darab; ++i){
        for (int j = 0; j < h2.darab; ++j){
            if (h1.tomb[i]==h2.tomb[j]){
                diff >> h1.tomb[i];
            }
        }
    }
    return diff;
}


Halmaz operator^(const Halmaz& h1, const Halmaz& h2){
    Halmaz x= (h1|h2);

    for (int i = 0; i < h1.darab; ++i){
        for (int j = 0; j < h2.darab; ++j){
            if (h1.tomb[i]==h2.tomb[j]){

                x >> h1.tomb[i];
            }
        }
    }

return x;

}


Halmaz operator+(const Halmaz& h, double szam){
    Halmaz plus;
    for (int i = 0; i < h.darab; ++i){
        plus << h.tomb[i]+szam;
    }
    return plus;
}

Halmaz operator-(const Halmaz& h, double szam){
    Halmaz minus;
    for (int i = 0; i < h.darab; ++i){
        minus << h.tomb[i]-szam;
    }
    return minus;
}



bool operator<(const Halmaz& h1, const Halmaz& h2){
    if (h1.darab>=h2.darab)
        return false;
    for (int i = 0; i < h1.meret(); ++i){
        bool bennevan = false;
        for (int j = 0; j < h2.meret(); ++j){
            if (h1.tomb[i] == h2.tomb[j]) {
                bennevan = true;
                break;
            }
        }
        if (!bennevan) return false;
    }
    return true;
}


bool operator<=(const Halmaz& bal, const Halmaz& jobb) {
    for (int i = 0; i < bal.meret(); ++i) {
        bool benne_van = false;
        for (int j = 0; j < jobb.meret(); ++j) {
            if (bal.tomb[i] == jobb.tomb[j]) {
                benne_van = true;
                break;
            }
        }
        if (!benne_van) return false;
    }

    return true;
}


bool operator>(const Halmaz& h1, const Halmaz& h2) {
    if (h1.meret() <= h2.meret())
        return false;

    for (int i = 0; i < h2.meret(); ++i) {
        bool bennevan = false;
        for (int j = 0; j < h1.meret(); ++j) {
            if (h2.tomb[i] == h1.tomb[j]) {
                bennevan = true;
                break;
            }
        }
        if (!bennevan)
            return false;
    }

    return true;
}

bool operator>=(const Halmaz& h1, const Halmaz& h2) {
    for (int i = 0; i < h2.meret(); ++i) {
        bool bennevan = false;
        for (int j = 0; j < h1.meret(); ++j) {
            if (h2.tomb[i] == h1.tomb[j]) {
                bennevan = true;
                break;
            }
        }
        if (!bennevan)
            return false;
    }

    return true;
}

bool operator==(const Halmaz& h1, const Halmaz& h2){
    if (h1.meret()!=h2.meret())
        return false;
    for (int i = 0; i < h1.meret(); ++i) {
        if (h1.tomb[i] !=h2.tomb[i])
            return false;
        }
        return true;
}

bool operator!=(const Halmaz& h1, const Halmaz& h2){
    return !(h1==h2);
}

