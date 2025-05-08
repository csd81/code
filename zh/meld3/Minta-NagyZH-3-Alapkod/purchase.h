#ifndef PURCHASE_H
#define PURCHASE_H

#include <vector>
#include <string>
#include "date.h"
#include "coupon.h"
#include "wallet.h"



class Purchase
{
    struct Item {
        std::string name;
        double unitPrice;
        double quantity;
        std::string unit;
    };
    std::vector<Item*> items;
    int originalAmount;
    int finalAmount;
    Coupon*  usedCoupon;
    Date date;
public:
    Purchase(const Purchase&) = delete;
    Purchase& operator=(const Purchase&) = delete;
    Purchase(const std::string& filename);
    ~Purchase();
    void applyCoupon(Coupon*);
    int useCoupons(Wallet&);
    int getTotal() const;
    void print() const;
};

#endif // PURCHASE_H
