// Program 12_4
// Demonstrating return
#include<iostream>
using namespace std;

int get_guess() {
	int guess;
	cout << "Enter your guess, a number from 1 to 100: ";
	cin >> guess;
	while (guess < 1 || guess > 100) {
		cout << "Invalid guess. Please enter a number from 1 to 100: ";
		cin >> guess;
	}
	return guess;
}

int main() {
	int firstguess;
	firstguess = get_guess();
	cout << "Your guess was: " << firstguess << endl;              
}

// the rerurn value of the function is assigned to the variable firstguess in the main() function.
// The get_guess() function prompts the user to enter a guess, checks if the guess is valid (between 1 and 100),
// and returns the valid guess to the main() function.