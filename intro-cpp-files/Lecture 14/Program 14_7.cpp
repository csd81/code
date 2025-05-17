// Program 14_7
// Throwing exceptions - throwing directly
#include <iostream>
#include <stdexcept>
using namespace std;

int process_boxes(int num_boxes) {
	if (num_boxes < 1) {
		throw exception();
	}
	//Do other stuff here
	return 1;
}

int main() {
	try {
		process_boxes(-1);
	}
	catch (exception& e) {
		cout << "Had an exception!" << endl;
	}
}

// stdexcept is a standard library header that provides classes and functions for handling exceptions in C++.
// It includes the standard exception class and its derived classes, which can be used to represent different types of exceptions.
// throw is a keyword in C++ that is used to throw an exception.
// When an exception is thrown, the program control is transferred to the nearest catch block that can handle the exception.
// This allows us to handle errors and exceptional conditions in a structured way.