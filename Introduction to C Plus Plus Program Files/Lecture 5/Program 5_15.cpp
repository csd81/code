// Program 5_15
// For loop with initialization and update outside the for statement
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05;
	int numpayments = 0; // initialization is done outside the for statement
	for (; numpayments < 5;) { 
		cout << "Balance after " << numpayments << " payments is: " << balance << endl;
		balance += balance * interest;
		balance -= payment;
		numpayments++; // update is done outside the for statement, this is not a good practice, but it is allowed
	}                              
}

// this is not a good practice because it makes the code less readable and harder to maintain.
// It is better to keep the initialization and update inside the for statement to make the code more readable and easier to understand.