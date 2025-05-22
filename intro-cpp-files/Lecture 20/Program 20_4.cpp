// Program 20_4
// Not Quite Polymorphism Example
#include<iostream>
#include<string>
using namespace std;

class car {
protected:
	float base_price;
	string model_name;

public:
	car() {
		base_price = 20000.0;
		model_name = "Generic Motor Company";
	}

	car(float price, string name) {
		base_price = price;
		model_name = name;
	}

	void print_info() {
		cout << "The model " << model_name << " costs " << base_price << endl;
	}

	float price() {
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

	void print_info() {
		cout << "The model " << model_name;
		float total_price = base_price;
		if (performance_package) {
			cout << ", with the performance package";
			total_price += 3000.0;
		}
		if (entertainment_package) {
			cout << ", with the entertainment package";
			total_price += 1200.0;
		}
		if (safety_enhancements) {
			cout << ", with safety enhancements";
			total_price += 2100.0;
		}
		cout << " costs " << total_price << endl;
	}

	float price() {
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

int main() {
	car x;
	x.print_info();

	SC300 y(0, 0, 0);
	y.print_info();                   

	SC300 z(1, 1, 1);
	z.print_info();                   
}


// this program demonstrates the use of inheritance and polymorphism in C++.
// The car class is a base class that represents a generic car with a base price and model name.
// The SC300 class is a derived class that represents a specific car model with additional features.
// there are some issues with the code:
// 1. The print_info() method in the SC300 class does not call the base class's print_info() method.
// 2. The price() method in the SC300 class does not override the base class's price() method.
// 3. The main() function creates an instance of the car class and an instance of the SC300 class,