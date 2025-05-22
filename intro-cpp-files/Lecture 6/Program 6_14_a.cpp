// Program 6_14_a
// Random Number Guessing Game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;                                         

int main() {
	// Generate a random number                          
	srand(time(0));  // Set the seed for the pseudorandom sequence
	int secret_number = (rand() % 100) + 1; // Random number between 1 and 100
	int guess; // Variable to store the user's guess
	int tries = 0; // Variable to count the number of tries
	cout << "Welcome to the Number Guessing Game!" << endl;
	cout << "I have selected a number between 1 and 100." << endl;
	cout << "Try to guess it!" << endl;
	// Get a user's initial guess
	cout << "Enter your guess: ";
	cin >> guess; // Read the user's guess from the standard input (keyboard)
	// Repeat until the user guesses the right value
	while (guess != secret_number) { // Check if the guess is not equal to the secret number
		tries++; // Increment the number of tries
		if (guess < secret_number) { // Check if the guess is less than the secret number
			cout << "Too low! Try again: ";
		} else { // The guess is greater than the secret number
			cout << "Too high! Try again: ";
		}
		cin >> guess; // Read the user's next guess
	} // End of while loop
	tries++; // Increment the number of tries for the correct guess
	cout << "Congratulations! You guessed the number " << secret_number << " in " << tries << " tries." << endl;
	// Report if too high or too low

	// Get another guess

	// User guessed it - report how many tries.
}