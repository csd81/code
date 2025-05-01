#ifndef WARDROBE_H
#define WARDROBE_H

#include "product.h"

class Wardrobe : public Product
{
    int doorCount;
    bool hasMirror;
public:
    Wardrobe(const string &id, const string &woodType,
             double weight, const Dimensions &dimensions, int price,
             int doorCount, bool hasMirror);
    int getDoorCount() const;
    bool getHasMirror() const;
    void printData() const override;
};

#endif // WARDROBE_H
