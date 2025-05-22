// Program 2_17
// Integer Division
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	a = 7;                                                     
	b = 3;
	cout << a + b << endl;  // Addition results in 10
	// Note: The result of integer addition is an integer
	cout << a - b << endl;  // Subtraction results in 4
	cout << a * b << endl;  // Multiplication results in 21
	cout << a / b << endl;  // Division of INTEGERS (no remainder) results in 2
	// Note: The result of integer division is an integer, the decimal part is discarded
	cout << a % b << endl;  // Modulus results in 1
	cout << a / 3.0 << endl; // Division of FLOAT results in 2.33333 
		// implicit conversion
}