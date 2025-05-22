// 8.1.2. Ismerje meg és valósítson meg a következő rendező függvények közül kettőt! Beszúró rendezés, shell rendezése, radix rendezés, shaker rendezés, heap rendezés, comb rendezés. 8.2. Rekurzív függvények

// Below is a clean C++11 example that implements both **comb sort** and **(binary) insertion sort**, then demonstrates them on the same array. I’ve also included a simple `print()` helper to show the results.


#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------
// Helper: print array
void print(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
}

// -----------------------------------------------------------------------------
// Comb Sort
// Shrinks gap by factor ≈1.3 each pass; finishes with a final bubble-pass (gap=1).
void combSort(vector<int>& arr) {
    const double SHRINK = 1.3;
    int gap = arr.size();
    bool swapped = false;

    while (gap > 1 || swapped) {
        // update gap for next comb
        gap = int(gap / SHRINK);
        if (gap < 1) gap = 1;

        swapped = false;
        // one "comb" over the array
        for (size_t i = 0; i + gap < arr.size(); ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------
// Binary Insertion Sort
// Uses binary search to find insertion point in the sorted prefix.
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        // find insertion position in [0..i-1]
        size_t lo = 0, hi = i;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (key < arr[mid])
                hi = mid;
            else
                lo = mid + 1;
        }
        // shift elements right to make room for key
        for (size_t j = i; j > lo; --j) {
            arr[j] = arr[j - 1];
        }
        arr[lo] = key;
    }
}

// -----------------------------------------------------------------------------
// Demonstration
int main() {
    vector<int> original = {5, 8, 3, 4, 12, 45, 87};

    // Comb sort
    auto a1 = original;
    cout << "Before combSort:     "; print(a1);
    combSort(a1);
    cout << "After combSort:      "; print(a1);
    cout << "\n";

    // Insertion sort
    auto a2 = original;
    cout << "Before insertionSort:"; print(a2);
    insertionSort(a2);
    cout << "After insertionSort: "; print(a2);

    return 0;
}
/*
*```

**Key points:**

* **`combSort`** repeatedly reduces the comparison gap by ≈1.3 until it reaches 1, and does a final bubble‐style pass to ensure full ordering.
* **`insertionSort`** uses binary search to locate where each new element belongs in the already‐sorted prefix, then shifts elements to insert it.
* `print()` takes a `vector<int>&` and writes it in a nice `[ ... ]` format.

Feel free to swap in plain arrays if you prefer, but `std::vector` makes resizing and bounds clearer in modern C++.

*/