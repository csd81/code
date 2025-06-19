#ifndef CHAIR_H
#define CHAIR_H

#include "babyproduct.h"

class Chair : public BabyProduct
{
    bool adjustable;
public:
    Chair(const string &id, const string &name, int price, int quantity, bool adjustable);

    void print(ostream& os) const {
        BabyProduct::print(os);

        os << " " << (adjustable ? "állítható" : "nem állítható");
    }
        bool getAdjustable() const;
};

#endif // CHAIR_H
