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

	// Report if too high or too low

	// Get another guess

	// User guessed it - report how many tries.
}