// Program 9_11
// newline character example
#include <iostream>
using namespace std;

int main() {
	cout << "This \n is a test." << endl                        ;
	// or
	cout << "This " << endl << " is a test.";                         
}

// This program demonstrates the use of the newline character '\n' in C++.
// The newline character is used to create a new line in the output.
// In this case, the output will be:
// This
// is a test.
// The program uses the cout object to print the string "This \n is a test." to the console.
// The '\n' character is interpreted as a newline character, causing the text after it to be printed on a new line.
// The program then ends with a return statement, indicating successful completion.
// std::endl is a manipulator that can be used to insert a newline character and flush the output buffer.
// It is often used in place of '\n' for better readability and to ensure that the output is immediately displayed.
// manipulators are special functions that can be used to modify the behavior of input and output streams.
// They are often used to format the output of data in a more readable way.
// the output buffer is a temporary storage area in memory where data is held before it is sent to the output device.
// The output buffer is used to improve performance by reducing the number of write operations to the output device.
// When the output buffer is flushed, all the data in the buffer is written to the output device.