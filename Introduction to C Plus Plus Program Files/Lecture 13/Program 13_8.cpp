// Program 13_8
// Passing by Reference
#include<iostream>
using namespace std;

void increase_percentage(float& value, float percentage) { // value is passed by reference, so it can be 
	value += value * (percentage / 100.0);  // we can change the value of the original variable
}

int main() {
	float savings_balance = 1000.0;  // savings_balance is a float variable
	cout << savings_balance << endl; // prints the initial value of savings_balance
	increase_percentage(savings_balance, 28); // increase the savings_balance by 28%
	cout << savings_balance << endl;                     // prints the updated value of savings_balance
}

// value is passed by reference, so it can be changed in the function
// this allows us to modify the original variable directly
// without creating a copy of it
// this is useful when we want to modify the original variable directly
// or when we want to avoid copying large objects