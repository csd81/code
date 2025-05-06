// Program 19_2_a
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
	bool metricunits; // true if metric units, false if English units
	// metric units are a system of measurement based on the meter, liter, and gram.
	// English units are a system of measurement based on inches, feet, and pounds.
	int num_gradations; // number of gradations or markings on the measuring cup
	// gradations are the markings on a measuring cup that indicate the volume of liquid.
	// they are usually marked in milliliters (ml) or ounces (oz).
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

// a base class is a class that is inherited from by other classes.
// a derived class is a class that inherits from a base class.
// In this example, the class "product" is the base class, and the class "cup" is the derived class.
// The derived class "cup" inherits the properties of the base class "product", which includes the wholesale_cost and retail_cost.
// The derived class "cup" also has its own properties, volume and color.
// The derived class "measuring_cup" inherits from the class "cup", which means it also inherits the properties of the base class "product".
// The derived class "measuring_cup" has its own properties, metricunits and num_gradations.
// The main function creates an object of the derived class "measuring_cup" and initializes its properties.