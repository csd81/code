// Program 20_6
// Polymorphism Example - no more virtual functions in base class
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
		model_name = "Generic1";
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

void print_car(car& c) {  
	c.print_info();
}
void print_car(SC300& c) { 
	c.print_info();
}

int main() {
	car x;
	print_car(x);
	SC300 y(true, false, true);
	print_car(y);                 
}

// The output of this program is:
// The model Generic1 costs 20000
// but the base class car does not have a virtual function
// so the derived class SC300 does not override the base class function
// print_car() takes a reference to a car object, but since the derived class SC300
// does not override the base class function, it will call the base class function
// print_info() instead of the derived class function.
// The model SC300, with the performance package, with safety enhancements costs 35000, so the derived class function does not get called.
// this is not polymorphism, but rather a function call to the base class function.
// we can fix this by making the base class function virtual, but that is not the point of this example.
// The point of this example is to show that we can have polymorphism without virtual functions in the base class.

// if we overload the print_car function for the derived class SC300, we can call the derived class function
// and get the correct output.

// the difference between overloading and overriding is that overloading is when we have two functions with the same name
// but different parameters, while overriding is when we have a derived class function with the same name as the base class function.
// in this case, we have overloaded the print_car function for the derived class SC300	