// Program 12_1
// Demonstrating a function body
#include<iostream>
using namespace std;

void print_help() {
	cout << "The object of the game is to get three of your mark in a single row," 
		<< "a single column, or on a diagonal." << endl;
	cout << "One player will use an 'X' mark, and one wil use an 'O' mark." << endl;
	cout << "The players will take turns placing a mark in an empty square in an 3x3 grid." 
		<< endl;
	cout << "The first player to get 3 marks in the right combination will win," 
		<< "but if neither does after all 9 cells are filled, the game ends in a tie." 
		<< endl;
}

int main() {
	print_help();         
}
 

// The object of the game is to get three of your mark in a single row,   		a single column, or on a diagonal.
// One player will use an 'X' mark, and one wil use an 'O' mark.
// The players will take turns placing a mark in an empty square in an 3x3 grid.
// The first player to get 3 marks in the right combination will win, but if neither does after all 9 cells are filled, the game ends in a tie.

// This game is a simple implementation of the classic game of Tic-Tac-Toe.
 

// print_help() is a function that prints the rules of the game to the console.
// It is defined outside of the main() function and is called from within the main() function.
// The function does not take any arguments and does not return any value.
// The function uses the cout object to output text to the console.