// Program 14_6
// Exception example - reading a nonexistent file, now with try/catch
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream infile;
	infile.exceptions(fstream::failbit);
	try {
		infile.open("something.dat", fstream::in);
	}
	catch (exception& category) {
		cout << "Error opening file" << endl;
		return 1;
	}
	int a;
	infile >> a;
	cout << "Read in: " << a << endl;                             
}

// fstream::failbit is a flag that indicates that an input/output operation has failed.
// When this flag is set, it means that the stream is in a failed state and cannot be used for input/output operations.
// In this program, we set the failbit exception flag for the fstream object infile.
// This means that if any input/output operation fails, an exception will be thrown.
// We then use a try-catch block to catch the exception and handle it gracefully.
// This allows us to provide a better user experience and prevent the program from crashing.

// sfstream::exceptions() is a member function of the fstream class that sets the exception flags for the stream.
// When we call this function with the failbit flag, it tells the stream to throw an exception if any input/output operation fails.
// This is useful for error handling in file I/O operations.

// the try/catch block is a way to handle exceptions in C++.
// The try block contains the code that may throw an exception, and the catch block contains the code that handles the exception.