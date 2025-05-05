// Program 15_1_2
// Connect 4 Program - stage 2
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

void initialize_board() {
	/* Initialize the board itself, to all empty squares */
}

void initialize_game() {
	/* Initialize the entire game */
}

int main() {
	int a, b;
	get_board_size(a, b);
	cout << "Returned " << a << " columns and " << b << " rows." << endl;           
}