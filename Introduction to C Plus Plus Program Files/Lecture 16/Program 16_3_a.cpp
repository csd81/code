// Program 16_3_a
// Vending Machine class example 1 - one member variable
#include <iostream>
using namespace std;

class vending_machine {
public:
	float price;
};

int main()
{
	vending_machine lobby_machine;
	vending_machine break_room_machine;

	lobby_machine.price = 1.00;
	break_room_machine.price = 2.25;

	cout << "The prices are: " << lobby_machine.price << " and " 
		<< break_room_machine.price << endl;                       
}