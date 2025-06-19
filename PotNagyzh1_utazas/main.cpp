#include <iostream>
#include "trip.h"
#include "travelagency.h"

using namespace std;

#define PART1  // Utazások adatszerkezete
#define PART2  // TravelAgency osztály, loadTrips, JSON betöltés
#define PART3  // printData metódus
#define PART4  // listTripsBetween metódus
#define PART5  // Promóciós helyszín kezelése
#define PART6  // promotedTravels metódus
#define PART7  // FilterBase<T> osztály
#define PART8  // filterTrips metódus
#define PART9  // MaxTimeFrom osztály
#define PART10 // listTripsBetween metódus egy átszállással


#ifdef PART7
#include "filterbase.h"
class FilterTestTripTo : public FilterBase<Trip*>
{
    string to;
public:
    FilterTestTripTo(const string &to):
        to(to)
    {}
    bool match(Trip * const &trip) const override
    {
        return trip->getDest() == to;
    }
};
#endif

#ifdef PART9
#include "maxtimefrom.h"
#endif

int main()
{
    cout << "main eleje" << endl << endl;

#if defined(PART1) && defined(PART2)
    cout << endl << "Loading trips..." << endl;
    TravelAgency agency;
    agency.loadTrips("trips.json");
#endif

#if defined(PART3) && defined(PART4)
    cout << endl << "Travel options from Becs to Parizs:" << endl;
    agency.listTripsBetween("Becs", "Parizs");
#endif

#ifdef PART5
    cout << endl << "Promoted location test..." << endl;
    cout << "Promoted location: " << TravelAgency::getPromotedLocation() << endl;
    TravelAgency::setPromotedLocation("Madrid");
    cout << "Promoted location: " << TravelAgency::getPromotedLocation() << endl;
    TravelAgency::setPromotedLocation("London");
    cout << "Promoted location: " << TravelAgency::getPromotedLocation() << endl;
#endif

#ifdef PART6
    cout << endl << "Listing promoted travels..." << endl;
    TravelAgency::setPromotedLocation("Parizs");
    cout << endl << "-------Travels to " << TravelAgency::getPromotedLocation() << "-------" << endl;
    agency.promotedTravels();
    TravelAgency::setPromotedLocation("Milano");
    cout << endl << "-------Travels to " << TravelAgency::getPromotedLocation() << "-------" << endl;
    agency.promotedTravels();
#endif

#ifdef PART7
    cout << endl << "FilterBase<T> test seemingly ok..." << endl;
#endif

#ifdef PART8
    cout << endl << "Filter trips that arrive at Milano..." << endl;
    FilterTestTripTo testFilter("Milano");
    agency.filterTrips(testFilter);
#endif

#ifdef PART9
    cout << endl << "Filter trips at most 2 hour trips from Budapest..." << endl;
    MaxTimeFrom testFilter2("Budapest", 120);
    agency.filterTrips(testFilter2);
#endif

#ifdef PART10
    cout << endl << "Travel options from Budapest to Milano:" << endl;
    agency.listTripsBetween("Budapest", "Milano");
#endif


    cout << endl << "main() vege!" << endl;

    return 0;
}
