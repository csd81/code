// Program 17_11
// Operator example - defining a unary operator
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

	lightbulb operator *(int increase_factor) {
		lightbulb ans;
		ans.watts_used = watts_used * increase_factor;
		ans.lumens = lumens * increase_factor;
		ans.temperature = temperature;
		return ans;
	}

	bool operator <(lightbulb& a) {
		return (watts_used < a.watts_used);
	}

	lightbulb operator !() {
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
	lightbulb bulb;
	(!bulb).print_vals();                          
}