// Program 16_4
// Vending Machine class example 3 - member function
#include <iostream>
#include <string>
using namespace std;

class vending_machine {

	float price;
	float credit;
	float money_collected;
	int inventory;
	string hello;
public:
vending_machine()
	{
		price = 0.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = 0;
		hello = "Hello, welcome to the vending machine!";

		cout << "Vending machine created" << endl;
	}

vending_machine(float p, float c, float mc, int i, string h) :
		price(p), credit(c), money_collected(mc), inventory(i),  hello(h)
	{
		cout << "Vending machine created with price: " << this->price << endl;
		cout << "credit: " << this->credit << endl;
		cout << "money collected: " << this->money_collected << endl;
		cout << "inventory: " << this->inventory << endl;	
	}

~vending_machine()
	{
		cout << "Vending machine destroyed" << endl;
	}
	void print_hello() {
		cout << hello << endl;
	}
};

int main()
{
	vending_machine machine1;
	vending_machine machine2(1.0, 2.0, 3.0, 4, "Szia, üdvözöljük a gépben!");

	machine1.print_hello();                            
	machine2.print_hello();                            
}