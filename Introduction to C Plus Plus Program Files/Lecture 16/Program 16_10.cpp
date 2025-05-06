// Program 16_10
// Vending Machine class example 9 - accessor and mutator
#include <iostream>
using namespace std;

class vending_machine {
private:
	float price = 1.0;
	float credit = 0.0;
	float money_collected = 0.0;
	int inventory = 0;

public:
	int number_remaining() {
		return inventory;
	}

	void restock(int new_number) {
		inventory = new_number;
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
	lobby_machine.restock(200);

	cout << "We have " << lobby_machine.number_remaining() << " items in stock." << endl;
	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.60);

	if (lobby_machine.vend()) {
		cout << "We got an item!" << endl;
	}
	else {
		cout << "No item for us." << endl;
	}
	cout << "There are " << lobby_machine.number_remaining() << " items left." << endl;                  
}

// Output: cool