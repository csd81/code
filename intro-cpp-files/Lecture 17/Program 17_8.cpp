// Program 17_8
// Operator example - multiplying lightbulb
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
		cout << "Lightbulb created." << endl;
	}
	
	lightbulb(int w, int l, int t) : 
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
	int get_watts() {
		return watts_used;
	}
	int get_lumens() {
		return lumens;
	}
	int get_temperature() {
		return temperature;
	}


};

void show_properties(lightbulb& b) {
	cout << "Watts used: " << b.get_watts() << endl;
	cout << "Lumens: " << b.get_lumens() << endl;
	cout << "Temperature: " << b.get_temperature() << endl;
}

lightbulb operator *(lightbulb& bulb, int increase_factor) {
	lightbulb ans;
	ans.set_watts(bulb.get_watts() * increase_factor);
	ans.set_lumens(bulb.get_lumens() * increase_factor);
	ans.set_temperature(bulb.get_temperature());
	return ans;
}

int main() {
	lightbulb bulb_a;
	lightbulb bulb_b;
	cout << "We have a lightbulb with the following properties:" << endl;
	show_properties(bulb_a);
	
	cout << "We will multiply the lightbulb by 2." << endl;
	bulb_b = bulb_a * 2;
	cout << "The new lightbulb has the following properties:" << endl;
	show_properties(bulb_b);

	cout << "You can create a new lightbulb with custom properties." << endl;
	cout << "Enter the watts used, lumens, and temperature:" << endl;
	int watts, lumens, temperature;
	cin >> watts >> lumens >> temperature;
	lightbulb custom_bulb(watts, lumens, temperature);
	cout << "The custom lightbulb has the following properties:" << endl;
	show_properties(custom_bulb);

	cout << "Enter a factor to multiply the custom lightbulb:" << endl;
	int factor;
	cin >> factor;
	lightbulb multiplied_bulb;
	multiplied_bulb = custom_bulb * factor;
	cout << "The multiplied lightbulb has the following properties:" << endl;
	show_properties(multiplied_bulb);

	return 0;
}
/*
 This program demonstrates operator overloading in C++
 It defines a class called lightbulb with three member variables:
 watts_used, lumens, and temperature.
 The class has a default constructor that initializes these variables to specific values.

 The program also defines an overloaded multiplication operator (*) that takes a lightbulb object and an integer as arguments.
 The operator multiplies the watts_used and lumens of the lightbulb by the integer factor
 and returns a new lightbulb object with the updated values.
 The main function creates two lightbulb objects, bulba and bulbb.
 It multiplies bulba by 2 using the overloaded operator and assigns the result to bulbb.
 Finally, it prints the watts_used, lumens, and temperature of bulbb to the console.

 */