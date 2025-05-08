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


Purchase::Purchase(const std::string& filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "[ERROR] Could not open file: " << filename << std::endl;
        return;
    }
    json js;
    try {
        in >> js;
    } catch (json::parse_error& e) {
        std::cerr << "[ERROR] JSON parse error: " << e.what() << " (byte: " << e.byte << ")" << std::endl;
        return;
    }

    if (!js.is_array()) { // Changed this check
        std::cerr << "[ERROR] Invalid JSON format: Expected a JSON array." << std::endl;
        return;
    }

    for (auto& elem : js) { // Iterate directly over the array
        Item* item = new Item;
        item->name = elem["Name"];
        item->unitPrice = elem["UnitPrice"];
        item->quantity = elem["Quantity"]["Value"];
        item->unit = elem["Quantity"]["Unit"];
        items.push_back(item);
    }

    originalAmount = 0;
    for (unsigned i = 0; i < items.size(); i++) {
        originalAmount += items[i]->quantity * items[i]->unitPrice;
    }
    finalAmount = originalAmount;
    usedCoupon = nullptr;
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
    cout << "Purchase Items:\n";
    for (unsigned i = 0; i < items.size(); i++) {
        cout << "  Item " << i + 1 << ":\n";
        cout << "    Name: " << items[i]->name << "\n";
        cout << "    Unit Price: " << items[i]->unitPrice << "\n";
        cout << "    Quantity: " << items[i]->quantity << "\n";
        cout << "    Unit: " << items[i]->unit << "\n";
    }

    cout << "\nOriginal Amount: " << originalAmount << "\n";
    cout << "Final Amount: " << finalAmount << "\n";

    if (usedCoupon != nullptr) {
        cout << "\nUsed Coupon Details:\n";
        usedCoupon->print();
    }
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


