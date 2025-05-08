#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
protected:
    std::string id;
    std::string woodType;
    double weight;
    int width;
    int height;
    int length;
    int price;

public:
    Product(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price);
    virtual ~Product() = default;
    virtual void print() const =0;
    std::string getId() const;
    int getPrice() const;
    std::string getWoodType() const;
    double getWeight() const;
    int getWidth() const;
    int getHeight() const;
    int getLength() const;
};

#endif // PRODUCT_H

