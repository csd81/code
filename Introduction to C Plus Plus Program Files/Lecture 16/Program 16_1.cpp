// Program 16_1
// Very basic class example
#include <iostream>
using namespace std;

class vending_machine {
private:
	int soda_count;
	int candy_count;
	int chips_count;
	int gum_count;
	int soda_price;
	int candy_price;
	int chips_price;
	int gum_price;
public:
	//More stuff here
	vending_machine(int s, int c, int ch, int g, int sp, int cp, int chp, int gp) :
		soda_count(s), candy_count(c), chips_count(ch), gum_count(g),
		soda_price(sp), candy_price(cp), chips_price(chp), gum_price(gp) {
		cout << "Vending machine created" << endl;
	}
	~vending_machine() {
		cout << "Vending machine destroyed" << endl;
	}
	void set_soda_count(int count) {
		soda_count = count;
	}
	void set_candy_count(int count) {
		candy_count = count;
	}
	void set_chips_count(int count) {
		chips_count = count;
	}
	void set_gum_count(int count) {
		gum_count = count;
	}
	void set_soda_price(int price) {
		soda_price = price;
	}
	void set_candy_price(int price) {
		candy_price = price;
	}
	void set_chips_price(int price) {
		chips_price = price;
	}
	void set_gum_price(int price) {
		gum_price = price;
	}
	int get_soda_count() {
		return soda_count;
	}
	int get_candy_count() {
		return candy_count;
	}
	int get_chips_count() {
		return chips_count;
	}
	int get_gum_count() {
		return gum_count;
	}
	int get_soda_price() {
		return soda_price;
	}
	int get_candy_price() {
		return candy_price;
	}
	int get_chips_price() {
		return chips_price;
	}
	int get_gum_price() {
		return gum_price;
	}
	void dispense_soda() {
		if (soda_count > 0) {
			soda_count--;
			cout << "Dispensing soda" << endl;
			cout << "Number of soda left: " << soda_count << endl;
		}
		else {
			cout << "Out of soda" << endl;
			cout << "Call the vending machine technician" << endl;
		}
	}
	void dispense_candy() {
		if (candy_count > 0) {
			candy_count--;
			cout << "Dispensing candy" << endl;
			cout << "Number of candy left: " << candy_count << endl;
		}
		else {
			cout << "Out of candy" << endl;
			cout << "Call the vending machine technician" << endl;
		}
	}
	void dispense_chips() {
		if (chips_count > 0) {
			chips_count--;
			cout << "Dispensing chips" << endl;
			cout << "Number of chips left: " << chips_count << endl;
		}
		else {
			cout << "Out of chips" << endl;
			cout << "Call the vending machine technician" << endl;
				}
	}
	void dispense_gum() {
		if (gum_count > 0) {
			gum_count--;
			cout << "Dispensing gum" << endl;
			cout << "Number of gum pieces left: " << gum_count << endl;
		}
		else {
			cout << "Out of gum" << endl;
			cout << "Call the vending machine technician" << endl;
		}
	}
};

int main()
{
	// Create a vending machine object with initial values using the constructor
	vending_machine lobby_soda_machine(1,2,3,4,5,6,7,8);
	// Display the initial values of the vending machine
	cout << "Soda count: " << lobby_soda_machine.get_soda_count() << endl;
	cout << "Candy count: " << lobby_soda_machine.get_candy_count() << endl;
	cout << "Chips count: " << lobby_soda_machine.get_chips_count() << endl;
	cout << "Gum count: " << lobby_soda_machine.get_gum_count() << endl;
	cout << "Soda price: " << lobby_soda_machine.get_soda_price() << endl;
	cout << "Candy price: " << lobby_soda_machine.get_candy_price() << endl;
	cout << "Chips price: " << lobby_soda_machine.get_chips_price() << endl;
	cout << "Gum price: " << lobby_soda_machine.get_gum_price() << endl;

	
// Set new values of the vending machine
	lobby_soda_machine.set_soda_count(10);
	lobby_soda_machine.set_candy_count(9);	
	lobby_soda_machine.set_chips_count(7);
	lobby_soda_machine.set_gum_count(8);
	lobby_soda_machine.set_soda_price(1);
	lobby_soda_machine.set_candy_price(2);
	lobby_soda_machine.set_chips_price(3);
	lobby_soda_machine.set_gum_price(4);
	// Display the new values of the vending machine
	cout << "values after setting new values" << endl;
	cout << "Soda count: " << lobby_soda_machine.get_soda_count() << endl;
	cout << "Candy count: " << lobby_soda_machine.get_candy_count() << endl;
	cout << "Chips count: " << lobby_soda_machine.get_chips_count() << endl;
	cout << "Gum count: " << lobby_soda_machine.get_gum_count() << endl;
	cout << "Soda price: " << lobby_soda_machine.get_soda_price() << endl;
	cout << "Candy price: " << lobby_soda_machine.get_candy_price() << endl;
	cout << "Chips price: " << lobby_soda_machine.get_chips_price() << endl;
	cout << "Gum price: " << lobby_soda_machine.get_gum_price() << endl;
	cout << "Dispensing soda" << endl;
	while (lobby_soda_machine.get_soda_count() > 0) {
		lobby_soda_machine.dispense_soda();
		cout << "Soda count: " << lobby_soda_machine.get_soda_count() << endl;
	}
	do {
		lobby_soda_machine.dispense_candy();
		cout << "Candy count: " << lobby_soda_machine.get_candy_count() << endl;
	} while (lobby_soda_machine.get_candy_count() > 0);

	for (int i = lobby_soda_machine.get_chips_count(); i < 0; i--) {
		lobby_soda_machine.dispense_chips();
		cout << "Chips count: " << lobby_soda_machine.get_chips_count() << endl;
	}
	

	// Create another vending machine object with initial values using the constructor
	vending_machine street_soda_machine(1,2,3,4,5,6,7,8);
	// Display the initial values of the vending machine
	cout << "Soda count: " << street_soda_machine.get_soda_count() << endl;
	cout << "Candy count: " << street_soda_machine.get_candy_count() << endl;
	cout << "Chips count: " << street_soda_machine.get_chips_count() << endl;
	cout << "Gum count: " << street_soda_machine.get_gum_count() << endl;
	cout << "Soda price: " << street_soda_machine.get_soda_price() << endl;
	cout << "Candy price: " << street_soda_machine.get_candy_price() << endl;
	cout << "Chips price: " << street_soda_machine.get_chips_price() << endl;
	cout << "Gum price: " << street_soda_machine.get_gum_price() << endl;

	cout << "Which item's price do you want to change?" << endl;
	cout << "1. Soda" << endl;
	cout << "2. Candy" << endl;
	cout << "3. Chips" << endl;
	cout << "4. Gum" << endl;
	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Soda price: " << street_soda_machine.get_soda_price() << endl;
		cout << "Enter new price for soda: ";
		int new_soda_price;
		cin >> new_soda_price;
		street_soda_machine.set_soda_price(new_soda_price);
		cout << "New soda price: " << street_soda_machine.get_soda_price() << endl;
		break;
	case 2:
		cout << "Candy price: " << street_soda_machine.get_candy_price() << endl;
		cout << "Enter new price for candy: ";
		int new_candy_price;
		cin >> new_candy_price;
		street_soda_machine.set_candy_price(new_candy_price);
		cout << "New candy price: " << street_soda_machine.get_candy_price() << endl;
		break;
	case 3:
		cout << "Chips price: " << street_soda_machine.get_chips_price() << endl;
		cout << "Enter new price for chips: ";
		int new_chips_price;
		cin >> new_chips_price;
		street_soda_machine.set_chips_price(new_chips_price);
		cout << "New chips price: " << street_soda_machine.get_chips_price() << endl;
		break;
	case 4:
		cout << "Gum price: " << street_soda_machine.get_gum_price() << endl;
		cout << "Enter new price for gum: ";
		int new_gum_price;
		cin >> new_gum_price;
		street_soda_machine.set_gum_price(new_gum_price);
		cout << "New gum price: " << street_soda_machine.get_gum_price() << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}

	cout << "Which item do you want to dispense?" << endl;
	cout << "1. Soda" << endl;
	cout << "2. Candy" << endl;
	cout << "3. Chips" << endl;
	cout << "4. Gum" << endl;
	int item_choice;
	cin >> item_choice;
	switch (item_choice) {
	case 1:
		cout << "Dispensing soda" << endl;
		street_soda_machine.dispense_soda();
		break;
	case 2:
		cout << "Dispensing candy" << endl;
		street_soda_machine.dispense_candy();
		break;
	case 3:
		cout << "Dispensing chips" << endl;
		street_soda_machine.dispense_chips();
		break;
	case 4:
		cout << "Dispensing gum" << endl;
		street_soda_machine.dispense_gum();
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}
	// for all objects of the class,  before the program ends, the destructor is called automatically
	// and the message "Vending machine destroyed" is displayed

	// we have created two objects of the class vending_machine
	// the destructor is called for both objects
	
	return 0;
}

// 
// 
// classes in C++ are similar to classes in Java 
// a class is a user-defined data type that can contain data members and member functions
// a class is a blueprint for creating objects
// an object is an instance of a class
// a class can contain data members (variables) and member functions (methods)
// a class can also contain constructors and destructors
// a constructor is a special member function that is called when an object of the class is created
// a destructor is a special member function that is called when an object of the class is destroyed
// a constructor has the same name as the class and does not have a return type
// a destructor has the same name as the class but with a tilde (~) before it and does not have a return type
// a constructor can be overloaded
// a destructor cannot be overloaded
// a constructor can have default arguments
// a destructor cannot have default arguments
//  private, protected, public are access specifiers
//  private members can only be accessed by member functions of the class
//  protected members can be accessed by member functions of the class and by derived classes
//  public members can be accessed by any function


