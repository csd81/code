// Program 17_11
// Operator example - defining a unary operator
#include<iostream>
using namespace std;

class lightbulb {
	int watts_used;
	int lumens;
	int temperature;

public:
	lightbulb(int w = 0, int l = 0, int t = 0) { // constructor
		watts_used = w;
		lumens = l;
		temperature = t;
		cout << "Constructor called\n";
	}
	~lightbulb() { // destructor
		cout << "Destructor called\n";
	}

	

	lightbulb operator *(int increase_factor) {  // overload the * operator, the * operator is a binary operator
		// the * operator takes one argument, which is an integer
		// the * operator returns a new object of the class
		lightbulb ans;
		ans.watts_used = watts_used * increase_factor;
		ans.lumens = lumens * increase_factor;
		ans.temperature = temperature;
		return ans;
	}

	bool operator <(lightbulb& a) { // overload the < operator, the < operator is a binary operator
		// the < operator takes one argument, which is an object of the class
		// the < operator returns a boolean value
		return (watts_used < a.watts_used);
	}

	lightbulb operator !() { // overload the ! operator, the ! operator is a unary operator
		// the ! operator takes no arguments
		// the ! operator returns a new object of the class
		lightbulb ans;
		ans.watts_used = 0;
		ans.lumens = 0;
		ans.temperature = temperature;
		return ans;
	}

	void print_vals() {
		cout << watts_used << " " << lumens << " " << temperature << endl;
	}
};

int main() {
	lightbulb bulba(60,		500,		2700);
	bulba.print_vals();

	lightbulb bulbb(60,		500,		2700);
	bulbb.print_vals();

	lightbulb bulb2 = !bulbb; // call the ! operator
	bulb2.print_vals();
	
	(bulb2 < bulbb) ? cout << "bulb2 < bulbb\n" : cout << "bulb2 >= bulbb\n";

	lightbulb bulb3 = bulba * 2; // call the * operator
	bulb3.print_vals();
}