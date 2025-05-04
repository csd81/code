// Program 17_7
// Vending Machine division operator
#include <iostream>
using namespace std;

class vending_machine {                                     
private:
	float price;
	float credit;
	float money_collected;

public:
	int inventory;
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

vending_machine& operator /(vending_machine& v1, vending_machine& v2) {
	// Assumes inventory is public, or this is a friend function
	int totalinventory = v1.inventory + v2.inventory;
	v1.inventory = totalinventory / 2;
	v2.inventory = totalinventory - v1.inventory;
	return v1;
}


int main()
{
	vending_machine lobby_machine(50.0, 75);
	vending_machine breakroom_machine(50.0, 100);
	cout << "Before division, the lobby machine has " << lobby_machine.inventory << endl;
	cout << "Before division, the breakroom machine has " << breakroom_machine.inventory 
		<< endl;
	vending_machine v3 = lobby_machine / breakroom_machine;
	cout << "After division, the lobby machine has " << lobby_machine.inventory << endl;
	cout << "After division, the breakroom machine has " << breakroom_machine.inventory 
		<< endl;            
}                        