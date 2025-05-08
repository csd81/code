#ifndef MULTIPRODUCT_H
#define MULTIPRODUCT_H

#include "product.h"

class MultiProduct : public Product
{
    string code;
    int unitPrice;
    int quantity;
public:
    MultiProduct();
    MultiProduct(const string &code, int unitPrice, int quantity);
    int getPrice() const override;
};

#endif // MULTIPRODUCT_H
