// Program 17_8
// Operator example - multiplying lightbulb
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

int main() {
	lightbulb bulba, bulbb;
	bulbb = bulba * 2;
	cout << bulbb.watts_used << " " << bulbb.lumens << " " << bulbb.temperature << endl;                  
}