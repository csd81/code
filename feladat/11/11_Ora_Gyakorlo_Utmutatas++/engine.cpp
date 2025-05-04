#include "engine.h"
#include <iostream>


Engine::Engine(std::string i, int m, int s, int tc) :
    Vehicle(i, m, s),
    towingCapacity(tc)
{}

std::string Engine::getType() const{
    return "ENGINE";
}

void Engine::print() const{
    std::cout << "ID: " << Engine::getId() <<"\n";
    std::cout << "Mass: " << Engine::getMass() << "\n";
    std::cout << "Speed: " << Engine::getSpeed() << "\n";
    std::cout << "TowingCapacity: " << towingCapacity << "\n";
}

int Engine::getTowingCapacity() const{
    return towingCapacity;
}
