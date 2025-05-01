#ifndef TABLE_H
#define TABLE_H

#include "product.h"

class Table : public Product
{
    int legCount;
    bool legsAdjustable;
public:
    Table(const string &id, const string &woodType,
          double weight, const Dimensions &dimensions, int price,
          int legCount, bool legsAdjustable);
    int getLegCount() const;
    bool getLegsAdjustable() const;
    void printData() const override;
};

#endif // TABLE_H
