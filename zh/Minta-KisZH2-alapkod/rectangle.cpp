#include "rectangle.h"

Rectangle::Rectangle(int width, int height, int x1, int y1, int x2, int y2)
    : Image(width, height), x1_(x1), y1_(y1), x2_(x2), y2_(y2)
{}

bool Rectangle::pixel(int x, int y) const {
    // light inside the rectangle (inclusive)
    return x >= x1_ && x <= x2_
           && y >= y1_ && y <= y2_;
}
