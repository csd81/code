// Program 3_1
// Illustrating Boolean values
// Boolean values are used to represent true and false; the value are represented by 1 and 0 respectively.
#include <iostream>
using namespace std;

int main() {
	bool test_true = true;
	bool test_false = false;
	cout << "test_true is: " << (test_true ? "yes" : "no"  ) << endl; // using the ternary operator
	cout << "test_false is: " << (test_false ? "TRUE" : "FALSE") << endl;          // Using the ternary operator
}