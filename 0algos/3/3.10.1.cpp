// 3.10. Műveletek tömbökön
//3.10.1. Írjon függvényeket a következő feladatokra: határozza meg egy 
// tömbben lévő elemek összegét, átlagát, minimumát, hogy egy adott elem 
// szerepel-e benne! Egy fájlban legyen a main függvény és egy másikban a 
// többi függvény! 



// inc.hpp

 
#ifndef INC_HPP_
#define INC_HPP_

// Print the array elements in [a0, a1, …, aN-1] format
void print(const double* arr, int size);

// Return the sum of all elements
double sum(const double* arr, int size);

// Return the average of all elements (assumes size > 0)
double avg(const double* arr, int size);

// Return the index of the minimum element (assumes size > 0)
int minIndex(const double* arr, int size);

// Return true if value is found in the array
bool searchFor(const double* arr, int size, double value);

#endif // INC_HPP_
 
//functions.cpp


// #include "inc.hpp"
#include <iostream>

// Print the array as [e0, e1, …, eN-1]
void print(const double* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i + 1 < size) 
            std::cout << ", ";
    }
    std::cout << "]";
}

double sum(const double* arr, int size) {
    double s = 0.0;
    for (int i = 0; i < size; ++i) {
        s += arr[i];
    }
    return s;
}

double avg(const double* arr, int size) {
    return sum(arr, size) / size;
}

int minIndex(const double* arr, int size) {
    int mi = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[mi]) {
            mi = i;
        }
    }
    return mi;
}

bool searchFor(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

// main.cpp
 

// #include "inc.hpp"
#include <iostream>

int main() {
    // sample data
    double myArray[] = { 12.0, 56.0, -7.0 };
    int size = sizeof(myArray) / sizeof(myArray[0]);
    double what = -8.0;

    std::cout << "Array: ";
    print(myArray, size);

    double s = sum(myArray, size);
    double a = avg(myArray, size);
    std::cout << "\nSum: " << s
              << ", Average: " << a << "\n";

    int idx = minIndex(myArray, size);
    std::cout << "Minimum at index " << idx
              << " → value " << myArray[idx] << "\n";

    if (searchFor(myArray, size, what)) {
        std::cout << what << " is found.\n";
    } else {
        std::cout << what << " is not found.\n";
    }

    return 0;
}
 