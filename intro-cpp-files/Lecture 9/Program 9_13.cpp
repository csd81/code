// Program 9_13
// String size
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = " This string is not a knot.";                
	cout << "Size is: " << s.size() << endl; // prints the size of the string
	cout << "Length is: " << s.length() << endl;                         // prints the length of the string
}
// the difference between size() and length() is that size() returns the number of characters in the string, 
// while length() returns the number of characters in the string.
// In practice, both functions return the same value, so you can use either one interchangeably.
// The program then prints the size and length of the string to the console.	