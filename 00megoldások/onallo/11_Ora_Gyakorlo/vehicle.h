#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

// Készíts egy absztrakt Vehicle osztályt, amely vasúti járműveket reprezentál. 
// A járműveknek legyen egy azonosítója (string), egy tömege (int), egy sebessége (int) 
// és egy tisztán virtuális getType metódus, ami visszaadja a típusát (string). 
// Az osztálynak legyen egy konstruktora, amely a típuson kívül minden más tulajdonságot megkap paraméterben és beállítja azokat. 
// Legyen virtuális destruktor. 
// Getterek is kellenek a későbbi feladatokhoz (getId, getMass). 
// Készíts a Vehicle osztályba egy tisztán virtuális print metódust. 
// A metódus az egyes járművek tulajdonságait írja ki a standard kimenetre. 
// Valósítsd meg a print metódust a gyerekosztályokban.

class Vehicle
{
protected:
    string id;
    int mass, speed;
public:
    Vehicle(const string& id,
            int mass,
            int speed);
    virtual ~Vehicle()=default;

    virtual void print() const=0;
    virtual string getType() const=0;
    // virtual bool isEngine() const; // default false

    int getMass() const; // TrainSet, engineCanTow()
    string getId() const; // TrainSet, getEngineId()
};

#endif // VEHICLE_H
