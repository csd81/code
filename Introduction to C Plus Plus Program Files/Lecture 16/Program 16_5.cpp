// Program 16_5
// Vending Machine class example 4 - alternative member function
#include <iostream>
using namespace std;

class vending_machine {

	float price;
	float credit;
	float money_collected;
	int inventory;
public:
	int get_inventory() {
		return inventory;
	}
	void set_inventory(int i) {
		inventory = i;
	}
};

int main()
{
	vending_machine lobby_machine;
	lobby_machine.set_inventory(250);

	cout << lobby_machine.get_inventory() << " items remain in the machine." << endl;             
}