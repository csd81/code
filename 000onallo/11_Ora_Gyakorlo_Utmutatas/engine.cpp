#include "engine.h"

int Engine::getMaxMass() const
{
    return maxMass;
}

Engine::Engine(const std::string &id, int tomeg, int sebesseg, int maxMass) : Vehicle(id, tomeg, sebesseg),
    maxMass(maxMass)
{
type = "ENGINE";
}

std::string Engine::getType() const
{
    return type;
}

void Engine::print() const
{
    std::cout <<  type
    << " "  << getId()
    << ": "  << getMass()
    << " t, max " << getSpeed()
    << " km/h, towing capacity: " << maxMass << " t"<< std::endl;
}
