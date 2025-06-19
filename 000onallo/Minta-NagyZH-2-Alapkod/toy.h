#ifndef TOY_H
#define TOY_H

#include "babyproduct.h"

class Toy : public BabyProduct
{
    int year;
public:
    Toy(const string &id, const string &name, int price, int quantity, int year);

    void print(ostream& os) const {
        BabyProduct::print(os);

        os << " " << year;
    }

    int getYear() const;
};

#endif // TOY_H
