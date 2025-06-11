#ifndef ENGINE_H
#define ENGINE_H

#include "vehicle.h"

// Engine: a mozdonyt reprezentálja, legyen egy plusz tulajdonsága, 
// amely a mozdony által elvontatható tömeget adja meg (int). 
// A típus szövege "ENGINE".

class Engine : public Vehicle
{
    int towableMass;
public:
    Engine(const string& id,
           int mass,
           int speed,
           int towableMass);

    int getTowableMass() const;

    void print() const;

    string getType() const;

    // bool isEngine() const; // return true
};

#endif // ENGINE_H
