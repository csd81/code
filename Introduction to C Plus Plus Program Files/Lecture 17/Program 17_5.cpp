// Program 17_5
// Vending Machine constructor with multiple parameters
#include <iostream>
using namespace std;

class vending_machine {
private:
	float price;
	float credit;
	float money_collected;
	int inventory;

public:
	vending_machine() {
		price = 1.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = 100;
		cout << "Created a new vending machine." << endl;
	}

	vending_machine(int starting_inventory) {
		price = 1.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = starting_inventory;
		cout << "Created a new vending machine." << endl;
	}

	vending_machine(float initial_price, int starting_inventory) {
		price = initial_price;
		credit = 0.0;
		money_collected = 0.0;
		inventory = starting_inventory;
		cout << "Created a new vending machine with " << inventory 
			<< " items at a cost of " << price << " each." << endl;
	}

	int number_remaining() {
		return inventory;
	}

};

int main()
{
	vending_machine lobby_machine(50.0, 75);                             
}