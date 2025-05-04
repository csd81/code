// Program 6_8
// Generating multiple random numbers
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int x = rand();
	cout << "The random number is " << x << endl;
	cout << "Here is another random number: " << rand() << endl;
	cout << "... and another: " << rand() << endl;                                      
}