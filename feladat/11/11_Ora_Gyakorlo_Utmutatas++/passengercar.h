#ifndef PASSENGERCAR_H
#define PASSENGERCAR_H

#include "vehicle.h"

class PassengerCar : public Vehicle
{
int    passengerCount;
public:
    PassengerCar(std::string i, int m, int s, int p);
    std::string getType() const;
    int getPassengerCount();
    void print() const;

};

#endif // PASSENGERCAR_H
