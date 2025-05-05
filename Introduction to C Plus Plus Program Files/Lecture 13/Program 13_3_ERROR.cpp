// Program 13_3_ERROR
// Multiple parameter types; Error when trying to use floats due to double
#include <iostream>
using namespace std;

float average(float a, float b) {
	return (a + b) / 2.0;
}

int average(int a, int b) {
	return (a + b) / 2;
}

int main() {
	cout << "The average of 10 and 35 is: " << average(10.0, 35.0) << endl;              
}