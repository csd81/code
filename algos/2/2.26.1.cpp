// 2.26. Alias változók
// 2.26.1. Írjon programot, amelyben egy kocka felületét és térfogatát 
// számolja ki! Úgy írja fel a képletet, hogy két ugyanolyan nevű változó 
// ne szerepeljen benne, hanem használjon alias változókat mutatók 
// segítségével. 
// 2.26.1.


#include <iostream>

int main() {
    int side;
    int *side1 = &side, *side2 = &side, *side3 = &side;
    int surface, volume;

    std::cout << "The side of the cube is: ";
    std::cin >> side;

    surface = 6 * (*side1) * (*side2);  // 6 * a * a
    volume = (*side1) * (*side2) * (*side3);  // a * a * a

    std::cout << "The volume of the cube is: " << volume << std::endl;
    std::cout << "The surface of the cube is: " << surface << std::endl;

    return 0;
}
