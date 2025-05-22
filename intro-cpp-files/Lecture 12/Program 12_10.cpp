// Program 12_10
// Same variable names in different scopes
#include<iostream>                                       
using namespace std;

float calculate_loan(float principal, float payment) {
	float balance = principal - payment;  // Remaining balance of loan after payment
	cout << "Inside the function, the value of the loan balance is: " << balance << endl;
	return balance;
}

int main() {
	float Balance = 100.0;  // Set up a variable to keep track of an account balance
	float loan_principal = 500.0;
	float loan_payment = 25.0;

	// Now use that to pay a loan
	Balance -= loan_payment;
	cout << "Before the function call, the value of the account balance is: " 
		<< Balance << endl;
	loan_principal = calculate_loan(loan_principal, loan_payment);

	cout << "After the function call, the value of the account balance is: " 
		<< Balance << endl; // it is not affected by the function
}

// The program demonstrates the concept of variable scope in C++.
// It defines a function called calculate_loan() that takes two float parameters: principal and payment.
// The function calculates the remaining balance of a loan after a payment is made and outputs the balance.
// The main() function initializes a variable called balance to 100.0 and a loan principal to 500.0.
// It then deducts the loan payment from the balance and calls the calculate_loan() function with the loan principal and payment as arguments.
// After the function call, it outputs the updated balance.
// The program illustrates how variables with the same name can exist in different scopes (local and global) without conflict.
// The balance variable in the main() function is separate from the balance variable in the calculate_loan() function.