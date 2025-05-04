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