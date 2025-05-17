// Program 17_12
// Friend Operator example
#include<iostream>
using namespace std;

class lightbulb {
	int watts_used;
	int lumens;
	int temperature;

public:
	lightbulb() {
		watts_used = 60;
		lumens = 500;
		temperature = 2700;
	}

	void print_vals() {
		cout << watts_used << " " << lumens << " " << temperature << endl;
	}

	friend lightbulb operator *(lightbulb, int);  // we declare the friend function here
};

lightbulb operator *(lightbulb bulb, int increase_factor) { // but we define the friend function here, outside the class
	lightbulb ans;
	ans.watts_used = bulb.watts_used * increase_factor; // it can access the private members of the class
	ans.lumens = bulb.lumens * increase_factor; // it can access the private members of the class
	ans.temperature = bulb.temperature; // it can access temperature, which is a private member of the class
	return ans;
}

int main() {
	lightbulb bulba, bulbb;
	cout << "Lightbulb 1:\n";
	bulba.print_vals();

	cout << "Lightbulb 2:\n";
	bulbb = bulba * 2;
	bulbb.print_vals();
}

// friend functions are not members of the class, but  they can access the private members of the class.
// friend functions are defined outside the class.
// friend functions are used to overload operators that take more than one argument.
// inside the class, we declare the friend function.
// outside the class, we define the friend function.

// friend functions are useful when we want to overload operators that take more than one argument.