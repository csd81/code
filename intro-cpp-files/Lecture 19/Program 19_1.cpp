// Program 19_1
// inheritance Example
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

class mug : public product {
public:
	float size;
	string material;
};

int main() {
	cup plastic_cup;
	plastic_cup.wholesale_cost = 0.10;
	plastic_cup.retail_cost = 0.30;
	plastic_cup.volume = 16.0;
	plastic_cup.color = "red";

	cout << "The plastic cup costs " << plastic_cup.wholesale_cost 
		<< " to purchase and sells for " << plastic_cup.retail_cost << endl;                       
	cout << "The volume of the plastic cup is " << plastic_cup.volume
		<< " ounces and the color is " << plastic_cup.color << endl;

	mug ceramic_mug;
	ceramic_mug.wholesale_cost = 0.50;
	ceramic_mug.retail_cost = 1.50;
	ceramic_mug.size = 12.0;
	ceramic_mug.material = "ceramic";
	cout << "The ceramic mug costs " << ceramic_mug.wholesale_cost 
		<< " to purchase and sells for " << ceramic_mug.retail_cost << endl;
	cout << "The size of the ceramic mug is " << ceramic_mug.size
		<< " ounces and the material is " << ceramic_mug.material << endl;
}



// inheritance in C++ allows a class to inherit properties and behaviors from another class.
// In this example, the class "product" is the base class, and the class "cup" is the derived class.
// The derived class "cup" inherits the properties of the base class "product", which includes the wholesale_cost and retail_cost.
// The derived class "cup" also has its own properties, volume and color.
// The main function creates an object of the derived class "cup" and initializes its properties.
// It then prints the wholesale and retail costs of the plastic cup.

// this code demonstrates the concept of inheritance in C++.
// Inheritance allows a class to inherit properties and behaviors from another class, promoting code reusability and organization.