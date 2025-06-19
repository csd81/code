#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include "trip.h"
#include "filterbase.h"
#include <iostream>
#include <fstream>
using namespace std;
#include  "json.hpp"
using namespace nlohmann;

class TravelAgency
{

    vector<Trip*> trips;

public:
    TravelAgency();
    ~TravelAgency();
    void loadTrips(const string& filename);
    void listTripsBetween(const string& from,  const string& to);
    void promotedTravels();


    void filterTrips(const FilterBase<Trip*>& filter) const;


    static string promotedLocation;
    static string getPromotedLocation();
    static void setPromotedLocation(const string &newPromotedLocation);
};

#endif // TRAVELAGENCY_H
