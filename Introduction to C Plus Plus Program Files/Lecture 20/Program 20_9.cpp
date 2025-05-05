// Program 20_9
// Abstract shape class with pure virtual area function
#include<iostream>
using namespace std;

class shape {
public:
	virtual float area() = 0;
};

class square : public shape {
private:
	float side_length;

public:
	square(float s) {
		side_length = s;
	}

	float area() {
		return side_length * side_length;
	}
};

class circle : public shape {
private:
	float radius;

public:
	circle(float r) {
		radius = r;
	}

	float area() {
		return radius * radius*3.14159;
	}
};

int main() {
	square s(3.0);
	circle c(3.0);
	cout << "Areas are: " << s.area() << " and " << c.area() << endl;                
}