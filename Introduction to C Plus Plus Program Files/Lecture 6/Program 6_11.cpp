// Program 6_11
// Random Number generation within range 0-99
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));  // Set the seed for the pseudorandom sequence
	int x = rand() % 100; // Modulus 100 means number between 0 and 99
	cout << "The random number is " << x << endl;                        
}