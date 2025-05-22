//8.1.1. Írjon függvényt, amely buborék illetve minimum kiválasztásos módszerrel rendez egy tömböt! Írjon segédfüggvényeket a minIndex, swap, print (tömb kiírás) feladatokra! 

#include <iostream>
using namespace std;

// Prints the array
void print(const double* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "]";
}

// Returns the index of the minimum element in arr[0..size-1]
int minIndex(const double* arr, int size) {
    int minIdx = 0;
    for (int i = 1; i < size; ++i)
        if (arr[i] < arr[minIdx])
            minIdx = i;
    return minIdx;
}

// Swaps arr[id1] and arr[id2]
void swap(double* arr, int id1, int id2) {
    double tmp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2] = tmp;
}

// Selection sort (minimum‐selection) on tomb[0..len-1]
void minSort(double* tomb, int len) {
    for (int i = 0; i < len; ++i) {
        // find min in tomb[i..len-1]
        int c = minIndex(tomb + i, len - i) + i;
        swap(tomb, i, c);
    }
}

// Bubble sort on tomb[0..len-1]
void bubbleSort(double* tomb, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (tomb[j] > tomb[j + 1]) {
                swap(tomb, j, j + 1);
            }
        }
    }
}

int main() {
    double myArray[]  = { 22, 16, -7, -42, 6 };
    double myArray2[] = { 22, 16, -7, -42, 6 };
    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Original myArray: ";
    print(myArray, size);
    cout << endl;

    minSort(myArray, size);
    cout << "Min‐sorted myArray: ";
    print(myArray, size);
    cout << endl << endl;

    cout << "Original myArray2: ";
    print(myArray2, size);
    cout << endl;

    bubbleSort(myArray2, size);
    cout << "Bubble‐sorted myArray2: ";
    print(myArray2, size);
    cout << endl;

    return 0;
}
