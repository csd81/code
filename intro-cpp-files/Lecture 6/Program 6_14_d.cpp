// Program 6_14_d
// Random Number Guessing Game
#include <iostream>                                                       
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// Generate a random number
	srand(time(0));  // Set the seed for the pseudorandom sequence
	int num = (rand() % 100) + 1;

	// Get a user's initial guess
	int guess;
	cout << "Guess a number from 1 to 100: ";
	cin >> guess;
	int guesses = 1;

	// Repeat until the user guesses the right value
	while (guess != num) {
		// Report if too high or too low
		if (guess < num) {
			cout << "Too low! Try again: ";
		} else {
			cout << "Too high! Try again: ";
		}
		// Get another guess
		cin >> guess;
		guesses++;
	}

	// User guessed it - report how many tries.
	cout << "You guessed it in " << guesses << " tries." << endl;
	cout << "The number was " << num << endl;
}