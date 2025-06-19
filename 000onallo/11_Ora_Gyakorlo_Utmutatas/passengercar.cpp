#include "passengercar.h"



PassengerCar::PassengerCar(const std::string &id, int tomeg, int sebesseg, int passengerCount)
: Vehicle(id, tomeg, sebesseg),
    passengerCount(passengerCount)
{
type = "PassengerCar";
}

std::string PassengerCar::getType() const
{
    return type;
}

void PassengerCar::print() const{
    std::cout <<  type
    << " "  << getId()
    << ": "  << getMass()
    << " t, max " << getSpeed()
    << " km/h, max passengers: " << passengerCount << std::endl;
    }
