// Program 12_4
// Demonstrating return
#include<iostream>
using namespace std;

int get_guess() {
	int guess;
	cout << "Enter your guess, a number from 1 to 100: ";
	cin >> guess;
	return guess;
}

int main() {
	int firstguess;
	firstguess = get_guess();
	cout << "Your guess was: " << firstguess << endl;              
}