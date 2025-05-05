// Program 13_1
// Function review: function to average 3 numbers
#include <iostream>
using namespace std;

float average(float a, float b, float c) {
	return (a + b + c) / 3.0;
}

int main() {
	float x, y, z;
	cout << "Enter three numbers: ";
	cin >> x >> y >> z;
	cout << "The average of " << x << ", " << y <<", and " << z <<" is: ";
	cout << average(x, y, z) << endl;
	return 0;
}

// This program demonstrates the use of a function to calculate the average of three numbers.
// The function takes three float parameters and returns their average.
// The main function calls the average function with three numbers and prints the result.