#ifndef WARDROBE_H
#define WARDROBE_H

#include "product.h"

class Wardrobe : public Product
{
    int doorCount;
    bool hasMirror;
public:
    Wardrobe(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price, int doorCount, bool hasMirror);

    void print() const;
};

#endif // WARDROBE_H
