#ifndef SINGLEPRODUCT_H
#define SINGLEPRODUCT_H

#include "product.h"

class SingleProduct : public Product {
    string code;
    int unitPrice;
public:
    SingleProduct(const string &code, int unitPrice);

    int getPrice() const override;
};

#endif // SINGLEPRODUCT_H
