#include "pizza.h"
#include <algorithm>

vector<string> Pizza::premiumToppings;


Pizza::Pizza(const string &name) : Food(name, "pizza")
{

}

void Pizza::addTopping(const string& topping)
{
    toppings.push_back(topping);
}

void Pizza::print() const
{
    cout << this->getName() << " " << "feltetek: ";
    for (auto  it : toppings){
        cout << it << " ";
    }

    cout << " ; ";
    cout << price() << " Ft" << endl;
}

void Pizza::addPremiumTopping(string pt)
{
    premiumToppings.push_back(pt);
}

void Pizza::clearPremiumToppings()
{
    premiumToppings.clear();
}


int Pizza::price() const {
    int sum = 2000;
    for (const auto& t : toppings) {
        if (find(premiumToppings.begin(), premiumToppings.end(), t) != premiumToppings.end())
            sum += 500;
        else
            sum += 300;
    }
    return sum;
}
