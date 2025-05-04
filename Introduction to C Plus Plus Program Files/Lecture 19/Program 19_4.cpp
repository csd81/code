// Program 19_4
// Inheritance Example: Public/Protected/Private
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
	Holmes_savings.generate_interest();

	Holmes_checking.print_account_info();
	Holmes_savings.print_account_info();              
}