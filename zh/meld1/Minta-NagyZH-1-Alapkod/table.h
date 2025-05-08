#ifndef TABLE_H
#define TABLE_H

#include "product.h"

class Table : public Product
{
    int legCount;
    bool legsAdjustable;

public:
    Table(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price, int legCount, bool legsAdjustable);

    void print() const override;
};

#endif // TABLE_H

