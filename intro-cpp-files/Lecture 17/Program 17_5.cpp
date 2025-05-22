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
		cout << "Created a basic vending machine." << endl;
	}

	vending_machine(int starting_inventory) {
		price = 1.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = starting_inventory;
		cout << "Created a new vending machine with " << inventory 
			<< " items." << endl;
	}

	vending_machine(float initial_price, int starting_inventory) {
		price = initial_price;
		credit = 0.0;
		money_collected = 0.0;
		inventory = starting_inventory;
		cout << "Created a new vending machine with " << inventory 
			<< " items at a cost of " << price << " each." << endl;
	}

	~vending_machine() {
		cout << "Vending machine destroyed." << endl;
	}

	int number_remaining() {
		return inventory;
	}

	float get_price() {
		return price;
	}

};

int main()
{	
	vending_machine machine;
	vending_machine Inv_machine(15);                             
	vending_machine priceInv_machine(50.0, 75);                             
	cout << "There are " << machine.number_remaining() << " items in the basic machine." << endl;
	cout << "The basic machine's items have a price of " << machine.get_price() << endl;

	cout << "There are " << Inv_machine.number_remaining() << " items in the first machine." << endl;
	cout << "The first machine's items have a price of " << Inv_machine.get_price() << endl;

	cout << "There are " << priceInv_machine.number_remaining() << " items in the second machine." << endl;
	cout << "The second machine's items have a price of " << priceInv_machine.get_price() << endl;
	
}