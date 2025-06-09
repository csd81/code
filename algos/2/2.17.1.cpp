// 2.17.1. Írjon programot, amely a víz hőmérséklete alapján megállapítja 
// annak halmazállapotát! 

#include <iostream>
#include <iomanip>

int main() {
    float temperature;

    std::cout << "Temperature of water (°C): ";
    std::cin >> temperature;

    if (temperature < 0.0f) {
        std::cout << "Solid water (ice)\n";
    } else if (temperature < 100.0f) {
        std::cout << "Liquid water\n";
    } else {
        std::cout << "Gaseous water (steam)\n";
    }

    return 0;
}
