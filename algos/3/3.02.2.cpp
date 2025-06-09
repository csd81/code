// 3.2.2. Továbbra is meg kell tippelni a megoldást, de az operandusokat 
// generálja véletlenszerűen -10 és 10 között! Véletlenszerűen döntse el 
// azt is, hogy egész vagy lebegőpontos osztást végez! Utóbbinál függvényt 
// kell használni a maradékképzésre. Lebegőpontos osztásnál mindig írja ki 
// a tizedes pontot az operandusoknál! 
// 3.2.2.

 #include <iostream>
#include <random>
#include <iomanip>

int main() {
    // Random engine és eloszlások
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-10, 10);
    std::uniform_int_distribution<> typeDist(0, 1); // 0 = int, 1 = float

    int A = dist(gen);
    int B;
    do {
        B = dist(gen); // biztosan ne legyen 0
    } while (B == 0);

    int type = typeDist(gen);

    if (type == 0) {
        // Egész osztás
        std::cout << "Integer division:\n";
        std::cout << A << " / " << B << " = " << (A / B) << "\n";
    } else {
        // Lebegőpontos osztás
        double result = static_cast<double>(A) / static_cast<double>(B);
        std::cout << "Floating point division:\n";
        std::cout << std::fixed << std::setprecision(4);
        std::cout << static_cast<double>(A) << " / " << static_cast<double>(B)
                  << " = " << result << "\n";
    }

    return 0;
}
