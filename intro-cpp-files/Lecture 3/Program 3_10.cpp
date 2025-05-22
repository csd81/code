// Program 3_10
// Illustrating an if statement
// The if statement is used to execute a block of code if a condition is true; otherwise, the block of code is skipped.

#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter your age: ";
	cin >> age;
	if ((age < 18) || (age >= 65)) {
		cout << "You're eligible for a discount!" << endl;                 
	} else cout << "You are not eligible for a discount!" << endl;       
	// the else statement is optional; if it is not included, the program will simply skip the block of code if the condition is false
  	// The if statement is used to execute a block of code if a condition is true; otherwise, the block of code is skipped.         
}