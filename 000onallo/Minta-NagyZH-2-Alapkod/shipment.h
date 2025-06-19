#ifndef SHIPMENT_H
#define SHIPMENT_H
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Shipment
{
public:
struct Item{
    string productid;
    int quantity;
};
    vector<Item> items;
    Shipment(const string& filename);
    vector<Item> getItems() const;
};

#endif // SHIPMENT_H
