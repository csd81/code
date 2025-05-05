// Program 6_14_b
// Random Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// Generate a random number
	srand(time(0));  // Set the seed for the pseudorandom sequence                
	int num_to_guess = (rand() % 100) + 1;
	int tries = 0; // Variable to count the number of tries
	
	// Get a user's initial guess
	int guess;
	cout << "Your guess: " << endl;
	cin >> guess; // Read the user's guess from the standard input (keyboard)
	tries++;
	// Repeat until the user guesses the right value
	
	while (guess != num_to_guess) {
		tries++;
		if (guess < num_to_guess) {
			cout << "Too low! Try again: ";
		} else {
			cout << "Too high! Try again: ";	
		}
		cin >> guess; // Read the user's guess from the standard input (keyboard)
		tries++;
	}
	// Report if too high or too low

	// Get another guess

	// User guessed it - report how many tries.
	cout << "You guessed it in " << tries << " treis." << endl;
	cout << "The number was " << num_to_guess << endl;
}