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
	s << b.watts_used << " " << b.lumens << " " << b.temperature;
	return s;
}

int main() {
	lightbulb bulb;
	cout << bulb << endl;                      
}