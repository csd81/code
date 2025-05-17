// Program 17_2
// Non-default constructor calls
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string s("Test String");
	cout << s << endl;
	fstream infile("Input.dat");     
	infile.open("Input.dat", ios::in); // Open file for input
	if (!infile) {
		cerr << "Error opening file." << endl;
		return 1; // Return an error code
	}
	infile.close(); // Close the file
	return 0; // Return success code
}

// This program demonstrates the use of non-default constructors in C++.
// It includes the necessary header files and uses the standard namespace.
// The main function creates a string object using a non-default constructor
// and prints it to the console. It also opens a file using a non-default
// constructor for the fstream class. The program demonstrates the use
// of constructors to initialize objects with specific values or states.

// fstream is a class in C++ that provides input and output operations
// on files. It is derived from both the ifstream and ofstream classes,
// allowing it to be used for both reading from and writing to files.
// The fstream class provides a convenient way to handle file I/O in C++
