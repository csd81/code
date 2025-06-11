#ifndef PASSENGERCAR_H
#define PASSENGERCAR_H

#include "vehicle.h"

// PassengerCar: a személykocsikat írja le, legyen egy plusz tulajdonsága, 
// amely a szállítható utasok számát adja meg (int, getPassengerCount). 
// A típus szövege "PassengerCar".

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
