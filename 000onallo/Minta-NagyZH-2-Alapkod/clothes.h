#ifndef CLOTHES_H
#define CLOTHES_H

#include "babyproduct.h"

class Clothes : public BabyProduct
{
    string size;
public:
    Clothes(const string &id, const string &name, int price, int quantity, const string &size);

    void print(ostream& os) const {
        BabyProduct::print(os);

        os << size;
    }

    string getSize() const;
};

#endif // CLOTHES_H
