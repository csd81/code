// Program 12_12
// Use of local variables only
#include<iostream>
using namespace std;

void my_function(int& x) { // pass by reference so that the function can modify the value of x
	x++;
}

int main() {
	int a = 1; // local variable
	// a is declared inside the main function, so it has local scope
	cout << "Before the function call, the value of a is: " << a << endl;
	my_function(a);
	cout << "After the function call, the value of a is: " << a << endl;            
}

// local variables are variables that are declared inside a function and can only be accessed within that function.
// They have a local scope, meaning they can only be accessed from within the function in which they are declared.
// it is generally recommended to use local variables whenever possible and only use global variables when necessary.