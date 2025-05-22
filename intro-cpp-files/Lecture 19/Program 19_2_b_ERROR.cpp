// Program 19_2_b_ERROR
// Inheritance Example - multiple levels of inheritance
#include<iostream>                                                    
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
	product sale_item;
	// sale_item.volume = 0;
	// sale_item.has_lid = false;
	sale_item.wholesale_cost = 0.10;
	sale_item.retail_cost = 0.30;

	drinking_cup styrofoam_cup;
	styrofoam_cup.has_lid = false;                           
}

// this example demonstrates the concept of multiple levels of inheritance in C++.
// In this example, the class "product" is the base class, and the class "cup" is the derived class.
// The derived class "cup" inherits the properties of the base class "product", which includes the wholesale_cost and retail_cost.
// The derived class "cup" also has its own properties, volume and color.

// The class "measuring_cup" is derived from the class "cup", and it adds its own properties, metricunits and num_gradations.

// The class "drinking_cup" is also derived from the class "cup", and it adds its own property, has_lid.

// The main function creates an object of the base class "product".

// However, the program contains an error because the base class "product" does not have the properties volume and has_lid.
// The program will not compile because the base class "product" does not have these properties.

// the drinking_cup does not have the properties metricunits and num_gradations,
// which are specific to the measuring_cup class.