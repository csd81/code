// Program 5_6
// INFINITE loop for computing balance - payment is less than interest,       
//so goes on forever
// this is a logic error
// The program demonstrates an infinite loop due to a logic error.
// The program computes the balance of a bank account after multiple payments and interest charges.
// The program uses a while loop to repeatedly compute the balance until it is less than or equal to 0.0.
// However, the payment amount is set to a value that is less than the interest charged on the balance.
// This causes the balance to never reach 0.0, resulting in an infinite loop.
// If we want to break out of the loop, we have to press Ctrl+C to terminate the program.
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;
	float payment = 1.0;  // Notice: payment is too small
	float interest = 0.05;
	int numpayments = 0;
	
	while (balance > 0.0) {    // this condition is always true
		balance += balance * interest;
		balance -= payment;
		numpayments++;
		cout << "Balance after " << numpayments << " payment(s) is: " 
			<< balance << endl;
	}                                     
}