#ifndef COUPON_H
#define COUPON_H
#include "date.h"

class Coupon
{
protected:
    int value;
public:
   explicit Coupon(int value);
   virtual ~Coupon();
   virtual bool isValid(const Date& date) const = 0;
   virtual int apply(int amount, const Date& date) = 0;
   virtual void use() = 0;
   virtual void print() const = 0;
};

#endif // COUPON_H
