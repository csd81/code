// 3.9.3. Egy plusz változó jelezze, hogy melyik irányba történik a 
// csúsztatás! A tömb mérete legyen megadható! 
// 3.9.3.


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void print(const std::vector<float>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << "myArray[" << i << "] = " << a[i] << "  ";
    }
    std::cout << "\n";
}

void shift(std::vector<float>& a, char direction, bool cyclic) {
    int size = a.size();
    if (size == 0) return;

    float temp = (direction == 'r') ? a[size - 1] : a[0];

    if (direction == 'r') {
        for (int i = size - 1; i > 0; --i) {
            a[i] = a[i - 1];
        }
        a[0] = cyclic ? temp : 0.0f;
    } else if (direction == 'l') {
        for (int i = 0; i < size - 1; ++i) {
            a[i] = a[i + 1];
        }
        a[size - 1] = cyclic ? temp : 0.0f;
    } else {
        std::cerr << "Invalid direction. Use 'l' or 'r'.\n";
    }
}

int main() {
    int size;
    std::cout << "Array size? ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Size must be positive.\n";
        return 1;
    }

    std::vector<float> myArray(size);
    for (int i = 0; i < size; ++i) {
        std::cout << "Provide the next number: ";
        std::cin >> myArray[i];
    }

    std::cin.ignore(); // flush newline after number input

    std::cout << "Original array:\n";
    print(myArray);

    char direction;
    std::cout << "In which direction do you want to shift? (l/r): ";
    std::cin >> direction;

    // Ciklikus eltolás
    shift(myArray, direction, true);
    std::cout << "After cyclic shift:\n";
    print(myArray);

    // Nem ciklikus eltolás
    shift(myArray, direction, false);
    std::cout << "After non-cyclic shift:\n";
    print(myArray);

    return 0;
}
