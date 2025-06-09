// 2.17.2. Alakítsa át a programot, hogy ne Celsius fokot, hanem Farenheit-t 
// kér be. Külön függvény végezze el a konvertálást! 
// 2.17.2.

#include <iostream>
#include <iomanip>

// Függvény: Fahrenheit → Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}

int main() {
    float fahrenheit;
    std::cout << "Temperature of water (in Fahrenheit): ";
    std::cin >> fahrenheit;

    float celsius = fahrenheitToCelsius(fahrenheit);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Converted to Celsius: " << celsius << " °C\n";

    if (celsius < 0.0f) {
        std::cout << "The water is solid now.\n";
    } else if (celsius > 100.0f) {
        std::cout << "The water is gaseous now.\n";
    } else {
        std::cout << "The water is liquid now.\n";
    }

    return 0;
}
