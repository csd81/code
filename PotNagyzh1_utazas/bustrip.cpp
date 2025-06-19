#include "bustrip.h"



void BusTrip::printData() const
{
    Trip::printData();
    cout << " pihenők száma: " << restCount;
    cout << " pihenők ideje: " << restDuration;
}

BusTrip::BusTrip(const string &source, const string &dest, int duration, int price, int restCount, int restDuration) : Trip(source, dest, duration, price),
    restCount(restCount),
    restDuration(restDuration)
{}
