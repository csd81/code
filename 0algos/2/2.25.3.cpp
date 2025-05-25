// 2.25.3. Módosítsa úgy az előző programot, hogy nem használ statikus 
// változót, hanem paraméterként adja át az eddigi részösszeget! 
// 2.25.3.



#include <iostream>

int sum(int data, int subTotal) {
    subTotal += data;
    return subTotal;
}

int main() {
    int num, total, subTotal = 0;
    char more = 'y';

    do {
        std::cout << "Provide the next number: ";
        std::cin >> num;

        subTotal = sum(num, subTotal);

        std::cout << "Are there more numbers? (y/n): ";
        std::cin >> more;
        std::cin.ignore(10000, '\n'); // clear input buffer

    } while (more == 'y' || more == 'Y');

    total = subTotal;

    std::cout << "The total is " << total << ".\n";

    return 0;
}
