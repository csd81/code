// Program 19_2_b
// Inheritance Example - multiple levels of inheritance
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
	plastic_cup.num_gradations = 10;

	cout << "The plastic cup costs " << plastic_cup.wholesale_cost 
		<< " to purchase and sells for " << plastic_cup.retail_cost << endl;
	cout << "It is " << plastic_cup.color << " in color and has a volume of "
		<< plastic_cup.volume << endl;
	if (plastic_cup.metricunits) {
		cout << "It has a total of " << plastic_cup.num_gradations 
			<< " markings in metric units." << endl;
	}
	else {
		cout << "It has a total of " << plastic_cup.num_gradations 
			<< " markings, in English units." << endl;                              
	}           
}