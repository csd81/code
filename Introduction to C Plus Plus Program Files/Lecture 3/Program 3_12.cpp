// Program 3_12
// Multiple operations within if and else clauses
// if we have multiple operations within the if and else clauses, we can use the following syntax:
// if (condition) {
// 	// multiple operations
// 	// ...
// }
// So the statements are enclosed in curly braces.

#include <iostream>
using namespace std;

int main() {
	int age;                                                
	cout << "Enter your age: ";
	cin >> age;
	float price; // price is a float variable; we declare it but do not initialize it
	// float is a data type that can hold decimal values
	// it is like double but has less precision;

	if ((age < 18) || (age >= 65)) {
		cout << "You're eligible for a discount!" << endl;
		price = 5.1;
	}
	else {
		cout << "Sorry, no discount is available." << endl;
		cout << "  But our prices are so low you won't even notice!" << endl;     
		price = 7500.1;
	}
	cout << "Your price is " << price << endl;

	// when we output a float variable, it is automatically 
}