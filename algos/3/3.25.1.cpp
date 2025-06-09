// 3.25. Riemann integrál
// 3.25.1. Írjon programot, amely négy függvény Riemann-integrálját 
// számítja ki 0 és 1 között! Elsőként az [a, b] intervallumot felosztjuk N 
// db (1000000) részre, azaz egy kis intervallum hossza: h = (b - a)/N. N 
// téglalapot képzünk úgy, hogy egyik téglalap se lógjon a függvény 
// fölé. Az i-dik téglalap alapja tehát h magassága pedig f(h*i) és f(h*(i + 
// 1)) közül a kisebbik. Az integrál a téglalapok összege. A számolandó 
// függvények: f1(x) = f2(x) = x2 f3(x) = sin(x) f4(x) = tan(x) Ábra: Riemann 
// integrál szemléltetése Példa bemenet: The Riemann integral of f1(x) over x 
// from 0 to 1: 3.14159 The Riemann integral of f2(x) over x from 0 to 1: 0.333332 
// The Riemann integral of sin(x) over x from 0 to 1: 0.459696 The Riemann 
// integral of tan(x) over x from 0 to 1: 0.615624 
// 3.25.1.


#include <iostream>
#include <cmath>
#include <string>

#define DEFAULT_A 0
#define DEFAULT_B 1
#define DEFAULT_NUM 1000000

inline double my_min(double a, double b) {
    return (a < b) ? a : b;
}

// Függvények
double f1(double x) {
    return std::sqrt((2.0 - x) * x) * 4.0;
}

double f2(double x) {
    return x * x;
}

// Integrál kiszámítása
void Integral(int a, int b, int num, double (*fptr)(double), const std::string& name) {
    double res = 0.0;
    double h = static_cast<double>(b - a) / num;
    for (int i = 0; i < num; ++i) {
        double x1 = a + i * h;
        double x2 = a + (i + 1) * h;
        double height = my_min(fptr(x1), fptr(x2));
        res += height * h;
    }
    std::cout << "The Riemann integral of " << name
              << " over x from " << a << " to " << b << ": "
              << res << "\n";
}

int main(int argc, char* argv[]) {
    int a = (argc > 1) ? std::atoi(argv[1]) : DEFAULT_A;
    int b = (argc > 2) ? std::atoi(argv[2]) : DEFAULT_B;
    int num = (argc > 3) ? std::atoi(argv[3]) : DEFAULT_NUM;

    std::cout << std::endl;
    Integral(a, b, num, f1, "f1(x)");
    Integral(a, b, num, f2, "f2(x)");
    Integral(a, b, num, std::sin, "sin(x)");
    Integral(a, b, num, std::tan, "tan(x)");
    std::cout << std::endl;

    return 0;
}

