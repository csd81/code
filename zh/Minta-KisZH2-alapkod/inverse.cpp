#include "inverse.h"

Inverse::Inverse(Image* orig)
    : Image(orig->getWidth(), orig->getHeight()), orig_(orig)
{}

bool Inverse::pixel(int x, int y) const {
    // opposite of the original pixel
    return !orig_->pixel(x, y);
}
