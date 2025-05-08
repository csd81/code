#ifndef INVERSE_H
#define INVERSE_H

#include "image.h"

class Inverse : public Image {
    Image* orig_;
public:
    Inverse(Image* orig);
    virtual bool pixel(int x, int y) const override;
};

#endif // INVERSE_H
