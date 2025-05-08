#ifndef STARS_H
#define STARS_H

#include "image.h"
#include <vector>
#include <utility>

class Stars : public Image {
    std::vector<std::pair<int,int>> stars_;
public:
    Stars(int width, int height);
    void addStar(int x, int y);
    bool pixel(int x, int y) const override;
};

#endif // STARS_H
