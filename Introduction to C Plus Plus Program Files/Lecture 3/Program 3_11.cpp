// Program 3_11
// Illustrating an if-else statement
// The if-else statement is used to execute one block of code if a condition is true and another block of code if the condition is false.
// there can be multiple else if statements in between the if and else statements. In this case, the first condition that is true will execute its block of code and the rest will be skipped.
// and the else is the last statement in the if-else statement; it is optional; if it is not included, the program will simply skip the block of code if the condition is false

#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter an age: ";
	cin >> age;
	if ((age < 18) || (age >= 65)) {
		cout << "You're eligible for a discount!" << endl;               
	}
	else if ((age >= 21) || (age <= 25)) {
		cout << "Sorry, no discount is available." << endl;
		cout << "  But you can buy cigarettes!" << endl;
	}
	else   {
		cout << "Sorry, no discount is available." << endl;
		cout << "  But our prices are so low you won't even notice!" << endl;
	}
}