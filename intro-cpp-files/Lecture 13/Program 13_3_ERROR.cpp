// Program 13_3_ERROR
// Multiple parameter types; Error when trying to use floats due to double
#include <iostream>
using namespace std;

double average(double a, double b) {
	return (a + b) / 2.0;
}

int average(int a, int b) {
	return (a + b) / 2;
}

int main() {
	cout << "The average of 10 and 35 is: " << average(10.1, 35.5) << endl;               // Error: ambiguous call to 'average'
	cout << "The average of 10 and 35 is: " << average(10, 35) << endl;                 // Error: ambiguous call to 'average'
}



// ambiguous call means that the compiler cannot determine which version of the function to call
// because there are multiple functions with the same name that could match the arguments provided. 
// In this case, both versions of the average function could be called with the arguments (10.0, 35.0) and (10, 35), leading to ambiguity.

// the difference bw a float and a double is that a float is a single-precision floating-point number, while a double is a double-precision floating-point number.
// This means that a double can represent a wider range of values and has more precision than a float.
// In C++, the default floating-point type is double, so when you write a floating-point literal like 10.1 or 35.5, it is treated as a double.
