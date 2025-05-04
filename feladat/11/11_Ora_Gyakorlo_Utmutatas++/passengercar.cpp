#include "passengercar.h"
#include <iostream>

PassengerCar::PassengerCar(std::string i, int m, int s, int p) :
    Vehicle(i,m,s),
    passengerCount(p)
{}
std::string PassengerCar::getType() const{
    return "PassengerCar";
}
int PassengerCar::getPassengerCount(){
    return passengerCount;
}


void PassengerCar::print() const{
    std::cout << "ID: " << PassengerCar::getId() <<"\n";
    std::cout << "Mass: " << PassengerCar::getMass() << "\n";
    std::cout << "Speed: " << PassengerCar::getSpeed() << "\n";
    std::cout << "Passenger count: " << passengerCount << "\n";
}
