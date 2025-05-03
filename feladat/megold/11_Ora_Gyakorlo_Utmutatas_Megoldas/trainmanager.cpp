#include "trainmanager.h"

#include <iostream>
using namespace std;

TrainManager::~TrainManager()
{
    // ezert kell a Vehicle-be virtualis destruktor
    for (size_t i=0;i<vehicles.size();i++)
        delete vehicles[i];

    for (size_t k=0;k<sets.size();k++)
        delete sets[k];
}

void TrainManager::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

void TrainManager::printAll() const
{
    cout << "--- Nyilvantartott jarmuvek:" << endl;
    for (size_t i=0;i<vehicles.size();i++)
        vehicles[i]->print();
}

bool TrainManager::coupleSet(const vector<Vehicle*>& vehiclesToUse)
{
    TrainSet* set = new TrainSet(vehiclesToUse);
    if (set->isValid())
    {
        sets.push_back(set);
        return true;
    }
    else
    {
        delete set;
        return false;
    }
}

TrainSet* TrainManager::searchSet(const string &engineId) const
{
    for (size_t k=0;k<sets.size();k++)
        if(sets[k]->getEngine()->getId() == engineId)
            return sets[k];
    return nullptr;
}

void TrainManager::printSets() const
{
    cout << "--- Nyilvantartott szerelvenyek:" << endl;
    for (size_t k=0;k<sets.size();k++)
        sets[k]->printAll();
}

void TrainManager::decoupleSet(TrainSet* set)
{
    delete set; // innentol lekerdezni mar nem lehet
    for (size_t k=0;k<sets.size();k++)
    {
        if (sets[k] == set)
        {
            for (size_t j=k+1;j<sets.size();j++)
                sets[j-1] = sets[j];
            sets.pop_back();
        }
    }
}

void TrainManager::removeVehicle(Vehicle *vehicle)
{
    delete vehicle; // innentol lekerdezni mar nem lehet
    for (size_t i=0;i<vehicles.size();i++)
    {
        if (vehicles[i] == vehicle)
        {
            for (size_t j=i+1;j<vehicles.size();j++)
                vehicles[j-1] = vehicles[j];
            vehicles.pop_back();
        }
    }
}
