// Program 6_14_f                                            
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
		if (user_guess < num_to_guess) {
			cout << "Your guess was too low." << endl;
		}
		else {
			cout << "Your guess was too high." << endl;
		}

		// Get another guess
		cout << "Guess again: ";
		cin >> user_guess;
		num_guesses++;
	}

	// User guessed it - report how many tries.
	cout << "You guessed it in " << num_guesses << " tries." << endl;
	cout << "The number was " << num_to_guess << endl;
	cout << "Congratulations! You won!" << endl;
	cout << "Thank you for playing!" << endl;
	cout << "Goodbye!" << endl;
	cout << "Have a great day!" << endl;
	cout << "See you next time!" << endl;
	cout << "Take care!" << endl;
	cout << "Happy coding!" << endl;
	cout << "Keep learning!" << endl;
	cout << "Stay curious!" << endl;
	cout << "Keep exploring!" << endl;
	cout << "Keep pushing your limits!" << endl;
	cout << "Keep challenging yourself!" << endl;
	cout << "Keep growing!" << endl;
	cout << "Keep improving!" << endl;
	cout << "Keep striving for excellence!" << endl;
	cout << "Keep reaching for the stars!" << endl;
	cout << "Keep dreaming big!" << endl;
	cout << "Keep believing in yourself!" << endl;
	cout << "Trump for Pope!" << endl;
}