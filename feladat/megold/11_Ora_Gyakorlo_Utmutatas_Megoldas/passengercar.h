#ifndef PASSENGERCAR_H
#define PASSENGERCAR_H

#include "vehicle.h"

class PassengerCar : public Vehicle
{
    int passengerCount;
public:
    PassengerCar(const string& id,
                 int mass,
                 int speed,
                 int passengerCount);

    void print() const;

    string getType() const;
};

#endif // PASSENGERCAR_H
