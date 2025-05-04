// Program 16_7
// Vending Machine class example 6 - initializing member variables
#include <iostream>
using namespace std;

class vending_machine {
public:
	float price = 1.0;
	float credit = 0.0;
	float money_collected = 0.0;
	int inventory = 0;

	int number_remaining() {
		return inventory;
	}

	void deposit_money(float amount) {
		credit += amount;
		cout << "Current credit is " << credit << endl;
	}
};

int main()
{
	vending_machine lobby_machine;

	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.10);                         
}