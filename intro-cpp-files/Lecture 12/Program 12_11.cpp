// Program 12_11
//Use of a global variable
#include<iostream>
using namespace std;

int a; // global variable because it is declared outside of any function

void my_function() {
	a++;
}

int main() {
	a = 1;
	cout << "Before the function call, the value of a is: " << a << endl;
	my_function();
	cout << "After the function call, the value of a is: " << a << endl;                     // it is incremented by 1 = 2
	return 0;
}

// global variables are variables that are declared outside of any function and can be accessed by any function in the program.
// They have a global scope, meaning they can be accessed from anywhere in the program.
// Global variables are useful for sharing data between functions, but they can also lead to code that is difficult to understand and maintain.
// It is generally recommended to use local variables whenever possible and only use global variables when necessary.
// Local variables are variables that are declared inside a function and can only be accessed within that function.
// They have a local scope, meaning they can only be accessed from within the function in which they are declared.
// Local variables are useful for encapsulating data and preventing unintended side effects on other parts of the program.
// They are generally preferred over global variables because they help to keep the code modular and easier to understand.
// The program demonstrates the use of a global variable called a.
// The variable a is declared outside of any function, making it accessible to all functions in the program.
// The program defines a function called my_function() that increments the value of a.
// The main() function initializes a to 1, outputs its value, calls my_function(), and then outputs the updated value of a.