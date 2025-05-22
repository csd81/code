// Program 9_12
// Accessing string elements
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "This string is not a knot.."; // ha-ha :)
	cout << s[0] << endl; // prints the first character of the string
	cout << s.at(3) << endl;                               // prints the fourth character of the string
} 

// This program demonstrates how to access individual characters in a string using both the subscript operator [] and the at() method.
// the subscript operator [] is used to access the character at a specific index in the string.
// the subscript operator [] is used to access the character at a specific index in an array or string.
// The at() method is a member function of the string class that returns a reference to the character at the specified index.

// other member functions of the string class include:
// length() - returns the length of the string
// size() - returns the size of the string
// clear() - removes all characters from the string
// empty() - returns true if the string is empty, false otherwise
// find() - searches for a substring within the string and returns the index of the first occurrence
// substr() - returns a substring of the string starting at the specified index and with the specified length

// The program then prints the first and fourth characters of the string to the console.
