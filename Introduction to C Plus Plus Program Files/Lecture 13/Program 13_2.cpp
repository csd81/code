// Program 13_2
// Multiple parameter options with different function signatures
#include <iostream>
using namespace std;

float average(float a, float b) {
	return (a + b) / 2.0;
}

float average(float a, float b, float c) {
	return (a + b + c) / 3.0;
}

float average(float a, float b, float c, float d) {
	return (a + b + c + d) / 4.0;
}

int main() {
	int parametercount;
	cout << "Enter the number of parameters (2, 3, or 4): ";
	cin >> parametercount;
	if (parametercount == 2) {
		float x, y;
		cout << "Enter two numbers: ";
		cin >> x >> y;
		cout << "The average of " << x << ", and " << y << " is: ";
		cout << average(x, y) << endl;
	} else if (parametercount == 3) {
		float x, y, z;
		cout << "Enter three numbers: ";
		cin >> x >> y >> z;
		cout << "The average of " << x << ", " << y << ", and " << z << " is: ";
		cout << average(x, y, z) << endl;
	} else if (parametercount == 4) {
		float x, y, z, w;
		cout << "Enter four numbers: ";
		cin >> x >> y >> z >> w;
		cout << "The average of " << x << ", " << y << ", " << z << ", and " << w << " is: ";
		cout << average(x, y, z, w) << endl;
	} else {
		cout << "Invalid number of parameters." << endl;
	}
	
	return 0;
}

// This program demonstrates function overloading in C++.
// It defines multiple versions of the average function, each with a different number of parameters.
// The main function calls each version of the average function with different numbers of arguments and prints the results.