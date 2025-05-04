// Program 5_1
// Single if statement for computing balance
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05;                                                    
	int numpayments = 0;
	if (balance > 0.0) {
		balance += balance * interest;
		balance -= payment;
		numpayments++;
		cout << "Balance after " << numpayments << " payment(s) is: "            
			<< balance << endl;
	}
}
