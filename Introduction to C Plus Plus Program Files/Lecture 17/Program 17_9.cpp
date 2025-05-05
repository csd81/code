// Program 17_9
// Operator example - adding the reverse-order multiplication
#include<iostream>
using namespace std;

class lightbulb {
public:
	int watts_used;
	int lumens;
	int temperature;

	lightbulb() {
		watts_used = 60;
		lumens = 900;
		temperature = 2700;
	}
};

lightbulb operator *(lightbulb bulb, int increase_factor) {
	lightbulb ans;
	ans.watts_used = bulb.watts_used * increase_factor;
	ans.lumens = bulb.lumens * increase_factor;
	ans.temperature = bulb.temperature;
	return ans;
}

lightbulb operator *(int increase_factor, lightbulb bulb) {
	lightbulb ans;
	ans.watts_used = bulb.watts_used * increase_factor;
	ans.lumens = bulb.lumens * increase_factor;
	ans.temperature = bulb.temperature;
	return ans;
}

int main() {
	lightbulb bulba, bulbb;
	bulbb = 2 * bulba;
	cout << bulbb.watts_used << " " << bulbb.lumens << " " << bulbb.temperature << endl;             
}