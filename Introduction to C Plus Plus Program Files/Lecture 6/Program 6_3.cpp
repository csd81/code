// Program 6_3
// Using more than one library 
//  A library is a collection of precompiled routines that a program can use.
//  Libraries are used to provide additional functionality to a program without having to write the code from scratch.
//  In C++, libraries are typically included using the #include directive.
//  The #include directive tells the compiler to include the specified library in the program.
//  This allows the program to use the functions and classes defined in the library.
//  The iostream library is a standard C++ library that provides input and output functionality.
//  The string library is a standard C++ library that provides string manipulation functionality.
//  The iostream library is included to use the standard input/output stream objects.
//  The string library is included to use the string class and its associated functions.
#include<iostream>
#include<string>
using namespace std;

int main() {
	cout << "Enter your name: ";
	// string name; // std::string is a class in the C++ standard library that represents a string of characters.
	// cin >> name; // This line reads a string from the standard input (keyboard) and stores it in the variable name. 
	// if you enter a string with spaces, only the first word will be stored in the variable name.
	// To read a string with spaces, you can use the getline function instead of cin.
	// getline(cin, name); // This line reads a line of text from the standard input (keyboard) and stores it in the variable name.

	// cout << "Hello, " << name << "!" << endl; // This line prints a greeting message to the console, including the user's name.

	string name1;
	getline(cin, name1);
	cout << "Hello, " << name1 << "!" << endl; // This line prints a greeting message to the console, including the user's name.

}

