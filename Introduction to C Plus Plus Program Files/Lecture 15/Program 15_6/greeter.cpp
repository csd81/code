// Program 15_6b
// definition (implementation) file for library
// greeter.cpp

#include "greeter.h"
#include <iostream>
using namespace std;

void mynamespace::greeting() {
	cout << "Hello!" << endl;           
}   


// source files are used to implement the functions, classes, and variables declared in the header file.
// they typically have a .cpp extension and contain the actual code that performs the operations declared in the header file.
// source files can include other source files and header files using the #include directive.
// this allows us to use the functions, classes, and variables declared in the header file in our source file.

// using namespace mynamespace;
// // main program
// int main() {
// 	greeting(); // Call the greeting function from the mynamespace namespace
// 	return 0;
// }
// // this program demonstrates how to use namespaces in C++ to organize code and avoid naming conflicts.