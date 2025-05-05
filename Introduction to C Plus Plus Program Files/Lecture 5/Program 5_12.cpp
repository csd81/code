// Program 5_12
// While loop for computing balance for set number of payments
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05;
	int numpayments = 0;
	while (numpayments < 5) {
		cout << "Balance after " << numpayments << " payments is: " << balance << endl;
		balance += balance * interest;
		balance -= payment;
		numpayments++;
	}                             
}