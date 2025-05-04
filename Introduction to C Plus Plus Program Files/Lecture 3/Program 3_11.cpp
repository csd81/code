// Program 3_11
// Illustrating an if-else statement
#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter an age: ";
	cin >> age;
	if ((age < 18) || (age >= 65)) {
		cout << "You're eligible for a discount!" << endl;               
	}
	else {
		cout << "Sorry, no discount is available." << endl;
		cout << "  But our prices are so low you won't even notice!" << endl;
	}
}