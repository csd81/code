// 2.21.2. Módosítsa úgy a programot, hogy az három szám legnagyobb közös 
// osztóját számolja ki! 
// 2.21.2.


#include <iostream>

int biggest_denominator(int x, int y) {
    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

int main() {
    int x, y, z;

    std::cout << "Give me the first number: ";
    std::cin >> x;

    std::cout << "Give me the second number: ";
    std::cin >> y;

    std::cout << "Give me the third number: ";
    std::cin >> z;

    // GCD(x, y, z) = GCD(GCD(x, y), z)
    int gcd_xy = biggest_denominator(x, y);
    int gcd_xyz = biggest_denominator(gcd_xy, z);

    std::cout << "The greatest common divisor: " << gcd_xyz << std::endl;

    return 0;
}
