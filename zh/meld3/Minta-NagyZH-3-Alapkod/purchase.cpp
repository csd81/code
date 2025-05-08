#include "purchase.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include "date.h"
#include "coupon.h"
#include "wallet.h"
#include "json.hpp"
using namespace std;
using namespace nlohmann;


Purchase::Purchase(const std::string& filename)
{
    ifstream in(filename);
    json js;
    in >> js;


    for(auto& elem : js["items"]){
        Item* item  = new Item;
            item->name =  elem["name"];
        item->unitPrice = static_cast<int>(std::round(elem["UnitPrice"].get<double>()));
            item->quantity = elem["Quantity"];
            item->unit = elem["Unit"];
            items.push_back(item);
    }
        originalAmount = 0;
    for(unsigned i=0; i < items.size(); i++){
     originalAmount +=   items[i]->quantity * items[i]->unitPrice;
    }
    finalAmount = originalAmount;
    usedCoupon  = nullptr;
}

Purchase::~Purchase()
{
    for(unsigned i=0; i < items.size(); i++){
        delete items[i];
    }
    delete usedCoupon;
}

void Purchase::print() const
{
    for(unsigned i=0; i < items.size(); i++){
        cout <<  items[i]->name         << items[i]->unitPrice
             << items[i]->quantity         << items[i]->unit << endl;
    }

    cout << originalAmount;
    cout << finalAmount;
    if (usedCoupon  != nullptr)
        usedCoupon->print();
}


void Purchase::applyCoupon(Coupon* c)
{
    finalAmount = c->apply(originalAmount, Date::currentDate);
    c->use();
    usedCoupon = c;

}

int Purchase::useCoupons(Wallet& w)
{
    Date  d = Date::getCurrentDate();
    Coupon* bestcoupon = nullptr;
    int maxBenefit = 0;

    for (Coupon* c : w.getCoupons()){
        if (c->isValid(d)){
            int discounted = c->apply(originalAmount, d);
            int benefit = originalAmount-discounted ;
            if (benefit>maxBenefit){
                maxBenefit = benefit;
                bestcoupon = c;
            }
        }

    }
    if (bestcoupon)
        applyCoupon(bestcoupon);
    return finalAmount;
}

int Purchase::getTotal() const
{
    return finalAmount;
}


