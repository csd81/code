// Program 15_1_3
// Connect 4 Program - stage 3
#include <iostream>
#include <vector>
using namespace std;

void get_board_size(int& columns, int& rows) {
	/* Get size of board from user */
	cout << "How many columns should the board have? ";
	cin >> columns;
	cout << "How many rows should the board have? ";
	cin >> rows;
}

vector<vector<int> > initialize_board(int columns, int rows) { // this function takes the number of columns and rows as parameters
	// and returns a 2D vector representing the board

	/* Initialize the board itself, to all empty squares */
	// Initialize the board with empty spaces
	// using a 2D vector
	vector<int> column(rows, 0);
	vector<vector<int> > board(columns, column);
	return board; // 
}

vector<vector<int> > initialize_game() { // this function initializes the game
	// it calls the get_board_size function to get the size of the board
	// and then calls the initialize_board function to create the board
	// it returns a 2D vector representing the board
	/* Initialize the entire game */
	int c, r;
	get_board_size(c, r);
	return initialize_board(c, r);
}

int main() {
	vector<vector<int> > board;
	// this variable will hold the board
	board = initialize_game();          
	// this variable will hold the board  
}