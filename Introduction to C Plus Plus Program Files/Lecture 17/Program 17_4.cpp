// Program 17_4
// Vending Machine constructor having variable argument
#include<iostream>                                         
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
	cout << "How many items does  the first machine start wtih? ";
	int init_number;
	cin >> init_number;
	vending_machine first_machine(init_number);
	cout << "There are " << first_machine.number_remaining() << " items in the first machine." << endl;                

	cout << "How many items does  the 2nd machine start wtih? ";
	cin >> init_number;
	vending_machine second_machine(init_number);
	cout << "There are " << second_machine.number_remaining() << " items in the 2nd machine." << endl;                
}