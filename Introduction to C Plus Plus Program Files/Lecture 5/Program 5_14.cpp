// Program 5_14
// For loop with initialization outside the for statement
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05;
	int numpayments = 0;
	for (; numpayments < 5; numpayments++) {
		cout << "Balance after " << numpayments << " payments is: " << balance << endl;
		balance += balance * interest;
		balance -= payment;
	}                       
}
