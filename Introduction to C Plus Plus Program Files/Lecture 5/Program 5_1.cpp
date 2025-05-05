// Program 5_1
// Single if statement for computing balance
// 
// This program computes the balance of a bank account after one payment
// and one interest charge. The program uses a single if statement to
// determine if the balance is greater than 0.0. If it is, the program
// computes the new balance by adding the interest and subtracting the
// payment. The program also counts the number of payments made.
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 100.0;
	float interest = 0.05; // 5% interest                                                    
	int numpayments = 0; // we  need to initialize numpayments to 0
	// to count the number of payments made
	if (balance > 0.0) {
		cout << "Balance before payment is: " << balance << endl;
		cout << "Payment is: " << payment << endl;
		cout << "Interest is: " << interest << endl;
		balance += balance * interest; // add interest to balance
		cout << "Balance after interest is: " << balance << endl;
		balance -= payment; // subtract payment from balance
		cout << "Balance after payment is: " << balance << endl;
		numpayments++; // increment the number of payments made
		cout << "Balance after " << numpayments << " payment(s) is: "            
			<< balance << endl;
	}
}
