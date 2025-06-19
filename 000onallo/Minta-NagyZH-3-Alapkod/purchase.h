#ifndef PURCHASE_H
#define PURCHASE_H
#include <iostream>
#include <fstream>
#include <vector>
#include "wallet.h"
#include "json.hpp"

using namespace nlohmann;
using namespace std;

class Purchase
{

struct Item{
    string Name;
    int UnitPrice;
    double QuantityValue;
    string QuantityUnit;
    void printdata() const;


};
    vector<Item> items;
public:

    Purchase(const string& filename);
    void print();
    double getTotal();

    double  useCoupons(Wallet&);


};

#endif // PURCHASE_H



