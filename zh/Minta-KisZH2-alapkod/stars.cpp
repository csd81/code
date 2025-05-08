#include "stars.h"

Stars::Stars(int width, int height)
    : Image(width, height)
{}

void Stars::addStar(int x, int y) {
    stars_.emplace_back(x, y);
}

bool Stars::pixel(int x, int y) const {
    // light if any star was placed here
    for (auto &p : stars_) {
        if (p.first == x && p.second == y)
            return true;
    }
    return false;
}
