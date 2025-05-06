// Program 16_3_b
// Vending Machine class example 2 - several member variables
#include <iostream>
using namespace std;

class vending_machine {
	float price; // price of the item (float)
	float credit; // credit in the machine (float)
	float money_collected; // money collected by the machine (float)
	int inventory; // number of items in the machine (int)
public:
	vending_machine(float p = 0.0, float c = 0.0, float mc = 0.0, int i = 0) :
		price(p), credit(c), money_collected(mc), inventory(i)
	 { 	cout << "Vending machine created." << endl; 
		cout << "price: " << this->price << endl; 
		cout << "credit: " << this->credit << endl;
		cout << "money collected: " << this->money_collected << endl;
		cout << "inventory: " << this->inventory << endl;
	}
	 ~vending_machine() { cout << "Vending machine destroyed" << endl; }

	void set_price(float p) { price = p; }
	void set_credit(float c) { credit = c; }
	void set_money_collected(float mc) { money_collected = mc; }
	void set_inventory(int i) { inventory = i; }
	
	float get_price() { return price; }
	float get_credit() { return credit; }
	float get_money_collected() { return money_collected; }
	int get_inventory() { return inventory; }2
};
void show_vending_machine(vending_machine& vm)
{
	cout << "Vending machine details:" << endl;
	cout << "Price: " << vm.get_price() << endl;
	cout << "Credit: " << vm.get_credit() << endl;
	cout << "Money collected: " << vm.get_money_collected() << endl;
	cout << "Inventory: " << vm.get_inventory() << endl;
	cout << endl;
}

int main()
{
	vending_machine lobby_machine(1,2,3,4);
	vending_machine machine(1,2,3,4);

	lobby_machine.set_price(1.00);
	lobby_machine.set_inventory(200);
	lobby_machine.set_credit(10.0);
	lobby_machine.set_money_collected(0.0);

	cout << "choose a vending machine" << endl;
	cout << "1. lobby machine" << endl;
	cout << "2. break room machine" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
		case 1:
			show_vending_machine(lobby_machine);
			break;
		case 2:
			show_vending_machine(machine);
			break;
		default:
			cout << "Invalid choice" << endl;
			cout << "Choose either 1 or 2" << endl;
			break;
	}


}