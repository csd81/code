// 2.14.2. Kérjünk be egy pontosságot és határozzuk meg, hogy a sor hány 
// tagját kell figyelembe venni, az adott pontosság eléréséhez! 

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double value;
    double accuracy;

    std::cout << "The accuracy of power series calculating e^x\n";
    std::cout << "x = ";
    std::cin >> value;

    std::cout << "How small should the accuracy (difference) be? ";
    std::cin >> accuracy;

    double result = 1.0;
    double factorial = 1.0;
    int length = 1;

    double accurateResult = std::exp(value);
    double difference = std::fabs(accurateResult - result);

    while (difference > accuracy) {
        factorial *= length;
        result += std::pow(value, length) / factorial;
        ++length;
        difference = std::fabs(accurateResult - result);
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Power series value:  " << result << "\n";
    std::cout << "Actual exp(x):       " << accurateResult << "\n";
    std::cout << "Final difference:    " << difference << "\n";
    std::cout << "Terms needed:        " << length << "\n";

    return 0;
}
