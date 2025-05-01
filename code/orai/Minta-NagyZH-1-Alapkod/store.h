#ifndef STORE_H
#define STORE_H

#include "product.h"
#include <vector>

class Store
{
    vector<Product*> products;

    Product* findProductById(const string &id);
public:
    ~Store();
    void loadStock(const string &filename);
    void printProducts() const;
    void printStock() const;
};

#endif // STORE_H
