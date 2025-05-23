// 3.3.2. A kezdeti sztringben 3 double típusú szám legyen, az elsőt eggyel, a 
// másodikat kettővel, a harmadikat hárommal növeljük meg! A megnövelt 
// értékeket egy új tömbbe írjuk ki normál alakban, 8 tizedes pontossággal 
// és előjellel! 

// 3.3.2.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

int main() {
    std::string input = "48.1658745 -654686835454.321635432435421 9.8765432e-11";
    std::istringstream iss(input);

    std::vector<double> numbers(3);
    for (int i = 0; i < 3; ++i) {
        iss >> numbers[i];
        numbers[i] += (i + 1);
    }

    std::ostringstream oss;
    oss << std::showpos << std::fixed << std::setprecision(8);
    for (const auto& num : numbers) {
        oss << num << " ";
    }

    std::string output = oss.str();
    std::cout << "The new string is: " << output << '\n';

    return 0;
}

