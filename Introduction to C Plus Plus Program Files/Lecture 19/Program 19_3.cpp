// Program 19_3
// Inheritance Example - inheriting member functions
#include<iostream>
#include<string>                   
using namespace std;

class product {
public:
	float wholesale_cost;
	float retail_cost;

	float profit_per_unit() {
		return retail_cost - wholesale_cost;
	}
};

class plate : public product {
public:
	float diameter;
};

class cup : public product {
public:
	float volume;
	string color;
};

class measuring_cup : public cup {
public:
	bool metricunits;
	int num_gradations;
};

class drinking_cup : public cup {
public:
	bool has_lid;
};

int main() {
	measuring_cup plastic_cup;
	plastic_cup.wholesale_cost = 0.10;
	plastic_cup.retail_cost = 0.30;
	plastic_cup.volume = 1000.0;
	plastic_cup.color = "clear";
	plastic_cup.metricunits = true;
	plastic_cup.num_gradations - 10;

	cout << "The plastic cup costs " << plastic_cup.wholesale_cost
		<< " to purchase and sells for " << plastic_cup.retail_cost << endl;
	cout << "We make a profit of " << plastic_cup.profit_per_unit()                           
		<< " on each one." << endl;                              
}
