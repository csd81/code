// Program 2_16
// Program to show arithmetic in C++
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	a = 12;
	b = 10;                                                        
	cout << a + b << endl;  // Addition 22
	cout << a - b << endl;  // Subtraction 2
	cout << a * b << endl;  // Multiplication 120
	cout << a / b << endl;  // Division of integers 1
							// Note: The result of integer division is an integer		; the decimal part is discarded
	cout << a % b << endl;  // Modulus 2
	cout << a / 10.0 << endl; // Division of float 1.2
	  // Note: The result of float division is a float
	  // this is called "promotion" or "implicit conversion" or "automatic conversion" or implicit type cast
	

}	