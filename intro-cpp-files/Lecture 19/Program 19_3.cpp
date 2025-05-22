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
		return retail_cost - wholesale_cost;  // This function calculates the profit per unit
	}
};

class plate : public product { // plate is a subclass of product
public:
	float diameter;
};

class cup : public product { // cup is a subclass of product
public:
	float volume;
	string color;
};

class measuring_cup : public cup { // measuring_cup is a subclass of cup
public:
	bool metricunits;
	int num_gradations;
};

class drinking_cup : public cup { // drinking_cup is a subclass of cup
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

		plate dinner_plate;
	dinner_plate.wholesale_cost = 0.50;
	dinner_plate.retail_cost = 1.50;
	dinner_plate.diameter = 10.0;
	cout << "The dinner plate costs " << dinner_plate.wholesale_cost
		<< " to purchase and sells for " << dinner_plate.retail_cost << endl;
	cout << "We make a profit of " << dinner_plate.profit_per_unit()
		<< " on each one." << endl;




	}

