#ifndef PASSENGERCAR_H
#define PASSENGERCAR_H

#include "vehicle.h"

class PassengerCar : public Vehicle
{
    int passengerCount;
    std::string type;
public:    
    PassengerCar(const std::string &id, int tomeg, int sebesseg, int passengerCount) ;
    std::string getType() const;
    void print() const;

};

#endif // PASSENGERCAR_H
