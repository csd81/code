#ifndef EXAMPLE_H
#define EXAMPLE_H

// Csak pelda, az example.h/cpp fajlok nem modositandok!

#include "image.h"

class Example1 : public Image
{
public:
    Example1();
    bool pixel (int x, int y) const;
};

class Example2 : public Image
{
public:
    Example2();
    bool pixel (int x, int y) const;
};

#endif // EXAMPLE_H
