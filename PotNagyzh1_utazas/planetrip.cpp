#include "planetrip.h"



void PlaneTrip::printData() const
{
    Trip::printData();
    cout << " Osztály: " << travelClass;
}

PlaneTrip::PlaneTrip(const string &source, const string &dest, int duration, int price, const string &travelClass) : Trip(source, dest, duration, price),
    travelClass(travelClass)
{}
