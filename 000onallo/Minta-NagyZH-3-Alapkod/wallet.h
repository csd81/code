#ifndef WALLET_H
#define WALLET_H

#include "coupon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
using namespace nlohmann;
using namespace std;

class Wallet
{
protected:
    vector<Coupon*> kuponok;

public:
    Wallet();
    ~Wallet();
    Wallet(const Wallet&) = delete;
    Wallet& operator=(const Wallet&) = delete;
    void addCoupon(Coupon*);

    vector<Coupon *> getKuponok() const;

    void loadCoupons(const string&);

    template<typename T>
    int countCoupons(bool onlyValid = true) const{
        int count =0;
        for (Coupon* k : kuponok){
            if (!k) continue;
            T* casted = dynamic_cast<T*>(k);
            if (casted &&  (!onlyValid  || casted->isValid()))            {
                count++;
            }
        }
        return count;
    }
    void countSingle(int& valid, int& invalid) const;
    void countMonthly(int& valid, int& invalid) const;
    void countMulti(int& valid, int& invalid) const;

    void exportCounts(const string&);
};

#endif // WALLET_H
