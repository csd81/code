// Program 19_6
// Everything Wrists store example
#include <iostream>
#include <string>
using namespace std;

class accessory { // Base class
public:
	float cost;
	float sale_price;

	// Default constructor
	accessory() {
		cost = 0.0;
		sale_price = 0.0;
	}

	// Non-default constructor
	accessory(float c, float p) {
		cost = c;
		sale_price = p;
	}
	float profit_per_unit() { 
		return sale_price - cost;  // This function calculates the profit per unit
	}
};

class rubber_wristband : public accessory { // Derived class
public:
	string color;
	string message;

	// Default constructor
	rubber_wristband() : accessory() {
		color = "";
		message = "";
	}

	// Non-default constructor
	rubber_wristband(float c, float p, string col, string mess) 
	: accessory(c, p) 
	{
		color = col;
		message = mess;
	}
};

int main()
{
	rubber_wristband birthday_band(0.20, 2.00, "Yellow", "It's My Birthday!");  // this is more profitable
	rubber_wristband bridges_band(0.20, 0.50,  "Black",  "Support Bridges - your life depends on them!");              

	cout << "The birthday band costs " << birthday_band.cost
		<< " to purchase and sells for " << birthday_band.sale_price << endl;
	cout << "We make a profit of " << birthday_band.profit_per_unit() 
		<< " on each one." << endl;
	
	cout << "The bridges band costs " << bridges_band.cost
		<< " to purchase and sells for " << bridges_band.sale_price << endl;
	cout << "We make a profit of " << bridges_band.profit_per_unit()
		<< " on each one." << endl;
	
}

// this program demonstrates inheritance in C++
// it creates a base class accessory and a derived class rubber_wristband
// the rubber_wristband class inherits from the accessory class
