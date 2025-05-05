// Program 13_4
// Multiple parameter types - calling with floats
#include <iostream>
using namespace std;

float average(float a, float b) {
	return (a + b) / 2.0;
}

float average(int a, int b) {
	return 1.0;
}

int main() {
	cout << "The average of 10 and 35 is: " << average(10.0f, 35.0f) << endl;       
}