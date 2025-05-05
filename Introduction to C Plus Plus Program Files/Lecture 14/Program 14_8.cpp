// Program 14_8
// Throwing exceptions - create then throw
#include <iostream>
#include <stdexcept>
using namespace std;

int process_boxes(int num_boxes) {
	if (num_boxes < 1) {
		exception bad_input;
		throw bad_input;
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

// // stdexcept is a standard library header that provides classes and functions for handling exceptions in C++.
// // It includes the standard exception class and its derived classes, which can be used to represent different types of exceptions.
// // throw is a keyword in C++ that is used to throw an exception.