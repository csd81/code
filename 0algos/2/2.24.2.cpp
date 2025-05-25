
// 2.24.2. A sin(x) függvénynek határozza meg az 1., 2. vagy 3. deriváltjának 
// az értékét egy adott pontban! Használja fel, hogy sin'(x) = cos(x), cos'(x) 
// = -sin(x). 
// 2.24.2.


// Itt a **2.24.2. feladat** modern és helyes **C++11-re portolt változata**, amely:

// ---

// ### ✅ Feladat:

// * A `sin(x)` függvény **n-edik deriváltját** számolja ki egy adott pontban.
// * A deriválások ciklikusan ismétlődnek:

//   $$
//   \begin{align*}
//   f^{(0)}(x) &= \sin(x) \\
//   f^{(1)}(x) &= \cos(x) \\
//   f^{(2)}(x) &= -\sin(x) \\
//   f^{(3)}(x) &= -\cos(x) \\
//   f^{(4)}(x) &= \sin(x) \quad\text{(és így tovább)}
//   \end{align*}
//   $$

// ---

// ### ✅ C++11 megoldás:

// ```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

float deriv(int whichDerivate, float posX) {
    switch (whichDerivate % 4) {
        case 0: return std::sin(posX);
        case 1: return std::cos(posX);
        case 2: return -std::sin(posX);
        case 3: return -std::cos(posX);
        default: return 0; // Ez sosem történik meg
    }
}

int main() {
    float posX;
    int times;

    std::cout << "Where do you want to calculate the derivative of sin(x) (in radians): ";
    std::cin >> posX;

    std::cout << "How many derivatives do you want? ";
    std::cin >> times;

    std::cout << std::fixed << std::setprecision(6);

    for (int i = 1; i <= times; ++i) {
        float result = deriv(i, posX);
        std::cout << "The " << i << ". derivative of sin(x) at x = "
                  << posX << " is: " << result << std::endl;
    }

    return 0;
}
