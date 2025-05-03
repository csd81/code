#include "vektor.h"

Vektor::Vektor(unsigned int db):
	darab(db)
{
	elemek=new double[darab];
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

unsigned int Vektor::getDarab() const { return darab; }
double Vektor::getElem(unsigned int index) const { return elemek[index]; }
void Vektor::setElem(unsigned int index, double elem) { elemek[index]=elem; }




Vektor Vektor::operator +(const Vektor &masik) const{
    if (darab==masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i=0; i<darab; i++)
            eredmeny.elemek[i]=elemek[i]+masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}

Vektor &Vektor::operator +=(const Vektor &masik)
{
    if (darab==masik.darab)
    {
        for (unsigned int i=0; i<darab; i++)
            elemek[i]+=masik.elemek[i];
        return *this;
    }
    else
    {
        return *this;
    }
}



Vektor operator +(double ertek, const Vektor &v){
    Vektor eredmeny(v.darab);
        for (unsigned int i = 0; i < v.darab; i++)
            eredmeny.elemek[i] = ertek + v.elemek[i];
        return eredmeny;
};

Vektor & Vektor::operator =(const Vektor &masik)
{
    if (this!=&masik)
    {
        delete [] elemek;
        darab=masik.darab;
        elemek=new double[darab];
        for (unsigned int i=0; i<darab; i++)
            elemek[i]=masik.elemek[i];
    }
    return *this;
}

Vektor &Vektor::operator--(){
    for (unsigned int i=0; i<darab; i++)
        elemek[i]=elemek[i]-1;
    return *this;
}




Vektor Vektor::operator--(int){
    Vektor eredeti(*this);
    for (unsigned int i=0; i<darab; i++)
        elemek[i]=elemek[i]-1;
    return eredeti;
}
ostream& operator <<(ostream &os, const Vektor &v){
    os << "(";
    for (unsigned int i=0; i<v.darab; i++)
    {
        if (i>0) os << " , ";
        os << v.elemek[i];
    }
    os << ")";
    return os;
}
// ---------------------------------------

// Vektor operator -(const Vektor &masik) const{}
Vektor Vektor::operator -(const Vektor &masik) const
{
    if (darab==masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i=0; i<darab; i++)
            eredmeny.elemek[i]=elemek[i]-masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}



// Vektor& operator -=(const Vektor &masik){}
Vektor &Vektor::operator -=(const Vektor &masik)
{
    if (darab==masik.darab)
    {
        for (unsigned int i=0; i<darab; i++)
            elemek[i]-=masik.elemek[i];
        return *this;
    }
    else
    {
        return *this;
    }
}



// Vektor operator -(double ertek, const Vektor &v){}
Vektor operator -(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i=0; i<v.darab; i++)
        eredmeny.elemek[i]=ertek-v.elemek[i];
    return eredmeny;
}



// Vektor operator *(const Vektor &masik) const{}
Vektor Vektor::operator *(const Vektor &masik) const
{
    if (darab==masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i=0; i<darab; i++)
            eredmeny.elemek[i]=elemek[i]*masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}



// Vektor& operator *=(const Vektor &masik){}
Vektor &Vektor::operator *=(const Vektor &masik)
{
    if (darab==masik.darab)
    {
        for (unsigned int i=0; i<darab; i++)
            elemek[i]*=masik.elemek[i];
        return *this;
    }
    else
    {
        return *this;
    }
}



// Vektor operator *(double ertek, const Vektor &v){}
Vektor operator *(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i=0; i<v.darab; i++)
        eredmeny.elemek[i]=ertek*v.elemek[i];
    return eredmeny;
}




// Vektor operator /(const Vektor &masik) const{}
Vektor Vektor::operator /(const Vektor &masik) const
{
    if (darab==masik.darab)
    {
        Vektor eredmeny(darab);
        for (unsigned int i=0; i<darab; i++)
            eredmeny.elemek[i]=elemek[i]/masik.elemek[i];
        return eredmeny;
    }
    else
    {
        return *this;
    }
}


// Vektor& operator /=(const Vektor &masik){}
Vektor &Vektor::operator /=(const Vektor &masik)
{
    if (darab==masik.darab)
    {
        for (unsigned int i=0; i<darab; i++)
            elemek[i]/=masik.elemek[i];
        return *this;
    }
    else
    {
        return *this;
    }
}




// Vektor operator /(double ertek, const Vektor &v){}
Vektor operator /(double ertek, const Vektor &v)
{
    Vektor eredmeny(v.darab);
    for (unsigned int i=0; i<v.darab; i++)
        eredmeny.elemek[i]=ertek/v.elemek[i];
    return eredmeny;
}






// Vektor operator +(double ertek) const{}
Vektor Vektor::operator +(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i=0; i<darab; i++)
        eredmeny.elemek[i]=elemek[i]+ertek;
    return eredmeny;
}




// Vektor operator -(double ertek) const{}
Vektor Vektor::operator -(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i=0; i<darab; i++)
        eredmeny.elemek[i]=elemek[i]-ertek;
    return eredmeny;
}


//Vektor operator *(double ertek) const{}
Vektor Vektor::operator *(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i=0; i<darab; i++)
        eredmeny.elemek[i]=elemek[i]*ertek;
    return eredmeny;
}


//Vektor operator /(double ertek) const{}
Vektor Vektor::operator /(double ertek) const
{
    Vektor eredmeny(darab);
    for (unsigned int i=0; i<darab; i++)
        eredmeny.elemek[i]=elemek[i]/ertek;
    return eredmeny;
}



//Vektor& operator++(){}
Vektor &Vektor::operator++()
{
    for (unsigned int i=0; i<darab; i++)
        elemek[i]=elemek[i]+1;
    return *this;
}



//Vektor operator++(int){   }
Vektor Vektor::operator++(int)
{
    Vektor eredeti(*this);
    for (unsigned int i=0; i<darab; i++)
        elemek[i]=elemek[i]+1;
    return eredeti;
}




//double& operator [](unsigned int index){}
double &Vektor::operator [](unsigned int index)
{
    return elemek[index];
}



//const double& operator [](unsigned int index) const{}
const double &Vektor::operator [](unsigned int index) const
{
    return elemek[index];
}




//double operator ^(const Vektor &masik) const{}
double Vektor::operator ^(const Vektor &masik) const
{
    if (darab==masik.darab)
    {
        double ertek=0;
        for (unsigned int i=0; i<darab; i++)
            ertek+=elemek[i]*masik.elemek[i];
        return ertek;
    }
    else
    {
        return 0;
    }
}


//double operator *() const{}
double Vektor::operator *() const
{
    double osszeg=0;
    for (unsigned int i=0; i<darab; i++)
        osszeg+=elemek[i]*elemek[i];
    return sqrt(osszeg);
}







//Vektor operator ~() const{}
Vektor Vektor::operator ~() const
{
    Vektor eredmeny(darab);
    double hossz=**this;
    // Igen, furán néz ki, de gondljuk át: A this egy mutató az adott objektumra. A *this egy referencia az adott objektumra.
    // A **this így a * operátor meghívva egy referenciára, ami nem mutató, aminek alapból nincs értelme.
    // Viszont az előző feladatban el kellett készíteni a * operátort a Vektorra, ami a hosszát adja vissza, tehát jelen esetben van értelme.
    for (unsigned int i=0; i<darab; i++)
        eredmeny.elemek[i]=elemek[i]/hossz;
    return eredmeny;
}


//bool operator ==(const Vektor &masik) const{}
bool Vektor::operator ==(const Vektor &masik) const
{
    if (darab!=masik.darab) return false;
    else
    {
        bool ok=true;
        for (unsigned int i=0; i<darab; i++)
        {
            if (elemek[i]!=masik.elemek[i]) ok=false; // Ha bárhol nem egyezik, akkor hamis.
        }
        return ok;
    }
    // Lehetne így is:
    //	if (darab!=masik.darab) return false;
    //	for (unsigned int i=0; i<darab; i++)
    //	{
    //		if (elemek[i]!=masik.elemek[i]) return false;
    //	}
    //	return true;
}


bool Vektor::operator !=(const Vektor &masik) const
{
    if (darab!=masik.darab) return true;
    else
    {
        bool ok=false;
        for (unsigned int i=0; i<darab; i++)
        {
            if (elemek[i]!=masik.elemek[i]) ok=true; // Ha bárhol nem egyezik, akkor igaz.
        }
        return ok;
    }
    // Vagy egyszerűbben, az előzőt felhasználva:
    //	return !(*this==masik);
}


bool Vektor::operator <(const Vektor &masik) const{
    if (darab!=masik.darab) return false;
    else
    {
        bool ok=true;
        for (unsigned int i=0; i<darab; i++)
        {
            if (!(elemek[i]<masik.elemek[i])) ok=false; // Ha bárhol nem kisebb, akkor hamis.
        }
        return ok;
    }
}











