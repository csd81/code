// Program 16_7
// Vending Machine class example 6 - initializing member variables
#include <iostream>
using namespace std;

class vending_machine {

	float price = 1.0;
	float credit = 0.0;
	float money_collected = 0.0;
	int inventory = 0;

public:
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

// or you can use the constructor to initialize the member variables the following way:
// class vending_machine {
//
// 	float price;
// 	float credit;
// 	float money_collected;
// 	int inventory;
// public:
// 	vending_machine(float p = 1.0, float c = 0.0, float mc = 0.0, int i = 0) :
// 		price(p), credit(c), money_collected(mc), inventory(i) {
// 		cout << "Vending machine created" << endl;
// 	}