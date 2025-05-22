// Program 6_4
// Using cmath (and iostream)
#include <iostream>
// iostream is a standard C++ library that provides input and output functionality.

#include <cmath>
// cmath is a standard C++ library that provides mathematical functions.
// It includes functions for performing common mathematical operations such as square root, trigonometric functions, logarithms, and more.
// The cmath library is included to use the sqrt function, which calculates the square root of a number.
// the sqrt function is defined in the cmath library. The syntax for using the sqrt function is:
// double sqrt(double x);
// where x is the number for which you want to calculate the square root.
// The function returns the square root of x as a double value.

using namespace std;

int main() {
	cout << "Enter a number: ";
	
	double base;
	double root;
	cin >> base; // This line reads a double value from the standard input (keyboard) and stores it in the variable base.

	root = sqrt(base);
	cout << "Square root of " << base << " is " << root << endl; // This line prints the square root of the number to the console.

}