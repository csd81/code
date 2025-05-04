// Program 17_3
// Vending Machine non-default constructor
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

	int number_remaining() {
		return inventory;
	}

};

int main()
{
	vending_machine lobby_machine(50);

	cout << "There are " << lobby_machine.number_remaining() << " items." << endl;                                    
}