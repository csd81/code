#ifndef WALLET_H
#define WALLET_H
#include "coupon.h"
#include <string>
#include <vector>

class Wallet
{
    std::vector<Coupon*>  coupons;
public:

    Wallet();
    ~Wallet()=default;
    void addCoupon(Coupon*);
    void listCoupons() const;
    void loadCoupons(const std::string& file);
    void exportCounts(const std::string& file);
    std::vector<Coupon *> getCoupons() const;

    template <typename T>
    int countCoupons(bool onlyValid)
    {
        int counter = 0;
        for (Coupon* c : coupons){
            T* typedCoupon = dynamic_cast<T*>(c);
            if (onlyValid){
                if (typedCoupon && typedCoupon->isValid(Date::getCurrentDate()))
                    counter++;
            } else {
                if (typedCoupon)
                    counter++;
            }

        }
        return counter;
    }
};

#endif // WALLET_H
