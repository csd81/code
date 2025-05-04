// Program 19_6
// Everything Wrists store example
#include <iostream>
#include <string>
using namespace std;

class accessory {
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
};

class rubber_wristband : public accessory {
public:
	string color;
	string message;

	// Default constructor
	rubber_wristband() : accessory() {
		color = "";
		message = "";
	}

	// Non-default constructor
	rubber_wristband(float c, float p, string col, string mess) : accessory(c, p) {
		color = col;
		message = mess;
	}
};

int main()
{
	rubber_wristband birthday_band(0.20, 2.00, "Yellow", "It's My Birthday!");
	rubber_wristband bridges_band(0.20, 0.50, "Black",
		"Support Bridges - your life depends on them!");              
}