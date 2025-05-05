// Program 20_1
// Inheritance Example - using function on base class
#include<iostream>
using namespace std;

class product {
public:
	float wholesale_cost;
	float retail_cost;

	float profit_per_item() {
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

float sale_price(product p) {
	return p.retail_cost * 0.9;
}

int main() {
	measuring_cup plastic_cup;
	plastic_cup.wholesale_cost = 0.10;
	plastic_cup.retail_cost = 0.30;
	drinking_cup coffee_cup;
	coffee_cup.wholesale_cost = 0.08;
	coffee_cup.retail_cost = 0.40;

	cout << "The plastic cup costs " << plastic_cup.wholesale_cost 
		<< " to purchase and sells for " << plastic_cup.retail_cost << endl;
	cout << "The coffee cup costs " << coffee_cup.wholesale_cost 
		<< " to purchase and sells for " << coffee_cup.retail_cost << endl;
	cout << "The sale prices will be " << sale_price(plastic_cup) 
		<< " and " << sale_price(coffee_cup) << " respectively." << endl;                      
}