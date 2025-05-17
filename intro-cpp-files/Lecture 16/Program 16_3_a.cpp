// Program 16_3_a
// Vending Machine class example 1 - one member variable
#include <iostream>
using namespace std;

class vending_machine {
public:
	float price;
	vending_machine(float p = 0.0) : price(p) 
	{ 
	cout << "Vending machine created with price: " << this->price << endl;
	}
};

int main()
{
	vending_machine lobby_machine(8.8);
	vending_machine break_room_machine(9.9);
	vending_machine machine;

	lobby_machine.price = 1.00;
	break_room_machine.price = 2.25;

	cout << "choose a vending machine" << endl;
	cout << "1. lobby machine" << endl;
	cout << "2. break room machine" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Lobby machine price: " << lobby_machine.price << endl;
		cout << "Enter new price for lobby machine: ";
		float new_lobby_price;
		cin >> new_lobby_price;
		lobby_machine.price = new_lobby_price;
		cout << "New lobby machine price: " << lobby_machine.price << endl;
		break;
	case 2:
		cout << "Break room machine price: " << break_room_machine.price << endl;
		cout << "Enter new price for break room machine: ";
		float new_break_room_price;
		cin >> new_break_room_price;
		break_room_machine.price = new_break_room_price;
		cout << "New break room machine price: " << break_room_machine.price << endl;
		break;
	
	default:
		cout << "Invalid choice" << endl;
		cout << "Choose either 1 or 2" << endl;
		break;
	}
}