// Program 17_13
// Overloading Output Stream Example

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

	friend ostream& operator <<(ostream&, const lightbulb&);
};

ostream& operator <<(ostream& s, const lightbulb& b) {
	s << b.watts_used << " W, " << b.lumens << " lm, " << b.temperature << " K";
	return s;
}

int main() {
	lightbulb bulb;
	cout << bulb << endl;                      
}

// << is the output stream operator
// in this example, we are overloading the << operator
// the new operator is defined as a friend function
// the new operator takes two arguments, an output stream and a lightbulb object
// both arguments are passed by reference
// the new operator returns an output stream
// the returned output stream is a reference to the original output stream

// it adds new functionality to the existing output stream operator
// in that it can now output a lightbulb object with all its values


