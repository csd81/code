// Program 9_14
// Comparing strings
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	                                                      
	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;
	if (s1 > s2) {
		cout << "\"" << s1 << "\" is greater than \"" << s2 << "\"" << endl;
	}
	else {
		cout << "\"" << s1 << "\" is NOT greater than \"" << s2 << "\"" << endl;
	}
}
// This program compares two strings entered by the user and prints whether the first string is greater than the second string.	
// The program uses the comparison operator > to compare the two strings.
// In C++, strings can be compared using the comparison operators <, >, <=, >=, ==, and !=.
// The comparison is done lexicographically, meaning that the strings are compared character by character based on their ASCII values.
// lexicographically means that the strings are compared character by character based on their ASCII values.
// The program first prompts the user to enter two strings.
// It then compares the two strings using the > operator and prints the result to the console.

// > operator is overloaded for the string class in C++.
// The overloaded operator compares the strings character by character based on their ASCII values.
// each  comparison operator is overloaded for the string class in C++.