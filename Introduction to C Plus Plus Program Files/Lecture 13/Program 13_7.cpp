// Program 13_7
// Reference example
#include <iostream>
using namespace std;

int main() {
	int a = 1;  // a is an integer variable
	int& b = a; // b is a reference to a, meaning it refers to the same memory location as a
	cout << a << " " << b << endl;
	a = 2;
	cout << a << " " << b << endl;
	b = 3;
	cout << a << " " << b << endl;                    
}

// In this program, we declare an integer variable a and initialize it to 1.
// We then declare a reference variable b that refers to a.
// When we change the value of a, the value of b also changes because they refer to the same memory location.

// using a reference allows us to create an alias for a variable,
// it is good for passing variables to functions without copying them
// and for modifying the original variable directly.
// References are often used in function parameters to avoid copying large objects and to allow functions to modify the original object.
