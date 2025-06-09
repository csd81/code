// 8.2.1. Valósítsa meg a gyorsrendezést! Mindig írja ki, hogy milyen mélyen van a rekurzióban statikus változó segítségével, és hogy mely résztömböt rendezi éppen! A kiírásokat a rekurzió mélysége alapján tabulálja! 


#include <iostream>
#include <iomanip>
using namespace std;

// Print the array
void print(const double* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        // fixed precision for readability
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << "]";
}

// Swap two elements in the array
void swap(double* arr, int i, int j) {
    double tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// Hoare partition scheme: returns index j such that arr[left..j] ≤ pivot ≤ arr[j+1..right]
int partition(double* arr, int left, int right) {
    double pivot = arr[left + (right - left) / 2];
    int i = left - 1;
    int j = right + 1;
    while (true) {
        // move j left until arr[j] ≤ pivot
        do { --j; } while (arr[j] > pivot);
        // move i right until arr[i] ≥ pivot
        do { ++i; } while (arr[i] < pivot);
        if (i < j) {
            swap(arr, i, j);
        } else {
            return j;
        }
    }
}

// QuickSort with recursion-depth tracing
void quickSort(double* arr, int left, int right) {
    static int level = 0;
    ++level;

    // indent according to recursion level
    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "Begin quickSort level " << level
         << ", range [" << left << ", " << right << "]\n";

    if (left < right) {
        int split = partition(arr, left, right);
        quickSort(arr, left, split);
        quickSort(arr, split + 1, right);
    }

    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "End   quickSort level " << level
         << ", range [" << left << ", " << right << "]\n";

    --level;
}

int main() {
    double myArray[] = { 0, -6, 7, -42, 6, 9 };
    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Original array: ";
    print(myArray, size);
    cout << "\n\n";

    quickSort(myArray, 0, size - 1);

    cout << "\nFinal sorted array: ";
    print(myArray, size);
    cout << "\n";

    return 0;
}
