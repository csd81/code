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

	friend lightbulb operator *(lightbulb, int);
};

lightbulb operator *(lightbulb bulb, int increase_factor) {
	lightbulb ans;
	ans.watts_used = bulb.watts_used*increase_factor;
	ans.lumens = bulb.lumens*increase_factor;
	ans.temperature = bulb.temperature;
	return ans;
}

int main() {
	lightbulb bulba, bulbb;
	bulbb = bulba * 2;
	bulbb.print_vals();                  
}