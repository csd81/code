// Program 17_10
// Operator example - defining inside a class
#include<iostream>
using namespace std;

class lightbulb {
	int watts_used;
	int lumens;
	int temperature;

public:
	lightbulb() {
		watts_used = 60;
		lumens = 900;
		temperature = 2700;
	}

	lightbulb operator *(int increase_factor) {
		lightbulb ans;
		ans.watts_used = watts_used * increase_factor;
		ans.lumens = lumens * increase_factor;
		ans.temperature = temperature;
		return ans;
	}

	void print_vals() {
		cout << watts_used << " " << lumens << " " << temperature << endl;
	}
};

int main() {
	lightbulb bulba, bulbb;
	bulbb = bulba * 2;
	bulbb.print_vals();                       
}