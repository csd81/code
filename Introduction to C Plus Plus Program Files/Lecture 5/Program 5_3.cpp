// Program 5_3
// While loop for computing balance
// The while loop is a control flow statement that allows code to be executed repeatedly based on a given boolean condition.
// The while loop is used to execute a block of code as long as the specified condition is true.
// In this case, the while loop is used to compute the balance of a bank account after multiple payments and interest charges.
// The program also counts the number of payments made.
#include <iostream>
using namespace std;

int main() {
	float balance = 1000.0;                                              
	float payment = 100.0;
	float interest = 0.05;
	int numpayments = 0;
	while (balance > 0.0) {
		cout << "Balance before payment is: " << balance <<  " ";
		cout << "Payment is: " << payment << " ";
		cout << "Interest is: " << interest << endl;
		balance += balance * interest;
		balance -= payment;                                               
		numpayments++;
		cout << "Balance after " << numpayments << " payment(s) is: " 
			<< balance << endl;
	}
}