#ifndef BABYPRODUCT_H
#define BABYPRODUCT_H
#include <iostream>
#include <vector>
using namespace std;

class BabyProduct
{
    string id;
    string name;
    int price;
    int quantity;
public:
    BabyProduct(const string &id, const string &name, int price, int quantity);

    virtual ~BabyProduct();

    virtual void print(ostream& os) const {
        os <<  id<< " " << name<<  " " <<price<< " " << quantity << " ";
    }
    friend ostream& operator<<(ostream&, const BabyProduct&);
    int getPrice() const;
    string getId() const;
    int getQuantity() const;
    void setQuantity(int newQuantity);
    string getName() const;
};

#endif // BABYPRODUCT_H
