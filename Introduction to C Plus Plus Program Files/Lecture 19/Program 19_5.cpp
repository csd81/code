// Program 19_5
// Inheritance Example: Constructors                               
#include<iostream>
#include<string>
using namespace std;

class bank_account {
private:
	string owner_name;
	string owner_address;
	long long int account_number;

protected:
	double balance;

	void set_account(long long int acctnum, double startbalance = 0.0) {
		account_number = acctnum;
		balance = startbalance;
	}

public:
	bank_account() {
		owner_name = "";
		owner_address = "";
		account_number = 0;
		balance = 0.0;
	}

	bank_account(string name, string address, long long int num, double bal) {
		owner_name = name;
		owner_address = address;
		account_number = num;
		balance = bal;
	}

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

	checking_account() : bank_account() {
	}

	checking_account(string name, string address, long long int num, 
		double bal) : bank_account(name, address, num, bal) {
	}


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
	double interest_rate;

public:
	savings_account() : bank_account() {
		interest_rate = 0.0;
	}

	savings_account(string name, string address, long long int num, double bal, 
		double rate) : bank_account(name, address, num, bal) {
		interest_rate = rate;
	}

	void begin_account(long long int num, double amt, double rate) {
		set_account(num, amt);
		interest_rate = rate;
	}

	void generate_interest() {
		balance = balance + interest_rate * balance;
	}
};

int main() {
	checking_account my_checking("John Keyser", "123 Any St., Anytown, TX 77777", 
		11122233, 100.0);
	savings_account my_savings("John Keyser", "123 Any St., Anytown, TX 77777", 
		99988877, 500.0, 0.03);

	my_checking.print_account_info();
	my_savings.print_account_info();                     
}