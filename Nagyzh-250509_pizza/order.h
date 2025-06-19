#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Order
{
    struct Item{
        string name;
        string type;
        int quantity;
    };

public:
    vector<Order::Item> items;
    static Order loadOrder(const string& filename);
    friend ostream& operator<<(ostream& os, const Order& order);

};

#endif // ORDER_H


