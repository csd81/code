#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

struct Dimensions
{
    int width;
    int height;
    int length;
};

class Product
{
    string id;
    string woodType;
    double weight;
    Dimensions dimensions;
    int price;

    int stockAmount = 0;
public:
    virtual ~Product() = default;

    Product(const string &id, const string &woodType,
            double weight, const Dimensions &dimensions, int price);
    string getId() const;
    string getWoodType() const;
    double getWeight() const;
    Dimensions getDimensions() const;
    int getPrice() const;

    int getStockAmount() const;
    void setStockAmount(int newStockAmount);

    virtual void printData() const = 0;
};

#endif // PRODUCT_H
