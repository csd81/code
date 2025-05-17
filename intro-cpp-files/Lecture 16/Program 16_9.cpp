// Program 16_9
// Vending Machine class example 8 - public and private members
#include <iostream>
using namespace std;

class vending_machine {
private:
	float price = 1.0;
	float credit = 0.0;
	float money_collected = 0.0;
	int inventory = 0;

public:              
	vending_machine() {
		cout << "Vending machine created" << endl;
	}
	~vending_machine() {
		cout << "Vending machine destroyed" << endl;
	}                             
	void set_inventory(int num_items) {
		if (num_items >= 0) {
			inventory = num_items;
		}
		else {
			cout << "Invalid inventory amount" << endl; // can't be negative
		}
	}

	int number_remaining() {
		return inventory;
	}

	void deposit_money(float amount) {
		credit += amount;
		cout << "Current credit is " << credit << endl;
	}

	float return_change() {
		float amt_to_return;
		amt_to_return = credit;
		credit = 0;
		cout << "Returning " << amt_to_return << " in change." << endl;
		return amt_to_return;
	}

	bool vend() {
		if (credit < price) {
			cout << "Please deposit more money" << endl;
			return false;
		}
		else if (inventory <= 0) {
			cout << "Sold Out." << endl;
			return false;
		}
		else {
			credit -= price;
			money_collected += price;
			cout << "Vending an item" << endl;
			inventory--;
			return_change();
			return true;
		}
	}
};

int main()
{
	vending_machine lobby_machine;
	lobby_machine.set_inventory(200);

	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.60);

	if (lobby_machine.vend()) {
		cout << "We got an item!" << endl;
	}
	else {
		cout << "No item for us." << endl;
	}                                    
}