// 3.7.2. Határozza meg a legnagyobb szintkülönbséget a teljes területen, 
// csak a szárazföldön, csak a tengerben! 
// 3.7.2.


#include <iostream>
#include <array>
#include <iomanip>
#include <limits>

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

    float highestLand = std::numeric_limits<float>::lowest();
    float lowestLand = std::numeric_limits<float>::max();
    float shallowestWater = std::numeric_limits<float>::lowest();
    float deepestWater = std::numeric_limits<float>::max();

    bool hasLand = false, hasWater = false;

    // Végigmegyünk a mátrixon és frissítjük a min/max értékeket
    for (int i = 0; i < xSize; ++i) {
        for (int j = 0; j < ySize; ++j) {
            float val = matrix[i][j];
            if (val > 0) {
                hasLand = true;
                if (val > highestLand) highestLand = val;
                if (val < lowestLand)  lowestLand = val;
            } else {
                hasWater = true;
                if (val > shallowestWater) shallowestWater = val;
                if (val < deepestWater)    deepestWater = val;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(4);

    if (hasLand)
        std::cout << "The level difference on land is: "
                  << (highestLand - lowestLand) << "\n";
    else
        std::cout << "There is no land.\n";

    if (hasWater)
        std::cout << "The level difference in water is: "
                  << (shallowestWater - deepestWater) << "\n";
    else
        std::cout << "There is no water.\n";

    if (hasLand && hasWater)
        std::cout << "The biggest global level difference is: "
                  << (highestLand - deepestWater) << "\n";
    else
        std::cout << "No global level difference can be computed.\n";

    return 0;
}

 