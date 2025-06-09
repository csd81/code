#ifndef PIZZA_H
#define PIZZA_H

#include "food.h"

class Pizza : public Food
{
    vector<string> toppings;
public:

    static  vector<string> premiumToppings;
    Pizza(const string &name);
    vector<string> getToppings() const;
    void addTopping(const string& topping);
    void print() const;
    static  void addPremiumTopping(string pt);
    static  void clearPremiumToppings();
    int price() const;
};

#endif // PIZZA_H


