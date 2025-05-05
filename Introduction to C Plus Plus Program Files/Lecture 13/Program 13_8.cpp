// Program 13_8
// Passing by Reference
#include<iostream>
using namespace std;

void increase_percentage(float& value, float percentage) {
	value += value * (percentage / 100.0);
}

int main() {
	float savings_balance = 1000.0;
	cout << savings_balance << endl;
	increase_percentage(savings_balance, 10);
	cout << savings_balance << endl;                     
}