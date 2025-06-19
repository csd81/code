#ifndef BUSTRIP_H
#define BUSTRIP_H
#include <iostream>
using namespace std;

#include "trip.h"

class BusTrip : public Trip
{   int restCount;
    int restDuration;

public:

    BusTrip(const string &source, const string &dest, int duration, int price, int restCount, int restDuration);
    void printData() const override;
};

#endif // BUSTRIP_H
