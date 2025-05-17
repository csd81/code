// Program 6_14_c
// Random Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// Generate a random number
	srand(time(0));  // Set the seed for the pseudorandom sequence         
	int num_to_guess = (rand() % 100) + 1;

	// Get a user's initial guess
	int user_guess;
	cout << "Guess a number from 1 to 100: ";
	cin >> user_guess;
	int num_guesses = 1;

	// Repeat until the user guesses the right value
		while (user_guess != num_to_guess) {
		
		
	// Report if too high or too low
	if (user_guess < num_to_guess)
	cout << "Too low! Try again: ";
else
	cout << "Too high! Try again: ";

	// Get another guess
	cin >> user_guess; // Read the user's guess from the standard input (keyboard)
	num_guesses++;
	}
	// User guessed it - report how many tries.
	cout << "You guessed it in " << num_guesses << " tries." << endl;
	cout << "The number was " << num_to_guess << endl;
}