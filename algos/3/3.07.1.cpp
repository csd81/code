// 3.7.1. Feladat: Írjon programot, amelyben egy 10*10-es statikus, 
// inicializált, float értékeket tartalmazó mátrix tengerszint feletti 
// magasság adatokat reprezentál! Adja meg a szárazföld és a tenger 
// arányát, ha a negatív magasság tengerfeneket reprezentál! Adja meg a 
// legmagasabb pontot és adja meg a legmagasabb pontot a tengerben feltételes 
// maximum keresés segítségével! Azt az esetet is kezelni kell, amikor nincs 
// tenger! Számolja ki a terület átlagos magasságát! 
 
#include <iostream>
#include <array>
#include <iomanip>
#include <cfloat> // FLT_MAX

int main() {
    const int xSize = 10, ySize = 10;
    std::array<std::array<float, ySize>, xSize> matrix = {{
        {4, 5, 6, 4, 2, 3, 4, 2, 4, 2},
        {2, 2, 6, 5, 8, 7, 5, 3, 4, 2},
        {4, 3, 6, 2, 6, 3, 4, 6, 7, 2},
        {7, 2, 6, -2, -3, -3, -4, 6, 1, 2},
        {4, 1, 6, -7, -2, -3, -2, -8, 4, 2},
        {8, 1, 6, -7, -4, -3, -7, -6, -4, -2},
        {4, 3, 6, 7, 3, -3, -4, -8, -2, -2},
        {9, 2, 6, 6, 2, 2, -4, -8, -4, 2},
        {4, 3, 6, 8, 3, 2, 4, -6, 4, 2},
        {3, 3, 6, 7, 1, 3, 5, 6, 4, 2}
    }};

    int water = 0, land = 0;
    float sum = 0.0f;

    // Szárazföld / tenger arány és összeg
    for (int i = 0; i < xSize; ++i) {
        for (int j = 0; j < ySize; ++j) {
            float val = matrix[i][j];
            if (val < 0)
                ++water;
            else
                ++land;
            sum += val;
        }
    }

    std::cout << "The ratio of land to water is: " << land << ":" << water << "\n";

    // Legmagasabb pont
    int maxX = 0, maxY = 0;
    for (int i = 0; i < xSize; ++i) {
        for (int j = 0; j < ySize; ++j) {
            if (matrix[i][j] > matrix[maxX][maxY]) {
                maxX = i;
                maxY = j;
            }
        }
    }

    std::cout << "The highest point is at row: " << maxX
              << ", column: " << maxY
              << " and its height is: " << matrix[maxX][maxY] << "\n";

    // Legsekélyebb vízpont
    float shallowMax = -FLT_MAX;
    int waterX = -1, waterY = -1;
    for (int i = 0; i < xSize; ++i) {
        for (int j = 0; j < ySize; ++j) {
            float val = matrix[i][j];
            if (val < 0 && val > shallowMax) {
                shallowMax = val;
                waterX = i;
                waterY = j;
            }
        }
    }

    if (waterX == -1) {
        std::cout << "There is no water so the search is meaningless.\n";
    } else {
        std::cout << "The most shallow water is at row: " << waterX
                  << ", column: " << waterY
                  << " and its depth is: " << shallowMax << "\n";
    }

    // Átlagos magasság
    float avg = sum / (xSize * ySize);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "The average height is: " << avg << "\n";

    return 0;
}

