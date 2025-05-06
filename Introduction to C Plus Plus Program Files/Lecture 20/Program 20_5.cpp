// Program 20_5
// Polymorphism Example
#include<iostream>
#include<string>
using namespace std;

class car {
protected:
	float base_price;
	string model_name;

public:
	car() {  // Default constructor
		base_price = 20000.0;
		model_name = "Generic1";
	}

	car(float price, string name) { // Parameterized constructor
		base_price = price;
		model_name = name;
	}

	virtual void print_info() {  									// Virtual function, not pure
		cout << "The model " << model_name << " costs " << base_price << endl;
	}

	virtual float price() { 										// Virtual function, not pure
		return base_price;
	}
};

class SC300 : public car {
protected:
	bool performance_package;
	bool entertainment_package;
	bool safety_enhancements;

public:
	SC300(bool p, bool e, bool s) : car(35000.0, "SC300") {
		performance_package = p;
		entertainment_package = e;
		safety_enhancements = s;
	}

	void print_info() override {  // overrides the base class print_info function  which is a virtual function
		cout << "The model " << model_name;
		float total_price = base_price; //  local variable, initialized to base price
		if (performance_package) {
			cout << ", with the performance package";
			total_price += 3000.0;  // add to total price if true
		}
		if (entertainment_package) {
			cout << ", with the entertainment package";
			total_price += 1200.0; // add to total price if true
		}
		if (safety_enhancements) { 
			cout << ", with safety enhancements";
			total_price += 2100.0; // add to total price if true
		}
		cout << " costs " << total_price << endl;
	}

	float price() override { // overrides the base class price function which is a virtual function
		float total_price = base_price;
		if (performance_package) {
			total_price += 3000.0;
		}
		if (entertainment_package) {
			total_price += 1200.0;
		}
		if (safety_enhancements) {
			total_price += 2100.0;
		}
		return total_price;
	}
};

void print_car(car& c) {  // function that takes a reference to a car object
	c.print_info();  // call the print_info method of the car object or derived class depending on the object passed
}

int main() {
	car x;
	print_car(x);
	SC300 y(true, false, true);
	print_car(y);              
}

// this program demonstrates polymorphism in C++ by using virtual functions.
// The car class has a virtual function print_info() that is overridden in the SC300 class.
// The print_car function takes a reference to a car object and calls the print_info() method.
// This allows for dynamic binding, where the correct print_info() method is called based on the actual object type at runtime.
// virtual functions allow derived classes to provide their own implementation of a function defined in the base class.

// pure virtual functions are declared by assigning 0 to the function in the base class.
// this makes the base class abstract, meaning it cannot be instantiated directly.
// if all functions in a class are pure virtual functions, the class is considered an abstract class aka interface.

// dynamic binding occurs when the function to be called is determined at runtime based on the actual object type.
// this allows for more flexible and extensible code, as new derived classes can be added without modifying existing code.