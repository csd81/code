// Program 17_11_a
// ++ Operator example - prefix and postfix
#include<iostream>
using namespace std;

class elephant {
public:
	float height;
	float weight;

	elephant() {
		height = 10.0;
		weight = 13000.0;
	}

	void operator ++() { // Prefix operator - for ++elephant, it is a unary operator, takes no arguments
		//Prefix operator - for ++elephant 
		cout << "increasing height of elephant" << endl;
		height += 0.1;
	}

	void operator ++(int whatever) { // int is a dummy variable, it is not used but is required to differentiate between prefix and postfix
		//Postfix operator - for elephant++
		cout << "increasing weight of elephant" << endl;
		weight += 100.0;
	}

	void print_characteristics() {
		cout << "Height is " << height << " and Weight is " << weight << endl;
	}
};

int main() {
	elephant Dumbo;
	Dumbo.print_characteristics();
	Dumbo++; // Postfix operator - for Dumbo++, increment weight
	Dumbo.print_characteristics();
	++Dumbo; // Prefix operator - for ++Dumbo, increment height
	Dumbo.print_characteristics();                     
}