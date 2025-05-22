// Program 16_8
// Vending Machine class example 7 - vending an item
#include <iostream>
using namespace std;

class vending_machine {

	float price ;
	float credit ;
	float money_collected ;
	int inventory ;
public:
	vending_machine() {
		price = 1.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = 0;
		
	cout << "Vending machine created" << endl;
	}
	~vending_machine() {
		cout << "Vending machine destroyed" << endl;
	}
	void set_price(float p) { price = p; }
	void set_credit(float c) { credit = c;	}
	void set_money_collected(float mc) { money_collected = mc; }
	void set_inventory(int i) { inventory = i; }

	float get_money_collected() { return money_collected; }
	float get_price() { return price; }
	float get_credit() { return credit; }
	int get_inventory() { return inventory; }

	int number_remaining() { 		return inventory; 	}

	void deposit_money(float amount) { 		credit += amount; 		cout << "Current credit is " << credit << endl; 	}
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