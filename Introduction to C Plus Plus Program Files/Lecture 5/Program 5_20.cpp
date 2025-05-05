// Program 5_20
// Declaring a static variable in a loop
#include <iostream>
using namespace std;

int main() {
	int i;
	for (i = 1; i < 4; i++) {
		static int j = 1;
		cout << "In loop: " << i << " " << j << endl;
		j++;
	}
	cout << "After loop: " << i << endl;                                 
	// cout << "After loop: " << j << endl;     // this will cause an error because j is not declared in this scope                            
}

// Declaring a static variable in a loop is a common practice in C++.
// A static variable is a variable that retains its value between function calls.	
// The static variable is initialized only once, and its value is retained between function calls.
// The static variable is stored in the data segment of the program, which is a region of memory used for static variables.
// The static variable is not destroyed when the function exits, and it retains its value between function calls.
// if we declare  a static variable in a loop, the variable will retain its value between iterations of the loop, but it will not be accessible outside the loop.
// The static variable is only accessible within the loop, and it is automatically destroyed when the loop terminates.