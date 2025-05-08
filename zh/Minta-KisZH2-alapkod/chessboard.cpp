#include "chessboard.h"

Chessboard::Chessboard()
    : Image(8, 8)
{}

bool Chessboard::pixel(int x, int y) const {
    // light if x+y is even
    return ((x + y) % 2) == 0;
}
