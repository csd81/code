// Program 20_9
// Abstract shape class with pure virtual area function
#include<iostream>
using namespace std;

class shape {
public:
	virtual float area() = 0; // pure virtual function
};

class square : public shape {
private:
	float side_length; //	 private member variable

public:
	square(float s) {
		side_length = s;
	}

	float area() override {  // override area function
		return side_length * side_length;
	}
};

class circle : public shape { // public inheritance
private:
	float radius; // private member variable

public:
	circle(float r) {
		radius = r;
	}

	float area() override {
		return radius * radius * 3.14159;
	}
};

int main() {
	square s(3.0);
	circle c(3.0);
	cout << "Areas are: " << s.area() << " and " << c.area() << endl;                
}

// we use public inheritance here, because we want to use the base class pointer to access the derived class objects
// and we want to use the derived class objects as if they are base class objects
