// Program 13_11
// A constant variable
#include<iostream>
using namespace std;

int main() {
	const float PI = 3.14159;
	float r = 2.0;
	float area = PI * r*r;
	cout << "The area of a circle of radius " << r << " is " << area << endl;            
}