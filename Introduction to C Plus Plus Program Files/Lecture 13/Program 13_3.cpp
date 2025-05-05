// Program 13_3
// Multiple parameter types
#include <iostream>
using namespace std;

double average(double a, double b) {
	cout << "This is the double version of the average function." << endl;
	return (a + b) / 2.0;
}

int average(int a, int b) {
	cout << "This is the int version of the average function." << endl;
	return (a + b) / 2;
}

int main() {
	cout << "The average of 10 and 35 is:\n" << average(10.3, 35.3) << endl;             // Calls the double version
	cout << "The average of 10 and 35 is:\n" << average(10, 35) << endl;                 // Calls the int version
}