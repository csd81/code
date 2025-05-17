// Program 15_1_1
// Connect 4 Program - stage 1
#include <iostream>
#include <vector>
using namespace std;                       

int rows, columns;
void get_board_size(int& rows, int& columns) {
	/* Get size of board from user */
	
	cout << "Enter the number of rows: ";
	cin >> rows;
	cout << "Enter the number of columns: ";
	cin >> columns;
	
}

void initialize_board() {
	/* Initialize the board itself, to all empty squares */
	vector<vector<char>> board(rows, vector<char>(columns, ' ')); // Initialize the board with empty spaces
	cout << "Board size: " << rows << " rows, " << columns << " columns" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	// draw_board(board); // Call a function to draw the board if needed
	// You can implement the draw_board function to display the board in a more user-friendly way
}
 void draw_board(const vector<vector<char>>& board) {
	/* Draw the board */
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
// You can implement this function to display the board in a more user-friendly way


void initialize_game() {
	/* Initialize the entire game */
	get_board_size(rows, columns); // Get the size of the board from the user
	initialize_board(); // Initialize the board with the specified size
	// Initialize other game variables here (e.g., current player, game state)
	// For example:
	// char current_player = 'X'; // Player 1
	// bool game_over = false; // Game state
	// You can add more initialization logic as needed
}

int main() {           
	initialize_game(); // Initialize the game
	// Add game loop and other game logic here
	// For example:
	// while (!game_over) {
	// 	// Get player input, update the board, check for win conditions, etc.
	// }
	return 0;
}