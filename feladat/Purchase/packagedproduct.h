#ifndef PACKAGEDPRODUCT_H
#define PACKAGEDPRODUCT_H

#include "product.h"

class PackagedProduct : public Product
{
    string code;
    int unitPrice;
    int packageCount;
    static int packageSize;

public:

    PackagedProduct(const string &code, int unitPrice, int packageCount);
    static void setPackageSize(int newPackageSize);
    int getPrice() const override;
};

#endif // PACKAGEDPRODUCT_H
