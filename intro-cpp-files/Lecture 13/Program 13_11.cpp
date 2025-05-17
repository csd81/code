// Program 13_11
// A constant variable
#include<iostream>
using namespace std;

int main() {
	const float PI = 3.14159;
	float r;
	cout << "Enter the radius of a circle: ";
	cin >> r;
	float area = PI * r * r;
	float circumference = 2 * PI * r;
	cout << "The area of a circle of radius " << r << " is " << area << endl;  
	cout << "The circumference of a circle of radius " << r << " is " << circumference << endl;
	// PI = 3.14; // This will cause a compilation error because PI is a constant variable
	return 0;         
}

// constant variables are variables whose value cannot be changed after they are initialized.
// They are declared using the const keyword in C++.
// In this program, we declare a constant variable PI and initialize it to 3.14159.
// We then use this constant variable to calculate the area of a circle with radius r.
// The value of PI cannot be changed after it is initialized, ensuring that the value of PI remains constant throughout the program.