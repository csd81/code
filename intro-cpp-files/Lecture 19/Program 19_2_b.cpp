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

	// has_lid is a boolean variable that indicates whether the drinking cup has a lid or not.
void check_lid() {
	if (has_lid) {
		cout << "It has a lid." << endl;
	}
	else {
		cout << "It does not have a lid." << endl;
	}
	}
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

	drinking_cup glass_cup;
	glass_cup.wholesale_cost = 0.20;
	glass_cup.retail_cost = 0.50;
	glass_cup.volume = 500.0;
	glass_cup.color = "blue";
	glass_cup.has_lid = true;
	cout << "The glass cup costs " << glass_cup.wholesale_cost 
		<< " to purchase and sells for " << glass_cup.retail_cost << endl;
	cout << "It is " << glass_cup.color << " in color and has a volume of "
		<< glass_cup.volume << endl;
	glass_cup.check_lid();

	drinking_cup glass_cup1;
	glass_cup1.wholesale_cost = 0.20;
	glass_cup1.retail_cost = 0.50;
	glass_cup1.volume = 500.0;
	glass_cup1.color = "blue";
	glass_cup1.has_lid = true;
	cout << "The glass cup costs " << glass_cup1.wholesale_cost 
		<< " to purchase and sells for " << glass_cup1.retail_cost << endl;
	cout << "It is " << glass_cup1.color << " in color and has a volume of "
		<< glass_cup1.volume << endl;
	glass_cup1.check_lid();
	glass_cup1.has_lid = false;
	glass_cup1.check_lid();
}

// this code demonstrates the concept of inheritance in C++.
// Inheritance allows a class to inherit properties and behaviors from another class, promoting code reusability and organization.
// In this example, the class "product" is the base class, and the class "cup" is the derived class.
// The derived class "cup" inherits the properties of the base class "product", which includes the wholesale_cost and retail_cost.
// The derived class "cup" also has its own properties, volume and color.
// The derived class "measuring_cup" inherits from the class "cup" and adds its own properties, metricunits and num_gradations.
// The derived class "drinking_cup" also inherits from the class "cup" and adds its own property, has_lid.

// this is called multiple levels of inheritance.
// note that measuring_cup and drinking_cup are both derived from the same base class, cup  but they have different properties.
// this is called multiple inheritance.
