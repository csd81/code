#include "wallet.h"
#include "monthlycoupon.h"
#include "multicoupon.h"
#include "singlecoupon.h"
#include <iomanip>

vector<Coupon *> Wallet::getKuponok() const
{
    return kuponok;
}

void Wallet::loadCoupons(const string & fn)
{
    ifstream ifs(fn);
    if (!ifs.is_open()) {
    cerr << "Nem sikerült megnyitni: " << fn << endl;
    return;
}

    json data;
    ifs >> data;

    for (size_t i = 0; i<data.size(); i++){


    int Value = data[i]["Value"];
        if  (data[i]["Type"]== "Single use"){
            Coupon* c = new SingleCoupon(Value, true);
            kuponok.push_back(c);
        }
    else if  (data[i]["Type"]=="Monthly"){
        int Year = data[i]["Year"];
        int Month = data[i]["Month"];
            char buffer[8];
            sprintf(buffer, "%04d-%02d", Year, Month);
        string date(buffer);
        Coupon* c = new MonthlyCoupon(Value, date);
        kuponok.push_back(c);
        }
    else if (data[i]["Type"] == "Multiple use"){
        int TotalUses = data[i]["TotalUses"];
        Coupon* c = new MultiCoupon(Value, TotalUses);
        kuponok.push_back(c);
        }
    }
}

void Wallet::countSingle(int &valid, int &invalid) const
{
     valid = 0;
        invalid = 0;
        for (auto* c : kuponok ){
            if (dynamic_cast<SingleCoupon*>(c)) {
                if (c->isValid()) ++valid;
                else ++invalid;
            }
        }

}

void Wallet::countMonthly(int &valid, int &invalid) const
{
     valid = 0;
        invalid = 0;
      for (auto* c: kuponok)  {
        if (dynamic_cast<MonthlyCoupon*>(c)) {
            if (c->isValid()) ++valid;
            else ++invalid;
        }
      }
}

void Wallet::countMulti(int &valid, int &invalid) const
{
          valid = 0;
        invalid = 0;
      for (auto* c: kuponok)  {
        if (dynamic_cast<MultiCoupon*>(c)) {
            if (c->isValid()) ++valid;
            else ++invalid;
        }
      }
}




void Wallet::exportCounts(const string & fn)
{
        int validSingle, invalidSingle;
        int validMonthly, invalidMonthly;
        int validMulti, invalidMulti;


         countSingle(validSingle, invalidSingle);
        countMonthly(validMonthly, invalidMonthly);
        countMulti(validMulti, invalidMulti);

        json j;
        j["Single"]["valid"] = validSingle;
        j["Single"]["invalid"] = invalidSingle;

        j["Monthly"]["valid"] = validMonthly;
        j["Monthly"]["invalid"] = invalidMonthly;

        j["Multi"]["valid"] = validMulti;
        j["Multi"]["invalid"] = invalidMulti;

    ofstream o(fn);
    if (!o.is_open()) {
    cerr << "Nem sikerült megnyitni: " << fn << endl;
    return;
}

    o<<setw(4)  << j << endl;
}

Wallet::Wallet() {}

Wallet::~Wallet()
{
    for (auto k: kuponok)
        delete k;
    kuponok.clear();
}

void Wallet::addCoupon(Coupon*  c)
{
    this->kuponok.push_back(c);
}

