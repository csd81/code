// Program 15_1_4
// Connect 4 Program - complete
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

void display_board(vector<vector<int> > board) {
	/* Print out the board to the screen */
	int i, j;
	//Loop through rows first
	for (j = 0; j < board[0].size(); j++) {
		//Loop through columns next
		for (i = 0; i < board.size(); i++) {
			//Display that location
			if (board[i][j] == 0) {
				cout << ". "; //Empty Cell
			}
			else if (board[i][j] == 1) {
				cout << "1 "; //Player 1 has it
			}
			else {
				cout << "2 "; //Player 2 has it
			}
		}
		cout << endl;  // End of a row
	}
}

int get_move(int player) {
	/* Return the column that the player will place the piece in, 
	for player number passed in */
	int col;
	cout << "Player " << player 
		<< ": Which column do you want to put a piece in (column 1 is at left)? ";
	cin >> col;
	col--; //Convert column to start at 0, not 1
	return col;
}

void place_piece(int column, vector<vector<int> >& board, int player) {
	/* Update the board by adding a piece to the designated column */
	int last_empty = 0;
	while ((last_empty < board[column].size()) && (board[column][last_empty] == 0)) {
		last_empty++;
	}
	last_empty--;
	board[column][last_empty] = player;
}

bool check_vertical_winner(vector<vector<int> > board, int player) {
	/* Check the board to see if that player has 4 consecutive vertical pieces */
	int i, j;
	for (i = 0; i < board.size(); i++) {
		//Can loop over all but last 3 rows, comparing 4 at a time
		for (j = 0; j < board[i].size() - 3; j++) {
			if ((board[i][j] == player) && (board[i][j + 1] == player) 
				&& (board[i][j + 2] == player) && (board[i][j + 3] == player)) {
				return true;
			}
		}
	}
	//Didn't find a winning combination
	return false;
}

bool check_horizontal_winner(vector<vector<int> > board, int player) {
	/* Check the board to see if that player has 4 consecutive horizontal pieces */
	int i, j;
	//Can loop over all but last 3 rows, comparing 4 at a time
	for (i = 0; i < board.size() - 3; i++) {
		for (j = 0; j < board[i].size(); j++) {
			if ((board[i][j] == player) && (board[i + 1][j] == player) && (board[i + 2][j] == player) && (board[i + 3][j] == player)) {
				return true;
			}
		}
	}
	//Didn't find a winning combination
	return false;
}

bool check_increasing_diagonal_winner(vector<vector<int> > board, int player) {
	/* Check the board to see if that player has 4 consecutive increasing 
	diagonal pieces */
	int i, j;
	//Can loop over all but first 3 rows, comparing 4 at a time
	for (i = 3; i < board.size(); i++) {
		//Can loop over all but last 3 rows, comparing 4 at a time
		for (j = 0; j < board[i].size() - 3; j++) {
			if ((board[i][j] == player) && (board[i - 1][j + 1] == player) 
				&& (board[i - 2][j + 2] == player) && (board[i - 3][j + 3] == player)) {
				return true;
			}
		}
	}
	//Didn't find a winning combination
	return false;
}

bool check_decreasing_diagonal_winner(vector<vector<int> > board, int player) {
	/* Check the board to see if that player has 4 consecutive decreasing 
	diagonal pieces */
	int i, j;
	//Can loop over all but last 3 rows, comparing 4 at a time
	for (i = 0; i < board.size() - 3; i++) {
		//Can loop over all but last 3 rows, comparing 4 at a time
		for (j = 0; j < board[i].size() - 3; j++) {
			if ((board[i][j] == player) && (board[i + 1][j + 1] == player) 
				&& (board[i + 2][j + 2] == player) && (board[i + 3][j + 3] == player)) {
				return true;
			}
		}
	}
	//Didn't find a winning combination
	return false;
}

bool check_full_board(vector<vector<int> > board) {
	/* Check the board to see if the board is full */
	//If all columns are full (first element is not 0), it is a full board.
	int i;
	for (i = 0; i < board.size(); i++) {
		if (board[i][0] == 0) {
			return false;
		}
	}
	// Never found an empty column, so must be full
	return true;
}

bool check_winner(vector<vector<int> > board) {
	/* Check the board to see if someone has won or if the board is full */
	if (check_vertical_winner(board, 1) ||
		check_vertical_winner(board, 2) ||
		check_horizontal_winner(board, 1) ||
		check_horizontal_winner(board, 2) ||
		check_increasing_diagonal_winner(board, 1) ||
		check_increasing_diagonal_winner(board, 2) ||
		check_decreasing_diagonal_winner(board, 1) ||
		check_decreasing_diagonal_winner(board, 2)) {
		return true;
	}
	//No winner, but if full board, it's a tie
	return check_full_board(board);
}

void print_winner(vector<vector<int> > board) {
	/* Print the winner, or that there's a tie */
	if (check_vertical_winner(board, 1) ||
		check_horizontal_winner(board, 1) ||
		check_increasing_diagonal_winner(board, 1) ||
		check_decreasing_diagonal_winner(board, 1)) {
		cout << "Player 1 Wins!!!" << endl;
	}
	else if (check_vertical_winner(board, 2) ||
		check_horizontal_winner(board, 2) ||
		check_increasing_diagonal_winner(board, 2) ||
		check_decreasing_diagonal_winner(board, 2)) {
		cout << "Player 2 Wins!!!" << endl;
	}
	else {
		cout << "Tie!" << endl;
	}
}

vector<vector<int> > initialize_game() {
	/* Initialize the entire game */
	int c, r;
	get_board_size(c, r);
	return initialize_board(c, r);
}

bool take_turn(vector<vector<int> >& board, int player) {
	/* Takes a turn, for the given player, returns true if there 
	is then a winner, or board is full */
	display_board(board);
	int move = get_move(player);
	place_piece(move, board, player);
	return(check_winner(board));
}

void declare_winner(vector<vector<int> >& board) {
	/* Prints out who won, or that there was a tie */
	display_board(board);
	print_winner(board);
}

int main() {
	vector<vector<int> > board;
	board = initialize_game();
	int player = 1;
	while (!take_turn(board, player)) {
		//Swap player's turn
		if (player == 1) {
			player = 2;
		}
		else {
			player = 1;
		}
	}
	declare_winner(board);                   
}