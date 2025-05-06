// Program 17_1
// Vending Machine class example
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
		price = 0.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = 100;
		cout << "Created a new vending machine." << endl;
	}
	~vending_machine() {
		cout << "Destroying vending machine." << endl;
	}

	int number_remaining() {
		return inventory;
	}
	void set_inventory(int num) {
		if (num >= 0) {
			inventory = num;
		}
		else {
			cout << "Invalid inventory amount." << endl;
		}
	}

};

int main()
{
	vending_machine lobby_machine;

	cout << "There are " << lobby_machine.number_remaining() << " items." << endl;         

	lobby_machine.set_inventory(50);
	cout << "Now, there are " << lobby_machine.number_remaining() << " items." << endl;         
}

// this program demonstrates the use of a class to model a vending machine.
// The class has private data members to store the price of the item, the amount of credit
// in the machine, the amount of money collected, and the number of items in the inventory.

// The class has a constructor that initializes these values and a public member function
// that returns the number of items remaining in the inventory. The main function creates
// an instance of the vending machine class and calls the number_remaining function to
// display the number of items remaining in the machine. The program demonstrates the use
// of encapsulation and abstraction in object-oriented programming by hiding the implementation
// details of the vending machine and providing a simple interface for interacting with it.