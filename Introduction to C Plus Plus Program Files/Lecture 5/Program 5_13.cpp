// Program 5_13
// For loop for computing balance for set number of payments
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05;
	int numpayments;
	for (numpayments = 0; numpayments < 5; numpayments++) {
		cout << "Balance after " << numpayments << " payments is: " << balance << endl;
		balance += balance * interest;
		balance -= payment;
	}                     
}

// for loops are used to repeat a block of code a specific number of times.
// The for loop is a control flow statement that allows code to be executed repeatedly based on a given boolean condition.
// The for loop is useful when you know the number of times you want to repeat a block of code.
// The syntax of the for loop is as follows:
// for (initialization; condition; increment/decrement) {
//     // block of code to be executed
// }

// for loops are used to traverse arrays, lists, and other data structures.

