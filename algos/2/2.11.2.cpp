// 2.11.2. Határozza meg a komplex gyököket is! A komplex gyököket is 
// figyelembe véve a másodfokú egyenletnek mindig két megoldása van, de azok 
// egybeeshetnek. 
// 2.11.2.

 
#include <iostream>
#include <complex>
#include <iomanip>

int main() {
    double a, b, c;
    std::cout << "Solve a*x^2 + b*x + c = 0 (complex roots allowed)\n\n";
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "c = "; std::cin >> c;

    // Ensure it's really quadratic
    if (a == 0.0) {
        std::cerr << "Coefficient a must be non-zero for a quadratic equation.\n";
        return 1;
    }

    // Compute discriminant as a complex number
    std::complex<double> D = std::complex<double>(b*b - 4.0*a*c, 0.0);
    auto sqrtD = std::sqrt(D);

    // Two roots
    std::complex<double> x1 = (-b + sqrtD) / (2.0 * a);
    std::complex<double> x2 = (-b - sqrtD) / (2.0 * a);

    // Print with 4 decimal places
    auto print_root = [&](const std::complex<double>& x, const char* name) {
        double re = x.real();
        double im = x.imag();
        std::cout << name << " = "
                  << std::fixed << std::setprecision(4)
                  << re;
        if (im >= 0)
            std::cout << "+" << im << "i\n";
        else
            std::cout << im << "i\n";
    };

    std::cout << "\nThe two solutions are:\n";
    print_root(x1, "x1");
    print_root(x2, "x2");

    return 0;
}
 