#include "image.h"
#include <fstream>
#include <iostream>
using namespace std;

Image::Image(int width, int height):
    width(width),
    height(height)
{
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

void Image::print() const
{
    cout << width << " " << height << endl;
    for (int y=0;y<height;y++)
    {
        for (int x=0;x<width;x++)
        {
            bool p = pixel(x,y);
            cout << (p ? '.' : '#') << flush;
        }
        cout << endl;
    }
}

// PART5: write to file using the same '.' / '#' and newline format
    void Image::saveToFile(const std::string& filename) const {
        std::ofstream ofs(filename);
        if (!ofs) return; // silently fail if cannot open
        for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                        ofs << (pixel(x, y) ? '.' : '#');
                    }
                ofs << '\n';
            }
    }
