// Program 17_7
// Vending Machine division operator
#include <iostream>
using namespace std;

class vending_machine {                                     
private:
	float price;
	float credit;
	float money_collected;

public:
	int inventory;
	vending_machine() {  // default constructor
		price = 1.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = 100;
		cout << "Created a new vending machine." << endl;
	}

	vending_machine(int starting_inventory) { // constructor with one parameter
		price = 1.0;
		credit = 0.0;
		money_collected = 0.0;
		inventory = starting_inventory;
		cout << "Created a new vending machine." << endl;
	}

	vending_machine(float initial_price, int starting_inventory) { // constructor with two parameters
		price = initial_price;
		credit = 0.0;
		money_collected = 0.0;
		inventory = starting_inventory;
		cout << "Created a new vending machine with " << inventory 
			<< " items at a cost of " << price << " each." << endl;
	}

	int number_remaining() { // getter function
		return inventory;
	}

};

vending_machine& operator /(vending_machine& v1, vending_machine& v2) {  // operator overload for division 
	//  pass by reference, so no copy is made and both machines are modified

	//  this function divides the inventory of two vending machines
	//  and returns the first vending machine with the new inventory
	
	//  it takes the inventory of both machines and divides it equally
	//  between the two machines

	// Assumes inventory is public, or this is a friend function
	// a friend function  is a function that is not a member of a class
	int totalinventory = v1.inventory + v2.inventory;
	v1.inventory = totalinventory / 2;  // divide the inventory equally
	v2.inventory = totalinventory - v1.inventory; // assign the remainder to the second machine
	return v1;
}


int main()
{
	vending_machine lobby_machine(50.0, 75); // create a vending machine with 75 items
	vending_machine breakroom_machine(50.0, 100); // create a vending machine with 100 items
	cout << "Before division, the lobby machine has " << lobby_machine.inventory << endl;
	cout << "Before division, the breakroom machine has " << breakroom_machine.inventory 
		<< endl;
	vending_machine v3 = lobby_machine / breakroom_machine; // create a new vending machine
	//  by dividing the two machines
	//  this will modify the inventory of both machines
	cout << "After division, the lobby machine has " << lobby_machine.inventory << endl;
	cout << "After division, the breakroom machine has " << breakroom_machine.inventory 
		<< endl;         
	cout << "v3 has " << v3.inventory << endl; // print the inventory of the new machine   
}                        

//creating a new machin is not necessary
//  but it is a good way to test the operator overload


// the return type of the operator overload can also be void
//  but this is not recommended
//  because it can lead to confusion
//  and it is not clear what the function does
//  it is better to return a new object
//  or a reference to an existing object
//  this way the function is clear and easy to understand