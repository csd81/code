#include "travelagency.h"
#include "bustrip.h"
#include "planetrip.h"
#include "traintrip.h"
#include "filterbase.h"

string TravelAgency::promotedLocation ="";

string TravelAgency::getPromotedLocation()
{
    return promotedLocation;
}

void TravelAgency::setPromotedLocation(const string &newPromotedLocation)
{
    promotedLocation = newPromotedLocation;
}

TravelAgency::TravelAgency() {}

TravelAgency::~TravelAgency()
{
    for (Trip* t : trips)
        delete t;

}

void TravelAgency::loadTrips(const string &filename)
{
    ifstream ifs(filename);
    json data;
    ifs  >> data;

    for (size_t i=0; i< data.size(); i++){
        string from=data[i]["From"];
        string to=data[i]["To"];
        int time=data[i]["TravelTime"];
        int price=data[i]["Price"];
            if  (data[i]["Type"] == "Train"){
                int stops =data[i]["Stops"];
                trips.push_back(new TrainTrip(from, to, time, price, stops));
            } else if (data[i]["Type"] == "Plain"){
                string osztaly=data[i]["Class"];
                trips.push_back(new PlaneTrip(from, to, time, price, osztaly));
            } else if (data[i]["Type"] == "Bus"){
                int stops =data[i]["Stops"];
                int totalstoptime =data[i]["TotalStopTime"];
                trips.push_back(new BusTrip(from, to, time, price, stops, totalstoptime));
        }

    }
}

void TravelAgency::listTripsBetween(const string &from, const string &to)
{
        bool kozvetlen = false;

    for (auto t: trips){
       if (t->getSource()==from && t->getDest()==to){
            t->printData();
            cout << endl;
            kozvetlen = true;
            }
    }
    if (kozvetlen) return;

    cout << "Nincs közvetlen járat " << from << " és " << to << " között!" << std::endl;
    cout << "Keresés 1 átszállással..." << std::endl;

    bool vanatszallas = false;

    for (Trip* elso : trips) {
        if (elso->getSource() == from) {
            string atszallas = elso->getDest();

            for (Trip* masodik : trips) {
               if (masodik->getSource()== atszallas && masodik->getDest() == to){
                    cout << "1. szakasz:" << endl;
                    elso->printData();
                    cout << endl;

                    cout << "2. szakasz:" << endl;
                    masodik->printData();
                    cout << endl;

                    vanatszallas = true;
               }
            }
        }
     }

    if (!vanatszallas) {
        std::cout << "1 átszállással sem lehetséges." << std::endl;
    }
}

void TravelAgency::promotedTravels()
{
    for (auto t: trips){
       if (t->getDest()==TravelAgency::promotedLocation)
            t->printData();
    }
}

void TravelAgency::filterTrips(const FilterBase<Trip *> &filter) const
{
    for (Trip* t: trips){
        if (filter.match(t)) {
            t->printData();
            cout << endl;
        }
    }
}







