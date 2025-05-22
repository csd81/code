// Program 10_8
// Using a stringstream for input
#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main() {
	stringstream wordreader; // create a stringstream object
	wordreader.str("Apple Banana Cherry");
	string first_word;
	string sec;
	wordreader >> first_word >> sec;
	
	cout << "The first string read was: " << first_word << endl;          
	cout << "The 2nd string read was: " << sec << endl;          
}

// sstream is a header file in the C++ standard library that provides classes for input and output operations on strings.
// It includes the stringstream class, which is used to read from and write to strings as if they were input/output streams.
// The stringstream class is derived from the iostream class and provides the same functionality as the iostream class, 
// but for strings instead of files.
// The stringstream class is used to create a string stream object that can be used to read from and write to strings.
// The stringstream class provides several member functions for string operations, including:
// 1. str(): Gets or sets the contents of the string stream.
// 2. clear(): Clears the contents of the string stream.

// the >> operator is used to read data from the string stream into a variable.
// The >> operator works in the same way as it does for input streams, reading data until a whitespace character is encountered.
// The stringstream class is useful for parsing strings, formatting output, and performing input/output operations on strings.