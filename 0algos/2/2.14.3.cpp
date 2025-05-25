// 2.14.3. Határozzuk meg a sin(x)-t hatványsor segítségével! 


// Íme a **2.14.3. feladat** teljesen helyes és **C++11-re portolt változata**, amely:

// * A `sin(x)` értékét számolja ki **hatványsor (Taylor-sor)** alapján,
// * A sor képlete:

//   $$
//   \sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n \cdot x^{2n+1}}{(2n+1)!}
//   $$
// * Rekurzív `factorial` helyett **iteratív, túlcsordulásbiztosabb verziót** használ,
// * Tisztán kezeli a lebegőpontos műveleteket (`double`),
// * Tizedes pontosságot használ kiíráskor,
// * Összehasonlítja az eredményt a `std::sin` könyvtári értékkel is.
 
#include <iostream>
#include <cmath>
#include <iomanip>

// Iteratív faktoriál
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    double x;
    int length;

    std::cout << "The accuracy of sinus series calculating sin(x)\n";
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "Length of the sinus series: ";
    std::cin >> length;

    double result = 0.0;

    for (int i = 0; i < length; ++i) {
        int exponent = 2 * i + 1;
        double term = std::pow(-1, i) * std::pow(x, exponent) / factorial(exponent);
        result += term;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "sin(" << x << ") with series length " << length << ": " << result << "\n";
    std::cout << "std::sin(" << x << "): " << std::sin(x) << "\n";
    std::cout << "Difference: " << std::fabs(result - std::sin(x)) << "\n";

    return 0;
}
