// Program 16_4
// Vending Machine class example 3 - member function
#include <iostream>
using namespace std;

class vending_machine {
public:
	float price;
	float credit;
	float money_collected;
	int inventory;

	void print_hello() {
		cout << "Hello" << endl;
	}
};

int main()
{
	vending_machine lobby_machine;

	lobby_machine.print_hello();                            
}