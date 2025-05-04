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