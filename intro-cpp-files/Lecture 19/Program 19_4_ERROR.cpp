// Program 19_4_ERROR
// Inheritance Example: Public/Protected/Private - with ERRORS
#include<iostream>
#include<string>
using namespace std;

class bank_account {
private:
	string owner_name;
	string owner_address;
	

protected:
	double balance;
	long long int account_number;

	void set_account(long long int acctnum, double startbalance = 0.0) {
		account_number = acctnum;
		balance = startbalance;
	}


public:
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
	void set_balance(double amt) {
		balance = amt;
	}
	double get_balance() {
		return balance;
	}	
};

class checking_account : public bank_account {
public:
	void begin_account(long long int num, double amt) {
		account_number = num;
		balance = amt;
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
	checking_account my_checking;
	savings_account my_savings;
	my_checking.begin_account(11122233, 100.0);
	my_checking.update_owner("John Keyser", "123 Any St., Anytown, TX 77777");
	my_checking.deposit(50.0);
	my_checking.withdraw(25.0);
	my_checking.print_account_info();

	my_savings.begin_account(11112223311122233, 10.0, 0.15);
	my_savings.set_balance(50.0);
	my_savings.update_owner("John Keyser", "123 Any St., Anytown, TX 77777");
	
	for (int i = 0; i < 60; i++) {
		my_savings.generate_interest();
	}
	my_savings.generate_interest();

	my_savings.update_owner("MYNAME", "MYADDRESS"); //
	my_savings.print_account_info();                             

	cout<< "Haha, I am richer than you!" << endl;
}