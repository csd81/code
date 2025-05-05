// Program 5_16
// Illustrating value of variable after a loop
#include <iostream>
using namespace std;

int main() {
	int i;
	for (i = 1; i < 4; i++) {
		cout << "In loop: " << i << endl;
	}
	cout << "After loop: " << i << endl;                                     
}

// The value of i after the loop is 4 because the loop condition is checked before each iteration.
// When the loop condition becomes false (i.e., when i is no longer less than 4), the loop terminates.
// The value of i is incremented to 4 after the last iteration of the loop, so when the loop terminates, i is equal to 4.