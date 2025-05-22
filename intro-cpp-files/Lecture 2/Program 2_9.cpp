// Program 2_9
// What does this output?
#include <iostream>
using namespace std;

int main() {
	float x = 3.0; // float variable
	float y; 	// declare y
	float z; 	// declare z

	y = x; 		// assign x to y                                   
				// y is now 3.0

	z = x * y; // assign x * y to z
				// z is now 9.0

	x = 5.5; 	// assign 5.5 to x
				// x is now 5.5
	cout << x << " " << y << " " << z << endl; // output x, y, z
				// output is 5.5 3.0 9.0
}