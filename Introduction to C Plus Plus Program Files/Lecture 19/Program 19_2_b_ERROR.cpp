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
	sale_item.volume = 0;
	sale_item.has_lid = false;
	drinking_cup styrofoam_cup;
	styrofoam_cup.metricunits = false;                           
}