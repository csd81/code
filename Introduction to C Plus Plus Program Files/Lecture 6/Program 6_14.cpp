// Program 6_14
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
	cout << "You guessed it!  It took you " << num_guesses << " tries." << endl;
}


// this code is a simple number guessing game.
// The program generates a random number between 1 and 100 and asks the user to guess it.
// The user is prompted to enter their guess, and the program provides feedback on whether the guess is too high or too low.
// The program continues to prompt the user for guesses until they correctly guess the number.
// Once the user guesses the correct number, the program congratulates them and displays the number of attempts it took to guess correctly.
// The program uses the rand() function to generate a random number and the srand() function to seed the random number generator with the current time.
// The srand(time(0)) line ensures that the random number generated is different each time the program is run.
// The program also uses a while loop to repeatedly prompt the user for guesses until they guess the correct number.
// The program uses the cin object to read user input from the standard input (keyboard).
// The program uses the cout object to print messages to the console.
// The program uses the endl manipulator to insert a newline character and flush the output buffer.
// The program uses the using namespace std; directive to avoid having to prefix standard library names with std::.
// The program includes the <iostream>, <cstdlib>, and <ctime> header files to use the standard input/output stream, random number generation, and time functions, respectively.
// The program uses the rand() function to generate a random number between 0 and RAND_MAX.
// The program uses the % operator to limit the range of the random number to 1-100.
// The program uses the + operator to adjust the range of the random number to 1-100.
// The program uses the cin object to read user input from the standard input (keyboard).
// The program uses the cout object to print messages to the console.
// The program uses the endl manipulator to insert a newline character and flush the output buffer.