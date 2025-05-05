// Program 6_12
// Random Number generation within range 1-100
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));  // Set the seed for the pseudorandom sequence
	int x = rand() % 100 + 1; // Adding 1 to change [0-99] to [1-100]
	cout << "The random number is " << x << endl;                    

	int y = rand() % 1000 + 1; // Adding 1 to change [0-999] to [1-1000]
	cout << "The random number is " << y << endl;                    
}