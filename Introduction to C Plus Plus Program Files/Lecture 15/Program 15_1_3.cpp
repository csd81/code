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

vector<vector<int> > initialize_board(int columns, int rows) {
	/* Initialize the board itself, to all empty squares */
	vector<int> column(rows, 0);
	vector<vector<int> > board(columns, column);
	return board;
}

vector<vector<int> > initialize_game() {
	/* Initialize the entire game */
	int c, r;
	get_board_size(c, r);
	return initialize_board(c, r);
}

int main() {
	vector<vector<int> > board;
	board = initialize_game();            
}