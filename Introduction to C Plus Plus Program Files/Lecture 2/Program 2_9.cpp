// Program 2_9
// What does this output?
#include <iostream>
using namespace std;

int main() {
	float x = 3.0;
	float y;
	float z;
	y = x;                                                      
	z = x * y;
	x = 5.5;
	cout << x << " " << y << " " << z << endl;
}