// Program 3_14
// Illustrating nested if statement
#include <iostream>
using namespace std;

int main() {
	float package_weight = 5.0;
	bool send_priority = true;
	float price;
	if (send_priority) {
		if (package_weight < 3.5) {
			price = 10.00;
		}
		else {
			price = package_weight * 3.0;
		}
	}
	else {
		price = package_weight * 1.5;
	}
	cout << "Your price is " << price << endl;                                     
}