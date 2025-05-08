#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>
using namespace std;

class Image
{
protected:
    int width, height;
public:
    Image(int width, int height);
    virtual ~Image()=default;

    int getWidth() const;
    int getHeight() const;

    // visszaadja, hogy az y-edik sor x-edik oszlopaban
    // levo pixel vilagos (true) vagy sotet (false) a kepen
    virtual bool pixel (int x, int y) const=0;

    void print () const;
        // PART5: save image to a text file in the same format as print()
            void saveToFile(const std::string& filename) const;
};

#endif // IMAGE_H
