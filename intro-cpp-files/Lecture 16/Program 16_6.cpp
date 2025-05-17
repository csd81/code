// Program 16_6
// Vending Machine class example 5 - multiple member functions
#include <iostream>
using namespace std;

class vending_machine {

	float price;
	float credit;
	float money_collected;
	int inventory;
public:
	vending_machine() : price(0),  credit(0), money_collected(0), inventory(0) {
		cout << "Vending machine created" << endl;
	}
	~vending_machine() {
		cout << "Vending machine destroyed" << endl;
	}
	
	int number_remaining() {
		return inventory;
	}

	void deposit_money(float amount) {
		credit += amount;
		cout << "Current credit is " << credit << endl;
	}

	float get_credit() {
		return credit;
	}
};

int main()
{
	vending_machine lobby_machine;
	

	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.25);
	lobby_machine.deposit_money(0.10);                       

	cout << "Current credit is " << lobby_machine.get_credit() << endl; // 0.60
	
}