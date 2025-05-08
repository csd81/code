#ifndef CHAIR_H
#define CHAIR_H

#include "product.h"

class Chair : public Product
{
    std::string style;
public:
    Chair(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price, const std::string &style);

    void print() const override;
};

#endif // CHAIR_H

