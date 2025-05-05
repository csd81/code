// Program 5_6
// INFINITE loop for computing balance - payment is less than interest,       
//so goes on forever
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 1.0;  // Notice: payment is too small
	float interest = 0.05;
	int numpayments = 0;
	while (balance > 0.0) {
		balance += balance * interest;
		balance -= payment;
		numpayments++;
		cout << "Balance after " << numpayments << " payment(s) is: " 
			<< balance << endl;
	}                                     
}