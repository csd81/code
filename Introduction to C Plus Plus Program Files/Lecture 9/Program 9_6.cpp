// Program 9_6
// Adding strings
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2, s3, s4;
	cout << "Enter your name: ";
	cin >> s4;
	
	s1 = "Happy";
	s2 = " ";
	s3 = "Birthday";
	
	cout << s1 + s2 + s3 + s2 +  s4 + " !" << endl;                  
}

// the string class in C++ provides a convenient way to manipulate strings, including concatenation.
// The + operator is overloaded for string objects, allowing you to concatenate two strings easily.
// In this example, s1 and s2 are concatenated to form s3, which is then printed to the console.