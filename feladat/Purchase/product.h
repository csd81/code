#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
class Product
{
public:
    virtual int getPrice() const = 0;
    virtual ~Product() {}
};

#endif // PRODUCT_H
