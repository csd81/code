// Program 16_2
// Calling member functions example 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "Hello";
	string s2 = "Calling member functions example 1";
	cout << s.length() << endl; // Prints the length of the string, which is 5
	cout << s2.length() << endl;
	
}

// length() is a member function of the string class
// It returns the length of the string, which is a constant;
// it does not change the string itself.
// The length() takes no arguments.
// it has a return type of int;
