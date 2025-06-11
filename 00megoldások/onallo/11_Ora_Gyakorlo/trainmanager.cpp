#include "trainmanager.h"

#include <iostream>
using namespace std;

// Hozz létre egy TrainManager osztályt, amely a vasúti járműveink kezelését valósítja meg. 
// Az osztály egy vektorban (vector<Vehicle*>) tárolja a járműveinket, amiket egyenként dinamikusan kell foglalnunk. 
// A tároló kezdetben üres.

TrainManager::~TrainManager()
{
    // ezért kell a Vehicle-be virtuális destruktor
    for (size_t i=0;i<vehicles.size();i++)
        delete vehicles[i];

    for (size_t k=0;k<sets.size();k++)
        delete sets[k];
}

// Legyen addVehicle metódus a TrainManager osztályban, amely paraméterben egy járművet vár (Vehicle*) és hozzáadja a tárolóhoz.

void TrainManager::addVehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}

// Legyen egy printAll metódus TrainManager osztályban, amely kiírja a járművek adatait. 
// Ehhez használja a járművek print metódusát.

void TrainManager::printAll() const
{
    cout << "--- Nyilvantartott jarmuvek:" << endl;
    for (size_t i=0;i<vehicles.size();i++)
        vehicles[i]->print();
}

// Módosítsd a TrainManager osztályt úgy, hogy szerelvényeket is tudjon tárolni tetszőleges mennyiségben (vector<TrainSet*>).

// Legyen egy coupleSet metódus a TrainManager osztályban, ami paraméterben várja a járművek vektorát, 
// azokból összeállít egy szerelvényt és eltárolja azt. 
// Csak érvényes szerelvényt lehet eltárolni, különben a szerelvényt azonnal törölni is kell.

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

// Legyen egy searchSet metódus a TrainManager osztályban, ami paraméterben egy mozdony azonosítóját kapja meg (string), 
// és ez alapján visszaadja a szerelvényt (TrainSet*). 
// Ha nem találja a szerelvényt, akkor nullptr-t adjon vissza.

TrainSet* TrainManager::searchSet(const string &engineId) const
{
    for (size_t k=0;k<sets.size();k++)
        if(sets[k]->getEngine()->getId() == engineId)
            return sets[k];
    return nullptr;
}

// Legyen egy printSets metódus a TrainManager osztályban, amely kiírja a tárolt szerelvények adatait. 
// Ehhez a TrainSet osztályban is ajánlott csinálni egy printAll metódust.

void TrainManager::printSets() const
{
    cout << "--- Nyilvantartott szerelvenyek:" << endl;
    for (size_t k=0;k<sets.size();k++)
        sets[k]->printAll();
}

// Legyen egy decoupleSet metódus a TrainManager osztályban, ami egy szerelvényt vár paraméterben (TrainSet*), 
// és eltávolítja azt a szerelvények közül.

void TrainManager::decoupleSet(TrainSet* set)
{
    delete set; // innentől lekérdezni már nem lehet
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

// Legyen egy removeVehicle metódus a TrainManager osztályban, ami egy járművet vár paraméterben, 
// és eltávolítja azt a tároltak közül (a szerelvényekben lévőkkel nem kell foglalkozni).

void TrainManager::removeVehicle(Vehicle *vehicle)
{
    delete vehicle; // innentől lekérdezni már nem lehet
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
