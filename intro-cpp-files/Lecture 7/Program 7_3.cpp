// Program 7_3
// Setting all elements of an array
#include <iostream>
using namespace std;

int main() {
	int player_money[4]; // Declare an array of integers, size 4, i.e. 0-3
	int i; // Declare a loop variable outside the loop
	for (i = 0; i < 4; i++) { // Loop through the array
		player_money[i] = 200; // Set each element to 200
	}
	// Show output
	for (i = 0; i < 4; i++) {
		cout << player_money[i] << endl; // Print each element
	}                      // Prints 200 200 200 200
}