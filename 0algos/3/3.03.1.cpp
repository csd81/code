// 3.3. Sztring konvertálás

// 3.3.1. Készítsen programot, amely statikus karaktertömbben lévő 4 számot 
// átkonvertál short int, int, float és double típusra! A számok összegét 
// írja be az eredeti tömbbe! 
// 3.3.1.

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

int main() {
    std::string input = "23 35678 1.2345e11 -9.8765432e-11";

    short shortIntValue;
    int intValue;
    float floatValue;
    double doubleValue;

    std::istringstream iss(input);
    iss >> shortIntValue >> intValue >> floatValue >> doubleValue;

    double sum = shortIntValue + intValue + floatValue + doubleValue;

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6) << sum;
    input = oss.str(); // visszaírjuk az összeg szövegét az input stringbe

    std::cout << "The sum is " << input << std::endl;

    return 0;
}
