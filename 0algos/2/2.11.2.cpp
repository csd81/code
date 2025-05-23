


2.11.2. Határozza meg a komplex gyököket is! A komplex gyököket is figyelembe véve a másodfokú egyenletnek mindig két megoldása van, de azok egybeeshetnek. 

2.11.2.
#include <stdio.h>
#include <math.h> int main() { float a, b, c, D, x1, x2;
} printf("The next equation is to be solved:\n");
printf("a*x^2+b*x+c=0\n");
printf("a= ");
scanf("%f", &a);
printf("b= ");
scanf("%f", &b);
printf("c= ");
scanf("%f", &c);
D = b*b - 4*a*c;
if (D > 0) { printf("There are 2 solutions!\n");
x1 = (-b + sqrt(D)) /(2*a);
x2 = (-b - sqrt(D)) /(2*a);
printf("x1= %f\n", x1);
printf("x2= %f\n", x2);
} else if (D == 0) { printf("There is 1 solution!\n");
x1 = -b /(2*a);
printf("x1= %f\n", x1);
} else { printf("There are 2 solutions! (complex)\n");
printf("x1= %f+(%f)i\n", (-b) /(2*a), sqrt(-D));
printf("x2= %f-(%f)i\n", (-b) /(2*a), sqrt(-D));
} return 0;

Here’s a C++11 version that always computes and prints two roots—including complex ones—for

$$
a x^2 + b x + c = 0
$$

even when they coincide. It uses `<complex>` so you don’t have to branch on the sign of the discriminant yourself:

```cpp
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
```

### Key points

* **`<complex>`**
  We wrap the real discriminant in a `std::complex<double>` so that `std::sqrt` will automatically give a complex result when $D<0$.
* **Unified formula**

  $$
    x_{1,2} \;=\;\frac{-b \pm \sqrt{D}}{2a}
  $$

  works whether $\sqrt{D}$ is real or imaginary.
* **Formatting**
  We use `fixed` with `setprecision(4)` for all numeric output, and a small lambda to print the “+” or “–” between real and imaginary parts.



