#include "passengercar.h"

#include <iostream>
using namespace std;

PassengerCar::PassengerCar(const string &id,
                           int mass,
                           int speed,
                           int passengerCount):
    Vehicle(id, mass, speed),
    passengerCount(passengerCount)
{
}

void PassengerCar::print() const
{
    cout << getType() << " " << id << ": ";
    cout << mass << " t, ";
    cout << "max " << speed << " km/h, ";
    cout << "max passengers: " << passengerCount;
    cout << endl;
}

string PassengerCar::getType() const
{
    return "PassengerCar";
}
