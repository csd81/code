// 8.2.2. Valósítsa meg a Fibonacci sort rekurzívan! 
// Az előző program szerint tabulálással jelölje, hogy milyen mélyen van a rekurzióban!  

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------
// Prints the Fibonacci array so far
void print(const vector<long>& arr) {
    cout << "[ ";
    for (long x : arr)
        cout << x << " ";
    cout << "]\n";
}

// -----------------------------------------------------------------------------
// Recursively generate Fibonacci numbers into `arr`, starting at index `idx`.
// `first` and `second` are the two previous values.
// `remaining` is how many more to generate.
// Uses a static `level` to track recursion depth and tabulate the output.
void fibonacci(vector<long>& arr,
               long first,
               long second,
               int remaining,
               int idx)
{
    static int level = 0;
    if (remaining <= 0) return;

    ++level;
    // Indent according to depth
    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "Begin Fibonacci recursion at level " << level
         << ", filling index " << idx << "\n";

    // Compute next Fibonacci number and store it
    arr[idx] = first + second;

    // Recurse for the rest
    fibonacci(arr, second, first + second, remaining - 1, idx + 1);

    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "End   Fibonacci recursion at level " << level
         << ", filled index " << idx << "\n";

    --level;
}

// -----------------------------------------------------------------------------
// Driver
int main() {
    int maxIndex;
    cout << "Max index of the Fibonacci series? ";
    cin  >> maxIndex;

    if (maxIndex <= 0) {
        cout << "No elements to display.\n";
        return 0;
    }

    // Prepare array of size maxIndex
    vector<long> fib(maxIndex);

    // First two elements are 1, if they exist
    fib[0] = 1;
    if (maxIndex > 1) {
        fib[1] = 1;
        // Generate the remaining maxIndex-2 elements starting at index 2
        fibonacci(fib, 1, 1, maxIndex - 2, 2);
    }

    // Print final series
    cout << "\nFinal Fibonacci series (" << maxIndex << " elements): ";
    print(fib);

    return 0;
}

