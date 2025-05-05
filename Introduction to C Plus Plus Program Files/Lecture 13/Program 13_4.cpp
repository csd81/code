// Program 13_4
// Multiple parameter types - calling with floats
#include <iostream>
using namespace std;

float average(float a, float b) {
	return (a + b) / 2.0;
}

int average(int a, int b) {
	return (a + b) / 2;
}

int main() {
	cout << "The average of 10 and 35 is: " << average(10.0f, 35.0f) << endl;       // 
	cout << "The average of 10 and 35 is (truncated): " << average(10, 35) << endl;       // 
}

// 10.0f and 35.0f are float literals
// The f suffix indicates that the number is a float literal, which is a single-precision floating-point number.
// This is important because the average function takes float parameters, 
// and using float literals ensures that the correct version of the function is called.
// // If you don't use the f suffix, the numbers would be treated as double literals by default,