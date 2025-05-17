// Program 17_6
// Example of shifting bits
#include <iostream>
using namespace std;

int main() {
	int i = 1; // 00000001 in binary	
	int j = i << 3;  // Shifting bits 3 spaces left 
	// 00001000 in binary, which is 8 in decimal
	cout << j << endl;                                    // Output: 8
}



// bit shifting is a common operation in C++
// and is often used in low-level programming, such as systems programming
// and embedded systems. It can be used for tasks such as bit manipulation,
// data compression, and cryptography.
// It is important to note that bit shifting can lead to undefined behavior
// if not used carefully, especially when shifting bits beyond the size of the data type.
// In C++, the left shift operator (<<) shifts the bits of a number to the left
// by a specified number of positions, effectively multiplying the number by 2 for each position shifted.
// The right shift operator (>>) shifts the bits of a number to the right
// by a specified number of positions, effectively dividing the number by 2 for each position shifted.
// The result of a left shift operation is equivalent to multiplying the number by 2 raised to the power of the number of positions shifted.
// For example, shifting the number 1 (binary 0001) three positions to the left
// results in the number 8 (binary 1000), which is equivalent to 1 * 2^3.
// Similarly, shifting the number 8 (binary 1000) three positions to the right
// results in the number 1 (binary 0001), which is equivalent to 8 / 2^3. 