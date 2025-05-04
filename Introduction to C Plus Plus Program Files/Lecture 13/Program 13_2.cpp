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
	cout << "The average of 10, and 35 is: " << average(10, 35) << endl;
	cout << "The average of 10, 35, and 17 is: " << average(10, 35, 17) << endl;
	cout << "The average of 10, 35, 17, and 21 is: " << average(10, 35, 17, 21) << endl;         
}