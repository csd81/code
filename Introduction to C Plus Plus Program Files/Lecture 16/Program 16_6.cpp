// Program 16_6
// Vending Machine class example 5 - multiple member functions
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

	void deposit_money(float amount) {
		credit += amount;
		cout << "Current credit is " << credit << endl;
	}
};

int main()
{
	vending_machine lobby_machine;
	lobby_machine.credit = 0.0;

	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.10);                       
}