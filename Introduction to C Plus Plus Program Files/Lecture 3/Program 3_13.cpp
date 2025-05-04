// Program 3_13
// Illustrating an if-else statement - missing curly braces
#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Enter your age: ";               
	cin >> age;
	float price;
	if ((age < 18) || (age >= 65)) {
		cout << "You're eligible for a discount!" << endl;     
		price = 5.0;
	}
	else
		cout << "Sorry, no discount is available." << endl;
		cout << "  But our prices are so low you won't even notice!" << endl;
		price = 7.5;

	cout << "Your price is " << price << endl;
}