// Program 3_14
// Illustrating nested if statement
// nested if statements are used to execute a block of code if a condition is true; otherwise, the block of code is skipped.
// the compiler will check the first condition; if it is true, it will check the second condition; if it is true, it will execute the block of code; otherwise, it will skip the block of code.
#include <iostream>
using namespace std;

int main() {
	float package_weight;
	cout << "Enter the weight of the package: ";
	cin >> package_weight;  // input the weight of the package
	bool send_priority;
	cout << "Do you want to send it priority? (1 for yes, 0 for no): ";
	cin >> send_priority;  // input whether to send it priority or not
	float price;
	if (send_priority) {  // in this case it is true, so we will check the next condition
		cout << "Priority shipping" << endl;
		if (package_weight < 3.5) {
			cout << "Light package (we charge a flat rate)" << endl;
			price = 10.00;
		}
		else {
			cout << "Heavy package" << endl;
			cout << "We charge by weight" << endl;
			price = package_weight * 3.0;
		}
	}
	else {
		cout << "Standard shipping" << endl;
		cout << "non-Priority shipping" << endl; // it is cheaper

		price = package_weight * 1.5;
	}
	cout << "Your price is " << price << endl;                                     
}