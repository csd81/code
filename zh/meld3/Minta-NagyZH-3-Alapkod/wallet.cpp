
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "singleusecoupon.h"
#include "multiusecoupon.h"
#include "monthlycoupon.h"
#include "wallet.h"
#include "json.hpp"
using namespace std;
//using namespace nlohmann;

Wallet::Wallet()
{

}

void Wallet::loadCoupons(const std::string &file)
{
    std::ifstream in(file);
    if (!in) {
        std::cerr << "[ERROR] Cannot open file: " << file << std::endl;
        return;
    }

    nlohmann::json js;
    try {
        in >> js;
    } catch (nlohmann::json::parse_error& e) {
        std::cerr << "[ERROR] Failed to parse JSON: " << e.what() << std::endl;
        return;
    }

    if (!js.is_array()) {
        std::cerr << "[ERROR] Expected JSON array at root.\n";
        return;
    }

    for (auto& item : js) {
        if (!item.is_object()) {
            std::cerr << "[WARNING] Skipping non-object item in JSON array.\n";
            continue;
        }

        std::string type = item["Type"];
        int value = item["Value"];

        if (type == "Single use") {
            addCoupon(new SingleUseCoupon(value));
        } else if (type == "Multiple use") {
            int uses = item["TotalUses"];
            addCoupon(new MultiUseCoupon(value, uses));
        } else if (type == "Monthly") {
            int year = item["Year"];
            int month = item["Month"];
            addCoupon(new MonthlyCoupon(value, year, month));
        } else {
            std::cerr << "[WARNING] Unknown coupon type: " << type << std::endl;
        }
    }

    std::cout << "[INFO] Loaded " << js.size() << " coupons from " << file << std::endl;
}





std::vector<Coupon *> Wallet::getCoupons() const
{
    return coupons;
}



void Wallet::addCoupon(Coupon* c)
{
    coupons.push_back(c);
}



void Wallet::listCoupons() const
{
    for (auto c : coupons){
        c->print();
    }
}


void Wallet::exportCounts(const std::string &file)
{
    nlohmann::json js;

    int singleValid =  countCoupons<SingleUseCoupon>(true);
    int singleTotal =  countCoupons<SingleUseCoupon>(false);
    int multiValid  =  countCoupons<MultiUseCoupon>(true);
    int multiTotal  =  countCoupons<MultiUseCoupon>(false);
    int monthlyValid = countCoupons<MonthlyCoupon>(true);
    int monthlyTotal = countCoupons<MonthlyCoupon>(false);

    js["Single use"]["Valid"]   = singleValid;
    js["Single use"]["Invalid"] = singleTotal - singleValid;
    js["Multiple use"]["Valid"]   = multiValid;
    js["Multiple use"]["Invalid"] = multiTotal - multiValid;
    js["Monthly"]["Valid"]   = monthlyValid;
    js["Monthly"]["Invalid"] = monthlyTotal - monthlyValid;

    std::ofstream out(file);
    if (!out) {
        std::cerr << "[ERROR] Could not write to file: " << file << std::endl;
        return;
    }

    out << js.dump(4);
    std::cout << "[INFO] exportCounts wrote to \"" << file << "\"" << std::endl;
}
