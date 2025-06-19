#include "freightcar.h"

FreightCar::FreightCar(const std::string &id, int tomeg, int sebesseg, int quantity)
: Vehicle(id, tomeg, sebesseg),
    quantity(quantity)
{
type = "FreightCar";
}

std::string FreightCar::getType() const
{
    return type;
}


void FreightCar::print() const{
    std::cout <<  type
    << " "  << getId()
    << ": "  << getMass()
    << " t, max " << getSpeed()
    << " km/h, carrying capacity: " << quantity << " t"<< std::endl;
    }
