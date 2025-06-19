#include "vektor.h"

Vektor::Vektor(unsigned int db):
	darab(db)
{
    elemek = new double[darab];
    for (unsigned int i=0; i<darab; i++)
        elemek[i]=0.0;
}

Vektor::Vektor(const Vektor &masik):
	darab(masik.darab)
{
	elemek=new double[darab];
	for (unsigned int i=0; i<darab; i++)
		elemek[i]=masik.elemek[i];
}

Vektor::~Vektor()
{
	delete [] elemek;
}

unsigned int Vektor::getDarab() const
{
	return darab;
}

double Vektor::getElem(unsigned int index) const
{
	return elemek[index];
}

void Vektor::setElem(unsigned int index, double elem)
{
	elemek[index]=elem;
}

//friend
Vektor operator+(const Vektor& v1, const Vektor& v2){
        if (v1.darab != v2.darab){
            std::cerr << "nem = meretűek";
        }

    Vektor uj(v1.darab);
    for (unsigned int i=0; i < v1.darab; i++){
        uj.elemek[i] = v1.elemek[i] + v2.elemek[i];
    }
    return uj;
}
//friend
Vektor operator-(const Vektor& v1, const Vektor& v2){
        if (v1.darab != v2.darab){
            std::cerr<< "!!";
        }
    Vektor uj(v1.darab);
    for (unsigned int i= 0; i < v1.darab; i++){
        uj.elemek[i] = v1.elemek[i] - v2.elemek[i];
        }
    return uj;
}
//friend
Vektor operator*(const Vektor& v1, const Vektor& v2){
        if (v1.darab != v2.darab){
            std::cerr << '!';
        }
        Vektor uj(v1.darab);
        for (unsigned int i=0; i< v1.darab; i++){
            uj.elemek[i] = v1.elemek[i] * v2.elemek[i];
        }
    return uj;
}
//friend
Vektor operator/(const Vektor& v1, const Vektor& v2){
        if (v1.darab != v2.darab){
            std::cerr << '!';
        }
        Vektor uj(v1.darab);
        for (unsigned int i=0; i<v1.darab; i++){
            uj.elemek[i] = v1.elemek[i]/v2.elemek[i];
        }
    return uj;

}

//friend
double operator^(const Vektor& v1, const Vektor& v2){
    if (v1.darab != v2.darab){
            std::cerr << '!';
        }
    double osszeg =0.0;
    for (unsigned int i=0; i<v1.darab; i++){
        osszeg+= v1.elemek[i] * v2.elemek[i];
    }
    return osszeg;
}


Vektor &Vektor::operator+=(const Vektor &masik)
{
    if (this->darab != masik.getDarab()){
        std::cerr << "error";
        }
    else {
        for (unsigned int i=0; i < this->darab; i++){
            this->elemek[i]+=masik.elemek[i];
        }
    }
    return *this;
}

Vektor& Vektor::operator-=(const Vektor &masik){
    if (this->darab != masik.getDarab()){
        std::cerr<< "!";
    } else {
        for (unsigned int i=0; i<this->darab; i++){
            this->elemek[i]-= masik.elemek[i];
        }
    }
    return *this;
}

Vektor& Vektor::operator*=(const Vektor &masik){
    if (this->darab != masik.getDarab()){
        std::cerr<< "!";
    } else {
        for (unsigned int i=0; i<this->darab; i++){
            this->elemek[i]*= masik.elemek[i];
        }
    }
    return *this;
}
Vektor& Vektor::operator/=(const Vektor &masik){
    if (this->darab != masik.getDarab()){
        std::cerr<< "!";
    } else {
        for (unsigned int i=0; i<this->darab; i++){
            this->elemek[i]/= masik.elemek[i];
        }
    }
    return *this;
}

Vektor& Vektor::operator=(const Vektor &masik)
{
    if (this==&masik)
        return *this;
    else {
        delete[] elemek;
        darab= masik.darab;
        elemek = new double[darab];
        for (unsigned int i = 0; i < darab; i++){
            elemek[i]=masik.elemek[i];
        }

    }
    return *this;
}


// friend
Vektor operator+(double d, const Vektor& v){

    Vektor uj(v.darab);
    for (unsigned int i=0; i < v.darab; i++){
        uj.elemek[i] =   d+v.elemek[i] ;
    }

    return uj;
}

Vektor operator+(const Vektor& v, double d)
{
    return  d+v;  // a másik operator+ meghívása
}

// friend
Vektor operator-(double d, const Vektor& v){
    Vektor uj(v.darab);
    for (unsigned int i=0; i < v.darab; i++){
        uj.elemek[i] =   d-v.elemek[i] ;
    }
    return uj;
}
Vektor operator-(const Vektor& v, double d){
    Vektor uj(v.darab);
    for (unsigned int i=0; i < v.darab; i++){
        uj.elemek[i] =   v.elemek[i] - d;
    }
    return uj;
}

// friend
Vektor operator/(double d, const Vektor& v){
    Vektor uj(v.darab);
    for (unsigned int i=0; i < v.darab; i++){
        uj.elemek[i] =   d/v.elemek[i] ;
    }
    return uj;
}

Vektor operator/(const Vektor& v, double d){
    Vektor uj(v.darab);
    for (unsigned int i=0; i < v.darab; i++){
        uj.elemek[i] =   v.elemek[i] /d;
    }
    return uj;
}


// friend
Vektor operator*(double d, const Vektor& v){
    Vektor uj(v.darab);
    for (unsigned int i=0; i < v.darab; i++){
        uj.elemek[i] =   d*v.elemek[i] ;
    }
    return uj;
}
Vektor operator*(const Vektor& v, double d)
{
    return  d*v;  // a másik operator+ meghívása
}

Vektor &Vektor::operator--()
{
    for (unsigned int i = 0; i < darab; i++){
        elemek[i]--;
    }
    return *this;
}


Vektor Vektor::operator--(int){
    Vektor temp(*this);

    for (unsigned int i = 0; i < darab; i++){
        --elemek[i];
    }
    return temp;
}

Vektor &Vektor::operator++()
{
    for (unsigned int i = 0; i < darab; i++){
        elemek[i]++;
    }
    return *this;
}

double &Vektor::operator[](unsigned int i)
{
    return elemek[i];
}


const double &Vektor::operator[](unsigned int i)const
{
    return elemek[i];
}

Vektor Vektor::operator++(int){
    Vektor temp(*this);

    for (unsigned int i = 0; i < darab; i++){
        ++elemek[i];
    }
    return temp;
}

// friend
std::ostream &operator<<(std::ostream& os, const Vektor& v){

    os <<  "(";
    if (v.getDarab() > 0)
    {
    os << v.getElem(0);
    for (unsigned int i=1; i < v.getDarab(); i++)
        {
             os << " , " << v.getElem(i);
        }
    }
    os << ")";

    return os;
}



double Vektor::operator*() const{
    double sum = 0.0;
    for (unsigned int i = 0; i < darab; i++){
        sum+= elemek[i] * elemek[i];
    }
    return std::sqrt(sum);

}

Vektor Vektor::operator~() const{
        double len = **this;  // használjuk az operator*()-t

    if (len == 0.0)
    {
        throw std::domain_error("Nullvektor nem normalizalhato!");
    }

    Vektor uj(darab);
    for (unsigned int i = 0; i < darab; i++)
    {
        uj.elemek[i] = elemek[i] / len;
    }

    return uj;
}


//friend
bool operator==(const Vektor& v1, const Vektor& v2){
        if (v1.getDarab() != v2.getDarab())
        return false;

    for (unsigned int i = 0; i < v1.getDarab(); i++)
    {
        if (v1.getElem(i) != v2.getElem(i))
            return false;
    }

    return true;
}
//friend

bool operator!=(const Vektor& v1, const Vektor& v2){
         return !(v1 == v2);
}
//friend
bool operator<(const Vektor& v1, const Vektor& v2){
        if (v1.getDarab() != v2.getDarab())
        return false;

    for (unsigned int i = 0; i < v1.getDarab(); i++)
    {
        if (v1.getElem(i) >= v2.getElem(i))
            return false;
    }

    return true;
}
