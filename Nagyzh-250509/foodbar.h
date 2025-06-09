#ifndef FOODBAR_H
#define FOODBAR_H
#include <iostream>
#include <fstream>
#include <vector>
#include "order.h"
#include "food.h"
#include "json.hpp"
using namespace nlohmann;
using namespace std;

class FoodBar
{

    vector<Food*> foods;

public:
    FoodBar(const string& filename);
    void printAll() const;
    void processOrder(Order o);

};

#endif // FOODBAR_H

