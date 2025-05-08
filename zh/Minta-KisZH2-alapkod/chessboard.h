#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "image.h"

class Chessboard : public Image {
public:
    Chessboard();
    virtual bool pixel(int x, int y) const override;
};

#endif // CHESSBOARD_H
