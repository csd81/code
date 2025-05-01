#ifndef CHAIR_H
#define CHAIR_H

#include "product.h"

class Chair : public Product
{
    string style;
public:
    Chair(const string &id, const string &woodType,
          double weight, const Dimensions &dimensions, int price,
          const string &style);
    string getStyle() const;
    void printData() const override;
};

#endif // CHAIR_H
