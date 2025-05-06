// Program 20_8
// Pure virtual function
#include<iostream>
using namespace std;

class shipping_company {
public:
	virtual float shipping_cost(float) = 0;            // pure virtual function, which is marked by = 0
};

class VQT : public shipping_company { // VQT is a derived class of shipping_company
public:
	float shipping_cost(float weight) override { // overrides the pure virtual function
		return 3.0 + 1.5 * weight;
	}
};

class NatFast : public shipping_company { // NatFast is a derived class of shipping_company
public:
	float shipping_cost(float weight) override { // overrides the pure virtual function
		return 2.0 * weight;
	}
};

class GovernmentPost : public shipping_company { // GovernmentPost is a derived class of shipping_company
public:
	float shipping_cost(float weight) override { // overrides the pure virtual function
		if (weight < 2.0) {
			return 3.0;
		}
		else if (weight < 4.0) {
			return 7.0;
		}
		else if (weight < 6.0) {
			return 11.0;
		}
		else {
			return 2.0 * weight;
		}
	}
};

shipping_company& select_company() {  // function to select the shipping company
	// This function returns a reference to a shipping_company object
	int option;
	cout << "Which shipping company do you use? " <<
		"Enter 1 for VQT, 2 for NatFast, 3 for Government Post: ";
	cin >> option;
	if (option == 1) {
		return *new VQT();  // return a reference to a new VQT object, we use new to create a new object, meaning we need to delete it later
	}
	else if (option == 2) {
		return *new NatFast(); // return a reference to a new NatFast object
	}
	else {
		return *new GovernmentPost(); // return a reference to a new GovernmentPost object
	}
}

int main() {
	float w;
	cout << "What is the package weight? ";
	cin >> w;
	shipping_company& x = select_company();

	cout << "Your package will cost " << x.shipping_cost(w) << " to ship." << endl;
	delete &x; // delete the object created by new in select_company
}

// Pure virtual functions are functions that have no implementation in the base class and must be overridden in derived classes.
// They are declared by assigning 0 to the function in the base class.
// Pure virtual functions are used to create abstract classes, which cannot be instantiated directly.
// Abstract classes are used to define a common interface for derived classes, allowing for polymorphism.
// In this program, the shipping_company class is an abstract class with a pure virtual function shipping_cost().
// The derived classes VQT, NatFast, and GovernmentPost provide their own implementations of the shipping_cost() function.
// The select_company() function returns a reference to a shipping_company object based on user input.
// The main() function prompts the user for the package weight and calls the shipping_cost() function of the selected shipping company.
// This allows for dynamic binding, where the correct shipping_cost() function is called based on the actual object type at runtime.