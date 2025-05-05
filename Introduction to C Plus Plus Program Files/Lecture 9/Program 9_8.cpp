// Program 9_8
// Appending a string
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	cout << "Enter your name: ";
	getline(cin, n); // Using getline to read the name
	string s = "Happy";
	s += " "; // Adding a space
	s += "Birthday";
	s += " "; // Adding a space
	s += n; // Adding a name
	s += " !"; // Adding an exclamation mark
	cout << s << endl;                   
}

// The program demonstrates how to append a string to another string using the += operator.
// The += operator is a shorthand for concatenation and assignment, allowing you to add a string to an existing string variable.
// In this case, the string "Birthday" is appended to the existing string "Happy", resulting in the output "HappyBirthday".
// the += operator is overloaded for string objects, allowing you to concatenate a string literal or another string object to an existing string variable.
// This operator modifies the original string variable in place, so you don't need to create a new string variable to store the result.
// The program will output "HappyBirthday" to the console.