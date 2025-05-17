// Program 6_9
// Random Number generation example with seed (new seed value)
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	srand(3);  // Set the seed for the pseudorandom sequence
	int x = rand();
	cout << "The random number is " << x << endl;
	cout << "Here is another random number: " << rand() << endl;
	cout << "... and another: " << rand() << endl;                                            
}

// seed value is a starting point for the sequence of pseudo-random numbers.
// The seed value is used to initialize the random number generator.
// The seed value determines the starting point for the sequence of pseudo-random numbers.
// If you use the same seed value, you will get the same sequence of pseudo-random numbers.