// Program 16_5
// Vending Machine class example 4 - alternative member function
#include <iostream>
using namespace std;

class vending_machine {
public:
	float price;
	float credit;
	float money_collected;
	int inventory;

	int number_remaining() {
		return inventory;
	}
};

int main()
{
	vending_machine lobby_machine;
	lobby_machine.inventory = 250;

	cout << lobby_machine.number_remaining() << " items remain in the machine." << endl;             
}