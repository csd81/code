


//3.10.2. Egészítse ki az előző programot a következő feladatokat ellátó függvényekkel! Maximális eleme indexének a meghatározása, szórás kiszámítása, két tömb elemeinek a felcserélése! 

Below is a C++11 solution split into three files. It adds:

* `maxIndex` – returns the index of the largest element
* `stdDev` – computes the population standard deviation
* `change` – swaps element‐by‐element two arrays

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

// Population standard deviation: sqrt( Σ(xi–μ)² / N )
double stdDev(const double* arr, int size);

// Swap the contents of arr1 and arr2 (both length size)
void change(double* arr1, double* arr2, int size);

// Return true if value exists in arr
bool searchFor(const double* arr, int size, double value);

#endif // FUNCTION_HPP
```

---

**functions.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <cmath>

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

double stdDev(const double* arr, int size) {
    double mean = avg(arr, size);
    double sumSq = 0.0;
    for (int i = 0; i < size; ++i) {
        double diff = arr[i] - mean;
        sumSq += diff * diff;
    }
    return std::sqrt(sumSq / size);
}

void change(double* arr1, double* arr2, int size) {
    for (int i = 0; i < size; ++i) {
        double tmp   = arr1[i];
        arr1[i]      = arr2[i];
        arr2[i]      = tmp;
    }
}

bool searchFor(const double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) return true;
    }
    return false;
}
```

---

**main.cpp**

```cpp
#include "function.hpp"
#include <iostream>
#include <iomanip>

int main() {
    double A[] = { 12.0, 56.0, -7.0 };
    double B[] = { 24.0, -26.0,  4.0 };
    int size   = sizeof(A) / sizeof(A[0]);
    double what = -8.0;

    std::cout << "Array A: "; print(A, size); 
    std::cout << "\nArray B: "; print(B, size);
    
    double s  = sum(A, size);
    double m  = avg(A, size);
    int    iMin = minIndex(A, size);
    int    iMax = maxIndex(A, size);
    double sd = stdDev(A, size);
    
    std::cout << "\n\n-- Statistics for A --\n"
              << "Sum:       " << s  << "\n"
              << "Average:   " << m  << "\n"
              << "Min index: " << iMin 
                 << " (value " << A[iMin] << ")\n"
              << "Max index: " << iMax
                 << " (value " << A[iMax] << ")\n"
              << "Std Dev:   " << std::fixed << std::setprecision(4) << sd << "\n";

    std::cout << "\n-- Swapping A and B --\n";
    change(A, B, size);
    std::cout << "A: "; print(A, size);
    std::cout << "\nB: "; print(B, size);

    std::cout << "\n\n-- Search --\n";
    if (searchFor(A, size, what))
        std::cout << what << " is in A\n";
    else
        std::cout << what << " is NOT in A\n";

    return 0;
}
```

---

**Build & run**

```bash
g++ -std=c++11 -o program main.cpp functions.cpp
./program
```


