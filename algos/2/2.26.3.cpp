// 2.26.3. Írjon az előzőhöz hasonló programot gömbre vonatkozóan! 

// 2.26.3.


#include <iostream>
#include <iomanip>
#include <cmath>  // M_PI is available in C++

int main() {
    float radius;
    float* radius1 = &radius;
    float* radius2 = &radius;
    float* radius3 = &radius;
    float surface, volume;

    std::cout << "The radius of the ball is: ";
    std::cin >> radius;

    surface = 4.0f * M_PI * (*radius1) * (*radius2);  // Surface = 4πr²
    volume = (4.0f / 3.0f) * M_PI * (*radius1) * (*radius2) * (*radius3);  // Volume = 4/3πr³

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "The surface of the ball is: " << surface << std::endl;
    std::cout << "The volume of the ball is: " << volume << std::endl;

    return 0;
}
