// Program 8_16_a
// ERROR - Attempting to assign arrays is not allowed
#include <iostream>
using namespace std;

int main() {
	int a[3] = { 1, 2, 3};
	int b[3];
	// b = a; // ERROR - Attempting to assign arrays is not allowed
	// instead, we need to copy the elements of the array a to the array b using a loop

	for (int i = 0; i < 3; i++) { // loop through the array using a for loop
		b[i] = a[i];                                        // copy each element of the array a to the array b
	}

	for (int i = 0; i < 3; i++) { // loop through the array using a for loop
		cout << b[i] << " ";                               // print each element of the array b
	}
	cout << endl; // print a new line
}