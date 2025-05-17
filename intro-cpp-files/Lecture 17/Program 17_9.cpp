// Program 17_9
// Operator example - adding the reverse-order multiplication
#include<iostream>
using namespace std;

class lightbulb {

	int watts_used;
	int lumens;
	int temperature;
public:
	lightbulb(int w = 60, int l = 900, int t = 2700) : 
		watts_used(w), lumens(l), temperature(t) {
		cout << "Lightbulb created." << endl;
	}
	~lightbulb() {
		cout << "Lightbulb destroyed." << endl;
	}
	void set_watts(int w) {
		watts_used = w;
	}
	void set_lumens(int l) {
		lumens = l;
	}
	void set_temperature(int t) {
		temperature = t;
	}
	int get_watts() const {
		return watts_used;
	}
	int get_lumens() const {
		return lumens;
	}	
	int get_temperature() const {
		return temperature;
	}
};

lightbulb operator *(const lightbulb& bulb, int increase_factor) {
	lightbulb ans(0,0,0);
	ans.set_watts(bulb.get_watts() * increase_factor);
	ans.set_lumens(bulb.get_lumens() * increase_factor);
	ans.set_temperature(bulb.get_temperature());
	return ans;
}

lightbulb operator *(int increase_factor, const lightbulb& bulb) {
	 
	return  bulb * increase_factor; //  this is the reverse-order multiplication
}


int main() {
 

	lightbulb bulba, bulbb, bulbc;
	cout << bulba.get_watts()  << " W, " << bulba.get_lumens() << " lm, " << bulba.get_temperature() << " K\n";
	
	bulbb = bulba * 2;
	cout << bulbb.get_watts() << " W, " << bulbb.get_lumens() << " lm, " << bulbb.get_temperature() << " K\n";
	
	bulbc = 2 * bulba;
	cout << bulbc.get_watts() << " W, " << bulbc.get_lumens() << " lm, " << bulbc.get_temperature() << " K\n";
}