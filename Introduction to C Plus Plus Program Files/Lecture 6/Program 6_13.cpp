// Program 6_13
// Multiple random numbers in range of 1 to 100
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));  // Set the seed for the pseudorandom sequence
	int x = (rand() % 100) + 1;
	cout << "The random number is " << x << endl;
	cout << "Here is another random number: " << (rand() % 100) + 1 << endl;
	cout << "... and another: " << (rand() % 100) + 1 << endl;                   
}