#include "freightcar.h"
#include <iostream>

FreightCar::FreightCar(std::string i, int m, int s, int f) :
    Vehicle(i,s,m),
    freightCapacity(f)
{}

std::string FreightCar::getType() const{
    return "FreightCar";
}

void FreightCar::print() const{
    std::cout << "ID: " << FreightCar::getId() <<"\n";
    std::cout << "Mass: " << FreightCar::getMass() << "\n";
    std::cout << "Speed: " << FreightCar::getSpeed() << "\n";
    std::cout << "Freight capacity: " << freightCapacity << "\n";
}
