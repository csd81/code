// Program 12_5
// Demonstrating early return
#include<iostream>
using namespace std;

void demo_func() {
	cout << "Line 1" << endl;
	return; // early return
	// The function exits here, and the following line will not be executed.
	cout << "Line 2" << endl;
	return;
}

int main() {
	demo_func();                   // outputs only "Line 1"
}

// early return is a programming technique where a function exits before reaching the end of its code block.
// It is often used to simplify code, improve readability, and reduce the number of nested blocks.
// Early return can be used to handle error conditions, validate input, or exit a function when a certain condition is met.