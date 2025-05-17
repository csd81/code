// Program 5_12
// While loop for computing balance for set number of payments
// While loops are used to repeat a block of code as long as a specified condition is true.
// The while loop is a control flow statement that allows code to be executed repeatedly based on a given boolean condition.

// The while loop is useful when you want to repeat a block of code an unknown number of times,
// but you know the condition that will stop the loop.
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05;
	int numpayments = 0;
	while (numpayments < 5) { // 0 to 4
		cout << "Balance after " << numpayments << " payments is: " << balance << endl;
		balance += balance * interest;
		balance -= payment;
		numpayments++;
	}                             
}