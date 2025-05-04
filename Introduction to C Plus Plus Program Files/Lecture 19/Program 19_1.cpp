// Program 19_1
// Inheritance Example
#include<iostream>
#include<string>                 
using namespace std;

class product {
public:
	float wholesale_cost;
	float retail_cost;
};

class cup : public product {
public:
	float volume;
	string color;
};

int main() {
	cup plastic_cup;
	plastic_cup.wholesale_cost = 0.10;
	plastic_cup.retail_cost = 0.30;
	plastic_cup.volume = 16.0;
	plastic_cup.color = "red";

	cout << "The plastic cup costs " << plastic_cup.wholesale_cost 
		<< " to purchase and sells for " << plastic_cup.retail_cost << endl;                       
}