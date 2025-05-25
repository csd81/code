// 2.38.2. Módosítsa úgy a programot, hogy az első sorba írja ki az adatok 
// számát! Szóközökkel válassza el az egyes értékeket és minden számot 
// fix hosszan írjon ki! 100 számonként szúrjon be egy üres sort! 
// 2.38.2.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream tf;
    int min, max, num;
    std::string fileName;

    std::cout << "This program will save a certain amount of random numbers into a file.\n";

    std::cout << "File name: ";
    std::cin >> fileName;

    std::cout << "Min number: ";
    std::cin >> min;

    std::cout << "Max number: ";
    std::cin >> max;

    std::cout << "Number of data: ";
    std::cin >> num;

    tf.open(fileName);
    if (!tf) {
        std::cerr << "File open to write has failed!\n";
        return 1;
    }

    // seed the random generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // write the number of values in the first line
    tf << num << '\n';

    const int width = 6;
    int count = 0;

    for (int i = 0; i < num; ++i) {
        int data = std::rand() % (max + 1 - min) + min;
        tf << std::setw(width) << data << ' ';
        ++count;

        if (count == 100) {
            tf << '\n';
            count = 0;
        }
    }

    tf.close();
    std::cout << "File written successfully.\n";

    return 0;
}
