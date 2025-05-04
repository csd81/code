// Program 21_2
// Game example - Game class modified to use a reference to a board
#include<iostream>
#include<vector>
using namespace std;

class gamemove {
protected:
	int player;
public:
	virtual void ask_move(int) = 0;
};

class connect4_move : public gamemove {
private:
	int column;

public:
	void set_move(int p, int c) {
		player = p;
		column = c;
	}
	void ask_move(int nextplayer) {
		player = nextplayer;
		cout << "Player " << nextplayer 
			<< ", which column do you want to place your piece in? ";
		cin >> column;
		column--; // Adjust to make first column be 0
	}
	int c() {
		return column;
	}
	int p() {
		return player;
	}
};

class reversi_move : public gamemove {
private:
	int row;
	int column;

public:
	void ask_move(int nextplayer) {
		player = nextplayer;
		cout << "Player " << nextplayer 
			<< ", which ROW do you want to place your piece in? ";
		cin >> row;
		cout << "Which COLUMN do you want to place your piece in? ";
		cin >> column;
		row--; column--; // Adjust to make the numbers start from 0
	}
	int r() {
		return row;
	}
	int c() {
		return column;
	}
	int p() {
		return player;
	}
};

class gameboard {
public:
	virtual void print_board() = 0;
	virtual int check_winner() = 0;
	virtual void take_turn(gamemove*) = 0;
};

class connect4_board : public gameboard {
private:
	int rows;
	int columns;
	vector<vector<int> > board;

	bool check_vertical_winner(int player) {
		/* Check the board to see if that player has 4 consecutive vertical pieces */
		int i, j;
		for (i = 0; i < columns; i++) {
			// Can loop over all but last 3 rows, comparing 4 at a time
			for (j = 0; j < rows - 3; j++) {
				if ((board[i][j] == player) && (board[i][j + 1] == player)
					&& (board[i][j + 2] == player) && (board[i][j + 3] == player)) {
					return true;
				}
			}
		}
		//Didn't find a winning combination
		return false;
	}

	bool check_horizontal_winner(int player) {
		/* Check the board to see if that player has 4 consecutive horizontal pieces */
		int i, j;
		// Can loop over all but last 3 rows, comparing 4 at a time
		for (i = 0; i < columns - 3; i++) {
			for (j = 0; j < rows; j++) {
				if ((board[i][j] == player) && (board[i + 1][j] == player) 
					&& (board[i + 2][j] == player) && (board[i + 3][j] == player)) {
					return true;
				}
			}
		}
		// Didn't find a winning combination
		return false;
	}

	bool check_increasing_diagonal_winner(int player) {
		/* Check the board to see if that player has 4 consecutive 
		increasing diagonal pieces */
		int i, j;
		//Can loop over all but first 3 rows, comparing 4 at a time
		for (i = 3; i < columns; i++) {
			// Can loop over all but last 3 rows, comparing 4 at a time
			for (j = 0; j < rows - 3; j++) {
				if ((board[i][j] == player) && (board[i - 1][j + 1] == player) 
					&& (board[i - 2][j + 2] == player) && (board[i - 3][j + 3] == player)) {
					return true;
				}
			}
		}
		// Didn't find a winning combination
		return false;
	}

	bool check_decreasing_diagonal_winner(int player) {
		/* Check the board to see if that player has 4 consecutive 
		decreasing diagonal pieces */
		int i, j;
		// Can loop over all but last 3 rows, comparing 4 at a time
		for (i = 0; i < columns - 3; i++) {
			//Can loop over all but last 3 rows, comparing 4 at a time
			for (j = 0; j < rows - 3; j++) {
				if ((board[i][j] == player) && (board[i + 1][j + 1] == player) 
					&& (board[i + 2][j + 2] == player) && (board[i + 3][j + 3] == player)) {
					return true;
				}
			}
		}
		// Didn't find a winning combination
		return false;
	}

	bool check_full_board() {
		/* Check the board to see if the board is full */
		// If all columns are full (first element is not 0), it is a full board.
		int i;
		for (i = 0; i < columns; i++) {
			if (board[i][0] == 0) {
				return false;
			}
		}
		// Never found an empty column, so must be full
		return true;
	}

public:
	connect4_board() {
		rows = 6;
		columns = 7;
		vector<int> col(rows, 0);
		board = vector<vector<int> >(columns, col);
	}
	connect4_board(int r, int c) {
		rows = r;
		columns = c;
		vector<int> col(rows, 0);
		board = vector<vector<int> >(columns, col);
	}

	void print_board() {
		int i, j;
		// Loop through rows first
		for (j = 0; j < rows; j++) {
			// Loop through columns next
			for (i = 0; i < columns; i++) {
				// Display that location
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
	int check_winner() {
		/* Check the board to see if someone has won or if the board is full */
		if (check_vertical_winner(1) ||
			check_horizontal_winner(1) ||
			check_increasing_diagonal_winner(1) ||
			check_decreasing_diagonal_winner(1)) {
			return 1;
		}
		if (check_vertical_winner(2) ||
			check_horizontal_winner(2) ||
			check_increasing_diagonal_winner(2) ||
			check_decreasing_diagonal_winner(2)) {
			return 2;
		}
		// No winner, but if full board, it's a tie
		if (check_full_board()) {
			return 3;
		}
		// No winner, board not full, so game is not over
		return 0;
	}

	// Returns whether a column is full or not
	bool isfullcol(int c) {
		return (board[c][0] != 0);
	}

	void take_turn(connect4_move* m) {
		int last_empty = 0;
		int column = m->c();
		int player = m->p();
		while ((last_empty < rows) && (board[column][last_empty] == 0)) {
			last_empty++;
		}
		last_empty--;
		board[column][last_empty] = player;
	}
	void take_turn(gamemove* m) {
		take_turn((connect4_move*)m);
	}
};

class reversi_board : public gameboard {
private:
	vector<vector<int> > board;

	void mark_up(int r, int c) {
		int i;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = r - 1; (i >= 0) && (board[i][c] == player); i--) {}
		if ((i >= 0) && (board[i][c] == board[r][c])) {
			// We can flip these pieces!
			for (i = r - 1; board[i][c] == player; i--) {
				board[i][c] = board[r][c];
			}
		}
	}
	void mark_down(int r, int c) {
		int i;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = r + 1; (i < 8) && (board[i][c] == player); i++) {}
		if ((i < 8) && (board[i][c] == board[r][c])) {
			// We can flip these pieces!
			for (i = r + 1; board[i][c] == player; i++) {
				board[i][c] = board[r][c];
			}
		}
	}
	void mark_right(int r, int c) {
		int i;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = c + 1; (i < 8) && (board[r][i] == player); i++) {}
		if ((i < 8) && (board[r][i] == board[r][c])) {
			// We can flip these pieces!
			for (i = c + 1; board[r][i] == player; i++) {
				board[r][i] = board[r][c];
			}
		}
	}
	void mark_left(int r, int c) {
		int i;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = c - 1; (i >= 0) && (board[r][i] == player); i--) {}
		if ((i >= 0) && (board[r][i] == board[r][c])) {
			// We can flip these pieces!
			for (i = c - 1; board[r][i] == player; i--) {
				board[r][i] = board[r][c];
			}
		}
	}
	void mark_diagul(int r, int c) {
		int i, j;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = r - 1, j = c - 1; (i >= 0) && (j >= 0) && (board[i][j] == player); 
i--, j--) {}
		if ((i >= 0) && (j >= 0) && (board[i][j] == board[r][c])) {
			// We can flip these pieces!
			for (i = r - 1, j = c - 1; board[i][j] == player; i--, j--) {
				board[i][j] = board[r][c];
			}
		}
	}
	void mark_diagur(int r, int c) {
		int i, j;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = r + 1, j = c - 1; (i < 8) && (j >= 0) && (board[i][j] == player);
			i++, j--) {}
		if ((i < 8) && (j >= 0) && (board[i][j] == board[r][c])) {
			// We can flip these pieces!
			for (i = r + 1, j = c - 1; board[i][j] == player; i++, j--) {
				board[i][j] = board[r][c];
			}
		}
	}
	void mark_diagdr(int r, int c) {
		int i, j;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = r + 1, j = c + 1; (i < 8) && (j < 8) && (board[i][j] == player);
			i++, j++) {}
		if ((i < 8) && (j < 8) && (board[i][j] == board[r][c])) {
			// We can flip these pieces!
			for (i = r + 1, j = c + 1; board[i][j] == player; i++, j++) {
				board[i][j] = board[r][c];
			}
		}
	}
	void mark_diagdl(int r, int c) {
		int i, j;
		int player = 3 - board[r][c];  // Set to other color from one played
		for (i = r - 1, j = c + 1; (i >= 0) && (j < 8) && (board[i][j] == player);
			i--, j++) {}
		if ((i >= 0) && (j < 8) && (board[i][j] == board[r][c])) {
			// We can flip these pieces!
			for (i = r - 1, j = c + 1; board[i][j] == player; i--, j++) {
				board[i][j] = board[r][c];
			}
		}
	}

public:
	reversi_board() {
		vector<int> col(8, 0);
		board = vector<vector<int> >(8, col);
		board[3][3] = 1;
		board[3][4] = 2;
		board[4][3] = 2;
		board[4][4] = 1;
	}
	void print_board() {
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (board[i][j] == 1) {
					cout << "1 ";
				}
				else if (board[i][j] == 2) {
					cout << "2 ";
				}
				else {
					cout << ". ";
				}
			}
			cout << endl;
		}
	}
	int check_winner() {
		int i, j;
		int count1 = 0;
		int count2 = 0;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				if (board[i][j] == 1) {
					count1++;
				}
				else if (board[i][j] == 2) {
					count2++;
				}
			}
		}
		if (count1 + count2 != 64) {
			return 0;  // Game not done!
		}
		if (count1 == count2) {
			return 3;  // Tie
		}
		if (count1 > count2) {
			return 1;
		}
	}
	void take_turn(reversi_move* m) {
		//First mark that square
		board[m->r()][m->c()] = m->p();
		//Now flip any pieces
		mark_up(m->r(), m->c());
		mark_down(m->r(), m->c());
		mark_left(m->r(), m->c());
		mark_right(m->r(), m->c());
		mark_diagul(m->r(), m->c());
		mark_diagur(m->r(), m->c());
		mark_diagdr(m->r(), m->c());
		mark_diagdl(m->r(), m->c());
	}
	void take_turn(gamemove* m) {
		take_turn((reversi_move*)m);
	}
};

class game {
private:
	gameboard& board;  // Notice this is a reference now, not a pointer
	gamemove* turn;
	int playerturn;
	int numturns;

protected:
	// Return 1 if player 1 wins, 2 if player 2 wins, 3 if tie, 0 if game not over
	int check_winner() {
		return board.check_winner(); // We use "." instead of "->" since board is a reference   
	}

	void take_turn() {
		board.print_board();         // We use "." instead of "->" since board is a reference
		turn->ask_move(playerturn);
		board.take_turn(turn);       // We use "." instead of "->" since board is a reference
	}                                    

	void declare_winner() {
		int result = check_winner();
		board.print_board();         // We use "." instead of "->" since board is a reference
		cout << "The game ended after " << numturns << " turns." << endl;
		if (result == 1) {
			cout << "Player 1 wins!  Congratulations!" << endl;
		}
		else if (result == 2) {
			cout << "Player 2 wins!  Congratulations!" << endl;
		}
		else if (result == 3) {
			cout << "The game has ended in a tie." << endl;
		}
		else if (result == 0) {
			cout << "The game ended before it was completed." << endl;
		}
	}

public:
	game(gameboard& b, gamemove& m) : board(b) {
		// We MUST initialize board in the constructor, since it's a reference.
		turn = &m;
	}

	void start_game() {
		numturns = 0;
		playerturn = 1;
		while (check_winner() == 0) {
			take_turn();
			if (playerturn == 1) {
				playerturn = 2;
			}
			else {
				playerturn = 1;
			}
			numturns++;
		}
		declare_winner();
	}
};

int main() {
	cout << "I can play Connect 4 or Reversi.  Which do you want to play?" << endl;
	cout << "Enter 1 for Connect4, anything else for Reversi: ";
	int choice;
	cin >> choice;
	if (choice == 1) {
		connect4_move m;
		connect4_board b;
		game g(b, m);
		g.start_game();
	}
	else {
		reversi_move m;
		reversi_board b;
		game g(b, m);
		g.start_game();
	}
}