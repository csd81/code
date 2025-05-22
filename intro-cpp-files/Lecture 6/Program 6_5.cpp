// Program 6_5
// Using multiple arguments in a function call
#include <iostream>
#include <cmath>
using namespace std;

int main() {

double base;
double exp;
cout << "Enter a base: ";
cin >> base; // This line reads a double value from the standard input (keyboard) and stores it in the variable base.
cout << "Enter an exponent: ";
cin >> exp; // This line reads a double value from the standard input (keyboard) and stores it in the variable exp.

cout << base << " to the " << exp << " power is: " << pow(base, exp) << endl; // This line prints the result of raising the base to the power of the exponent. 
// The pow function is used to calculate the power of a number.
}

// we can use multiple arguments in a function call.
// The pow function takes two arguments: the base and the exponent.
// It calculates the value of the base raised to the power of the exponent.
// The pow function is defined in the cmath library.
// The syntax for using the pow function is:
// double pow(double base, double exponent);
// where base is the number to be raised to a power, and exponent is the power to which the base is raised.