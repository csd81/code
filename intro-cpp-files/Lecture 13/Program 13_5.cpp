// Program 13_5
// Using a Default Parameter
#include <iostream>
#include <string>
using namespace std;

void printmultiple(string s, int times = 10) { // the default value for times is 1
	for (int i = 0; i < times; i++) {
		cout << s << " ";
	}
	cout <<  endl;
}


int main() {
	printmultiple("World");                
	printmultiple("Hello", 1);
	printmultiple("Hello", 5);
	printmultiple("Hello", 19);
	
}

// we can call the function with one or two arguments
// if we call it with one argument, the default value for times will be used
// this allows us to provide a default value for a parameter, making it optional
// this is useful when we want to provide a default behavior for a function
// without requiring the caller to specify all the arguments every time