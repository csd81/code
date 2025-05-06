// Program 17_10
// Operator example - defining inside a class
#include<iostream>
using namespace std;

class lightbulb {
	int watts_used;
	int lumens;
	int temperature;

public:
	lightbulb(int w = 0, int l = 0, int t = 0) {
		watts_used = w;
		lumens = l;
		temperature = t;
	} 

	

	lightbulb operator *(int increase_factor) {
		lightbulb ans;
		ans.watts_used = watts_used * increase_factor;
		ans.lumens = lumens * increase_factor;
		ans.temperature = temperature;
		return ans;
	}

	void print_vals() {
		cout << " Watts: " << watts_used << " W\n" 
			<< " Lumens: " << lumens << " lm\n" 
			<< " Temperature: " << temperature << " K\n";
		
	}
};

int main() {
	cout << "Lightbulb 1:\n";
	lightbulb bulba(60,900,2700); 
	bulba.print_vals();           

	cout << "Lightbulb 2:\n";
	lightbulb bulbb;
	bulbb = bulba * 2;
	bulbb.print_vals();                       
}

// we can define the operator inside the class
// we can overload the operator inside the class.
// To do this, we define the operator function inside the class.
// The operator function is defined as a member function of the class.
// The operator function takes one argument, which is an integer.
// The operator function returns a new object of the class.
// The operator function is called when we use the operator on an object of the class.

