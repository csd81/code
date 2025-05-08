#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "image.h"

class Rectangle : public Image {
    int x1_, y1_, x2_, y2_;
public:
    Rectangle(int width, int height, int x1, int y1, int x2, int y2);
    virtual bool pixel(int x, int y) const override;
};

#endif // RECTANGLE_H
