// Program 13_1
// Function review: function to average 3 numbers
#include <iostream>
using namespace std;

float average(float a, float b, float c) {
	return (a + b + c) / 3.0;
}

int main() {
	cout << "The average of 10, 35, and 17 is: " << average(10, 35, 17) << endl;            
}