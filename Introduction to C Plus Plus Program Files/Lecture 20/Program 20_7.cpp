// Program 20_7
// Polymorphism Example - passing by value rather than by reference
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

	virtual void print_info() {
		cout << "The model " << model_name << " costs " << base_price << endl;
	}

	virtual float price() {
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

int main() {
	car x;
	print_car(x);
	SC300 y(true, false, true);
	print_car(y);                   
}