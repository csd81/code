// Program 16_3_b
// Vending Machine class example 2 - several member variables
#include <iostream>
using namespace std;

class vending_machine {
public:
	float price;
	float credit;
	float money_collected;                        
	int inventory;
};

int main()
{
	vending_machine lobby_machine;
	vending_machine break_room_machine;

	lobby_machine.price = 1.00;
	lobby_machine.inventory = 200;
	lobby_machine.credit = 0.0;
	lobby_machine.money_collected = 0.0;                 
}