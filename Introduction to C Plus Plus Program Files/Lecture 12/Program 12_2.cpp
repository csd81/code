// Program 12_2
// Demonstrating variable in a function
#include<iostream>
using namespace std;

void howdy10() {
	int i;
	for (i = 0; i < 10; i++) {
		cout << "Howdy" << " ";
	}
	cout  << endl;
}

int main() {
	howdy10();                 
	howdy10();                 
	howdy10();                 
}

// The program defines a function called howdy10() that prints "Howdy" 10 times.
// The function uses a for loop to iterate from 0 to 9 and outputs "Howdy" in each iteration.
// The main() function calls the howdy10() function to execute it.
// The program demonstrates the use of a function to encapsulate a block of code that can be reused.