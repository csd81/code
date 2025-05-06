// Program 20_10
// Abstract shape class, adding perimeter function and triangle class
#include <iostream>
#include <cmath> // for sqrt
using namespace std;

class shape {
public:
	virtual float area() = 0; // pure virtual function
	virtual float perimeter() = 0; // pure virtual function
};

class square : public shape { // public inheritance
private:
	float side_length;

public:
	square(float s) {
		side_length = s; // constructor
	}

	float area() override { // override area function
		return side_length * side_length; 
	}

	float perimeter() override { // override perimeter function
		return 4.0 * side_length;
	}
};

class circle : public shape {
private:
	float radius;

public:
	circle(float r) {
		radius = r;
	}

	float area() override { // override area function
		return radius * radius * 3.14159;
	}

	float perimeter() override { // override perimeter function
		return 2.0 * radius * 3.14159;
	}
};

class triangle : public shape {
private:
	float side_length_1, side_length_2, side_length_3;

public:
	// Constructor takes in lengths of 3 sides
	triangle(float s1, float s2, float s3) {
		side_length_1 = s1;
		side_length_2 = s2;
		side_length_3 = s3;
	}

	float area() override { // override area function
		// Compute with Hero's formula 
		float s = (side_length_1 + side_length_2 + side_length_3) / 2.0;
		return sqrt(s * (s - side_length_1) * (s - side_length_2) * (s - side_length_3));  // sqrt is from cmath
	}

	float perimeter() override {
		return side_length_1 + side_length_2 + side_length_3;
	}
};

void report_info(shape& s) {  // pass by reference so we can use base class pointer to access derived class objects
	cout << "The Area is: " << s.area() << endl;
	cout << "The Perimeter is: " << s.perimeter() << endl;
}

int main() {
	square s(3.0);
	circle c(3.0);
	triangle t(3.0, 4.0, 5.0);
	report_info(s);
	report_info(c);
	report_info(t);                    
}

// Hero's formula is used to calculate the area of a triangle when the lengths of all three sides are known.
// It is given by the formula:
// Area = sqrt(s * (s - a) * (s - b) * (s - c))
// where s is the semi-perimeter of the triangle, and a, b, and c are the lengths of the sides.
// The semi-perimeter s is calculated as:
// s = (a + b + c) / 2