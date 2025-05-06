// Program 19_4
// Inheritance Example: Public/Protected/Private
#include<iostream>
#include<string>
using namespace std;

class bank_account {

private: // Private members are not accessible outside the class
	string owner_name;  
	string owner_address;
	long long int account_number;  // long long int is used for large account numbers

protected:	

	double balance; // Protected members are accessible in derived classes

	void set_account(long long int acctnum, double startbalance = 0.0) {
		account_number = acctnum;
		balance = startbalance;
	}

public: 			// Public members are accessible from outside the class
	
	void update_owner(string name, string address) {
		owner_name = name;
		owner_address = address;
	}

	void print_account_info() {
		cout << "Account: " << account_number << endl;
		cout << "Current Balance : " << balance << endl;
		cout << "Owner: " << owner_name << endl;
		cout << "Address: " << owner_address << endl;
	}
};

class checking_account : public bank_account {
public:
	void begin_account(long long int num, double amt) {
		set_account(num, amt);
	}

	void deposit(double amt) {
		balance += amt;
	}

	double withdraw(double amt) {
		if (balance >= amt) {
			balance -= amt;
			return amt;
		}
		else {
			return 0;
		}
	}
};

class savings_account : public bank_account {
private:
	double interest_rate;

public:
	void begin_account(long long int num, double amt, double rate) {
		set_account(num, amt);
		interest_rate = rate;
	}

	void generate_interest() {
		balance = balance + interest_rate * balance;
	}
};

int main() {
	checking_account Holmes_checking;
	savings_account Holmes_savings;
	Holmes_checking.begin_account(11122233, 100.0);
	Holmes_checking.update_owner("Sherlock Holmes", "221B Baker St., London");
	Holmes_savings.begin_account(99988877, 500.0, 0.03);
	Holmes_savings.update_owner("Sherlock Holmes", "221B Baker St., London");

	Holmes_checking.deposit(50.0);
	Holmes_checking.withdraw(25.0);
	
	for (int i = 0; i < 100; i++) {
		Holmes_savings.generate_interest();
	}
		
	Holmes_savings.update_owner("my name", "my address"); // 
	

	Holmes_checking.print_account_info();
	cout << "I stole this money from Sherlock Holmes!" << endl;
	Holmes_savings.print_account_info();              
}

// Public/Protected/Private are access specifiers in C++ that control the visibility of class members.
// Public members are accessible from outside the class.
// Protected members are accessible in derived classes but not from outside the class.
// Private members are only accessible within the class itself. 