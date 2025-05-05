// Program 6_10
// Random Number generation example with time-based seed
#include <iostream>
#include <cstdlib> // This header file is included to use the standard library functions for random number generation.
#include <ctime> // This header file is included to use the time function for seeding the random number generator.
using namespace std;

int main() {
	srand(time(0));  // Set the seed for the pseudorandom sequence
	int x = rand();
	cout << "The random number is " << x << endl;
	cout << "Here is another random number: " << rand() << endl;
	cout << "... and another: " << rand() << endl;                                
}

// time(0) returns the current time as a time_t object.	
// The time(0) function returns the number of seconds since the epoch (00:00:00 UTC on 1 January 1970).
// The time(0) function is used to generate a different seed value each time the program is run.