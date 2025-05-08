#include "monthlycoupon.h"
#include<iostream>

using namespace std;


MonthlyCoupon::MonthlyCoupon(int validYear, int validMonth, int value) : Coupon(value),
    validYear(validYear),
    validMonth(validMonth)
{
    used = false;
}

bool MonthlyCoupon::isValid(const Date& date) const
{

    if (date.getYear() == validYear && date.getMonth() == validMonth && !used)
        return true;
    return false;
}

int MonthlyCoupon::apply(int amount, const Date& date)
{
    if (this->isValid(date))
        return amount-value;
    return amount;
}

void MonthlyCoupon::use()
{
    used = true;
}

void MonthlyCoupon::print() const
{
    cout << "MonthlyCoupon: "
         << value << " Ft, valid: "
         << validYear << "." << validMonth
         << ", used: " << (used ? "yes" : "no") << endl;

}

void MonthlyCoupon::setCurrentDate(int y, int m, int d)
{
    Date newDate(y, m, d);             // Konstruktorral hozunk létre dátumot
    Date::setCurrentDate(newDate);     // Beállítjuk a globális dátumot
}

