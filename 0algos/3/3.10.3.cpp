//3.10.3. Egészítse ki az előző programot a következő feladatokat 
ellátó függvényekkel! Adott elem első előfordulásának meghatározása, 
utolsó előfordulásának meghatározása, két tömb között az 
alapműveletek elvégzése az azonos indexű elemek között, skaláris szorzat 
meghatározása.  

Below is a clean C++11 solution, organized into three files:

---

**function.hpp**

```cpp
#ifndef FUNCTION_HPP
#define FUNCTION_HPP

// Print array elements as [e0, e1, …, eN-1]
void print(const double* arr, int size);

// Sum of elements
double sum(const double* arr, int size);

// Average of elements (size > 0)
double avg(const double* arr, int size);

// Index of minimum element (size > 0)
int minIndex(const double* arr, int size);

// Index of maximum element (size > 0)
int maxIndex(const double* arr, int size);

// Swap the contents of a1 and a2 (both length size)
void change(double* a1, double* a2, int size);

// Element-wise basic operations (+, –, *, /) between a1 and a2, printed to 
stdout
void elementWiseOps(const double* a1, const double* a2, int size);

// Scalar (dot) product of a1 and a2
double dotProduct(const double* a1, const double* a2, int size);

// First occurrence of value in arr, or –1 if not found
int firstOccurrence(const double* arr, int size, double value);

// Last occurrence of value in arr, or –1 if not found
int lastOccurrence(const double* arr, int size, double value);

// Returns true if value is found in arr
bool searchFor(const double* arr, int size, double value);

#endif // FUNCTION_HPP
```

---

**functions.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <cmath>

// Print array as [e0, e1, …]
void print(const double* arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i + 1 < size) std::cout << ", ";
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
        if (arr[i] < arr[mi]) mi = i;
    }
    return mi;
}

int maxIndex(const double* arr, int size) {
    int ma = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[ma]) ma = i;
    }
    return ma;
}

void change(double* a1, double* a2, int size) {
    for (int i = 0; i < size; ++i) {
        double tmp = a1[i];
        a1[i] = a2[i];
        a2[i] = tmp;
    }
}

void elementWiseOps(const double* a1, const double* a2, int size) {
    std::cout << "\nElement-wise operations:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Index " << i << ":\n";
        std::cout << "  " << a1[i] << " + " << a2[i]
                  << " = " << (a1[i] + a2[i]) << "\n";
        std::cout << "  " << a1[i] << " - " << a2[i]
                  << " = " << (a1[i] - a2[i]) << "\n";
        std::cout << "  " << a1[i] << " * " << a2[i]
                  << " = " << (a1[i] * a2[i]) << "\n";
        std::cout << "  " << a1[i] << " / " << a2[i]
                  << " = " << (a1[i] / a2[i]) << "\n";
    }
}

double dotProduct(const double* a1, const double* a2, int size) {
    double dot = 0.0;
    for (int i = 0; i < size; ++i) {
        dot += a1[i] * a2[i];
    }
    return dot;
}

int firstOccurrence(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

int lastOccurrence(const double* arr, int size, double value) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

bool searchFor(const double* arr, int size, double value) {
    return firstOccurrence(arr, size, value) != -1;
}
```

---

**main.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <iomanip>

int main() {
    double A[]     = { 12.0, 56.0, -7.0, 56.0 };
    double B[]     = { 24.0, -26.0, 4.0,  19.0 };
    int    size    = sizeof(A) / sizeof(A[0]);
    double what1   = -8.0;
    double what2   = 56.0;

    std::cout << "Array A: "; print(A, size);
    std::cout << "\nArray B: "; print(B, size);

    // basic stats on A
    double s       = sum(A, size);
    double m       = avg(A, size);
    int    iMin    = minIndex(A, size);
    int    iMax    = maxIndex(A, size);

    std::cout << "\n\n-- Statistics for A --\n"
              << "Sum:     " << s << "\n"
              << "Average: " << m << "\n"
              << "Min idx: " << iMin
              << " (value " << A[iMin] << ")\n"
              << "Max idx: " << iMax
              << " (value " << A[iMax] << ")\n";

    // presence test
    std::cout << "\n-- Search for " << what1 << " in A --\n";
    if (searchFor(A, size, what1))
        std::cout << what1 << " is found in A\n";
    else
        std::cout << what1 << " is NOT found in A\n";

    // swap A and B
    std::cout << "\n-- Swap A and B --\n";
    change(A, B, size);
    std::cout << "A: "; print(A, size);
    std::cout << "\nB: "; print(B, size);

    // element-wise ops
    elementWiseOps(A, B, size);

    // dot product
    double dot = dotProduct(A, B, size);
    std::cout << "\n\nDot product: " << dot << "\n";

    // first & last occurrence in B
    int firstIdx = firstOccurrence(B, size, what2);
    int lastIdx  = lastOccurrence(B, size, what2);
    std::cout << "\n-- Occurrences of " << what2 << " in B --\n";
    if (firstIdx != -1) {
        std::cout << "First at index " << firstIdx
                  << ", last at index " << lastIdx << "\n";
    } else {
        std::cout << what2 << " not found in B\n";
    }

    return 0;
}
```

---

**Build & run**

```bash
g++ -std=c++11 -o demo main.cpp functions.cpp
./demo
```


