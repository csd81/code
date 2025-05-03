#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
protected:
    string id;
    int mass, speed;
public:
    Vehicle(const string& id,
            int mass,
            int speed);
    virtual ~Vehicle()=default;

    virtual void print() const=0;
    virtual string getType() const=0;
    // virtual bool isEngine() const; // default false

    int getMass() const; // TrainSet, engineCanTow()
    string getId() const; // TrainSet, getEngineId()
};

#endif // VEHICLE_H
